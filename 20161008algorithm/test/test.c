#include<stdio.h>

void insertion_sort(int array[], int first, int last){
	int i, j, temp;
	for (i = first + 1; i <= last; i++){
		temp = array[i]; //�c������Ĕ���һ���^�����temp�r��ԓ��������
		for(j = i - 1; j >= first && array[j] > temp; j--) //��first=0��jѭ����-1ʱ������[[��·��ֵ]](http://zh.wikipedia.org/wiki/%E7%9F%AD%E8%B7%AF%E6%B1%82%E5%80%BC)����������array[-1]
			array[j + 1] = array[j];
		array[j+1] = temp; //���������ŵ���ȷ��λ��
	}
}

int main()
{
       int i;
       int arr[6]={5,3,7,2,6,9};
       insertion_sort(arr,0,5);
       for(i = 0; i < 6; i++)
           printf("%d\n",arr[i]);
       return 0;
}