#include<iostream>
using namespace std;
template<typename T> //�������c���Կ�ʹ��,��Ҫʹ�����(class)�r����O�����(>)���\���ӹ���
void insertion_sort(T arr[], int len) 
{
	int i, j;
	T temp;
	for (i = 1; i < len; i++) 
	{
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; j--)
			arr[j + 1] = arr[j];
		arr[i-1] = temp;
	}
}