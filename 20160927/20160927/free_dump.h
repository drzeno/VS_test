#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>    
#include <assert.h>    
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/timeb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>

#define CONST_BUFROWCNT    100 /*ÿ����չ��*/
#define CONST_PACKROWSIZE  sizeof(THsPackRow)
#define CONST_PACKCOLSIZE sizeof(THsPackColData)
#define CONST_DATASIZELEN 2 
#define CONST_PACKSPLIT  1
#define CONST_MAXSTRINGLEN      (254 * 254)  /* Ŀǰÿ�ֶ�ֵ����󳤶�������254 * 254�ֽڣ��������Զ��ص� 16581374*/
#define MAX_ITEMNAME_LEN 100
#define CONST_BUFFIELDCNT  30 /*ÿ����չ�ֶ���*/
#define  gIPackFieldSize sizeof(THsPackField) 
typedef unsigned char byte;


typedef struct HsPackField
{
  char sFieldName[100]; 
  char *sLinkName;
  int iLen; /*�ֶ�������*/
  int iFldIdx; /*��ǰ�ֶ�����λ��*/
}THsPackField;


typedef struct HsPackColData
{
  char *sData;
  byte bCanFree;
  int iLen;
}THsPackColData;

typedef struct HsPackRow
{
  THsPackColData *arrCols;
  int iColCnt;  /*��ǰ����*/
  int iBufColCnt; /*����������*/
}THsPackRow;



typedef struct HsPack
{
  char *sData; /*������*/
  int iLen;
  int iBufLen;
  THsPackField *arrFields; /*�����ֶ��б�*/
  int iFieldCount;
  int iBufFieldCount;
  THsPackRow *arrRows;  /*����������*/
  int iRowCount;  /*��ǰ����*/
  int iBufRowCount; /*��������*/
  int iRecNo; /*��ǰλ��,��0��ʼ*/
  byte bEof;
  int iPackVer; /*��ǰ���ݰ�����*/

  char sValue[30];
  char *pOptData;
  byte bUseOldPack; /*��ǰ�Ƿ�����˾ɰ汾�İ����´����´��ʱ�������ֵΪ�棬����ֻ��һ��ʱ�����Ǵ���ɾɰ�İ�*/
}THsPack;



int  hsParseData(THsPack *hsPack, const char *sData);
int  hsPackClear(THsPack *hsPack);
int hsFreeOneRow(THsPackRow *arrRows, const int bNeedFree);
int StrToInt(const char *sVal, const int iMaxLen);
int hsInternalExtRows(THsPack *hsPack, int iNeedNewRowCount);
int  hsAppendRow(THsPack *hsPack);
int StrToByte(const char *sVal) ;
int  hsAddFieldEx(THsPack *hsPack,  const char *sFieldName, const int bNeedChkName, const int bLinkName);
int hsInternalAddString(THsPackColData *pCol, const char *Value, const int bIsLink, const int iDataLen);
char* ParseOldPackage(THsPack *hsPack, char *S  );
int  hsAddFieldEx(THsPack *hsPack,  const char *sFieldName, const int bNeedChkName, const int bLinkName);
int hsInternalExtFields(THsPack *hsPack);
int  hsGetFieldIdx(THsPack *hsPack,  const char *sFieldName);
char * hsInlGetFieldName(THsPackField * pPackField);
int  hsAddField(THsPack *hsPack, const char *sFieldName);
int  hsAddStringEx(THsPack *hsPack, int iFldIdx,const char *Value, const int iValLen);
int hsInternalAddString(THsPackColData *pCol, const char *Value, const int bIsLink, const int iDataLen);
int hsInternalCheckCol(THsPack *hsPack, int iFldIdx );
int  hsPackEof(THsPack *hsPack);