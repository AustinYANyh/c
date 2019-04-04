#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//编写一个函数实现n^k,使用递归
//跳出条件:只有一个n的时候
//int nk(int n)
//{
//	int k=0;
//	if (k==1)
//	{
//		return n;
//	}
//	return n*nk(n - 1);
//}
//int main()
//{
//	int num = 0;
//	int k = 2;
//	int a=nk(num);
//	printf("%d\n", a);
//int jiaohuan(int* x,int* y)
//{
//	int tmp;
//	tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	scanf("%d %d", &num1,&num2);
//	jiaohuan(&num1, &num2);
//	printf("%d %d\n",num1, num2);

void init(int arr[],int chushihua[],int n)
{
	int i;
	for (i = 0; i < n; i++)//数组遍历
	{
		arr[i] = chushihua[i];
	}
}

void empty(int arr[],int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		arr[i] = 0;
	}
}

void reverse(int arr[],int n)
{
	int tmp;
	int i, j;
	//i是数组从低到高遍历,j是从高到低遍历,两者数据交换
	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}

void dayin(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 9, 5, 2, 7 };
	int dasini[] = { 1, 2, 3, 4 };
	init(arr, dasini,4);
	dayin(arr, 4);
	reverse(arr, 4);
	dayin(arr, 4);
	empty(arr, 4);
	dayin(arr, 4);
system("pause");
return 0;
}