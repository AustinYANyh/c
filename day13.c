#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

//.调整数组使奇数全部都位于偶数前面。 

//题目：

//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分


void paixu(int arr[], int left , int right )
{
	for (int left= 0; left< right; ++left)
	{
		if (arr[left] % 2 == 0)
		{
			int tmp;
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;//把找到的这个偶数放到末尾
				right--;//末尾的偶数不需要管,数组长度减去1
				left--;//首位的原末尾还没判断是否为偶数
		}
		else continue;
	}

}
//int arr[] = { 0, 1, 3, 2, 8, 4, 9, 6 };
//int size = sizeof(arr) / sizeof(arr[0]);
//paixu(arr,0,7);
//for (int i = 0; i < size; ++i)
//{
//	printf("%d ", arr[i]);
//}


//1 3 5
//2 8 10 
//9 15 28

void paixu

int main11()
{
	int arr[3][3] = { 1,3,5,2,8,10,9,15,28 };
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

   system("pause");
   return 0;
}
