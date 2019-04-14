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
	for (int i = 0; i < size; ++i)//这个循环用来遍历
	{
		for (int j = 0; j<size-1-i; ++j)//用来比较相邻元素的大小,i之前的已经排好,只需排后面的元素
		{
			if (arr[j] >arr[j + 1]) 
			{
				swap(&arr[j + 1], &arr[j]);
			}
		}
	}
}

void find(int arr[], int size,int *num1,int * num2)//比较相邻的排好序的两个元素,如果不同就是只出现一次
{
	int tmp = 0;
	for (int i = 0; i < size; i += 2)//一次找两个元素比较
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
			tmp++; //把第一次找出的数字赋值给num1,第二次找到的赋值给num2
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