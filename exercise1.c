#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

// 	char str[] = "Hello";
// 	sizeof(str);
// 	strlen(str);
// 	printf("%d %d ", sizeof(str), strlen(str));


//调整数组使奇数全部都位于偶数前面。

//题目：

// 输入一个整数数组，实现一个函数，
// 来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
// 所有偶数位于数组的后半部分

void paixu(int arr[],int size)
{
	for (int i = 0; i < size; ++i)
	{

			if (arr[i] % 2 == 0)
			{
				int tmp = { 0 };
				tmp = arr[i];
				arr[i] = arr[size - 1];
				arr[size - 1] = tmp;
				--size;
				--i;
			}
			else
			{
				continue;
			}
	}
}

// 	int arr[10] = {1,4,6,8,5,9,2,3,7,13};
// 	paixu(arr, 10);
// 	for (int i = 0; i < 10; ++i)
// 	{
// 		printf("%d ", arr[i]);
// 	}


// 杨氏矩阵
// 有一个二维数组.
// 数组的每行从左到右是递增的，每列从上到下是递增的.
// 在这样的数组中查找一个数字是否存在。
// 时间复杂度小于O(N);

#define maxhang 5
#define maxlie  5
int to_find(int arr[maxhang][maxlie], int hang, int lie, int n)
{
	//先跟右上角的元素比较(0行maxlie列)
	hang = 0;
	lie = maxlie - 1;
	while (hang<maxhang||lie>=0)
	{
			if (n > arr[hang][lie])
			{
				++hang;
			}
			else if (n < arr[hang][lie])
			{
				--lie;
			}
			else 
			{
				return 1;
			}
	}
	return 0;
}

int main()
{
	int arr[5][5] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 3, 6, 9, 12, 15, 4, 8, 12, 16, 20,  5, 10, 15,20,25 };
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j <5; ++j)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	int a = to_find(arr, 5, 5, 10);
	if (a == 1)
	{
		printf("找到了!\n");
	}
	else
	{
		printf("没找到!\n");
	}
	system("pause");
   return 0;
}