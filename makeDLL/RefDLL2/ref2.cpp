#undef UNICODE
#include <windows.h>
#include <iostream>
using namespace std;
typedef int (*AddFunc)(int a, int b);
int main(int argc, char *argv[])
{
      HMODULE hDll = LoadLibrary("secondDLL.dll");//��������ǰ��L
      if (hDll != NULL)
      {
            AddFunc add = (AddFunc)GetProcAddress(hDll, "Add");//Add�������֮������ô�򵥣�����Ϊд��extern ��C����Ե�ʡ�
            if (add != NULL)
            {
                  cout<<add(2, 5)<<endl;
            }
            FreeLibrary(hDll);
      }
	  system("pause");
	  return 0;
}