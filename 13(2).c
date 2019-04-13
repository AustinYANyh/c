#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>


#define Hang 3
#define Lie  3

int find(int arr[Hang][Lie],int hang,int lie, int n)
{
	if ((n<arr[0][0]) || (n>arr[hang - 1][lie - 1]))	//合法化校验
	return 0;	//杨氏矩阵第一个数最小最后一个数最大	
	int a = 0;	int b = lie-1;
	while ((a < hang) && (b >= 0))
	{
		if (n>arr[a][b])		//待查找数字比这一行第三列大,往下一行查找
		{
			a++;			
		}
		else if (n < arr[a][b])	//待查找数字比这一行第三列小,往前两列查找	
		{	
			b--;
		}
		else	return 1;		//表明找到
	}
	return 0;
}


int main()	
{
		int arr[3][3] = { 1, 3, 5, 2, 8, 10, 9, 15, 28 };
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		int x = 0;
		x = find(arr,3,3, 28);
		if (x == 1)
		{
			printf("找到了!\n");
		}
		else if (x == 0)
			printf("没找到!\n");
		system("pause");
		return 0;
}
