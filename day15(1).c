#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>


void swap(int* x, int* y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void sort(int arr[], int size)
{
	for (int i = 0; i < size; ++i)//���ѭ����������
	{
		for (int j = 0; j<size-1-i; ++j)//�����Ƚ�����Ԫ�صĴ�С,i֮ǰ���Ѿ��ź�,ֻ���ź����Ԫ��
		{
			if (arr[j] >arr[j + 1]) 
			{
				swap(&arr[j + 1], &arr[j]);
			}
		}
	}
}

void find(int arr[], int size,int *num1,int * num2)//�Ƚ����ڵ��ź��������Ԫ��,�����ͬ����ֻ����һ��
{
	int tmp = 0;
	for (int i = 0; i < size; i += 2)//һ��������Ԫ�رȽ�
	{
		if (arr[i] == arr[i + 1])
		{
			continue;
		}
		else
		{
			if (tmp==0)
			{
				*num1 = arr[i];
				++i;
			}
			else if (tmp==1)
			{
				*num2 = arr[i];
				++i;
			}
			tmp++; //�ѵ�һ���ҳ������ָ�ֵ��num1,�ڶ����ҵ��ĸ�ֵ��num2
		}
	}
}


int main()
{
	int arr[10] = { 1, 3, 9, 3, 2, 5, 8, 8, 9, 1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	sort(arr, 10);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	int num1, num2 = 0;
	find(arr, 10, &num1, &num2);
	printf("  %d %d", num1, num2);
   system("pause");
   return 0;
}