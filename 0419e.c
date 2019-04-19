#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

// 写代码可以在整型有序数组中查找想要的数字，
// 找到了返回下标，找不到返回 - 1.（折半查找）

int find(int arr[], int n)
{
	int left = 0;
	/*int size = sizeof(arr) / sizeof(arr[0]);*/
	int right = 4;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < n)
		{
			left = mid + 1;
		}
		else if (arr[mid]>n)
		{
			right = mid - 1;
		}
		else break;
	}
	if (left > right)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
//将数组A中的内容和数组B中的内容进行交换。（数组一样大）


int main()
{
	int arr1[] = { 1, 3, 5, 7, 9 };
	int arr2[] = { 2, 4, 6, 8, 10 };
	for (int i = 0; i < 5; ++i)
	{
		int tmp;
		tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;

	}
	for (int i = 0; i < 5; ++i)
	{
		printf("%d ", arr1[i]);
		
	}
	printf("\n");
	for (int i = 0; i < 5; ++i)
	{
		printf("%d ", arr2[i]);

	}
	system("pause");
	return 0;
}