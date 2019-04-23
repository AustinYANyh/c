#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//打印n*n的乘法表

void Mulexcel(int n)
{
	int res = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			res = i*j;
			printf("%d*%d=%d ", i, j, res);
		}
		printf("\n");
	}
}

//1.在屏幕上输出以下图案： 
//	     *
//      ***
//	   *****
//    *******
//   *********
//  ***********
// *************
//  ***********
//   *********
//    *******
//     *****
//      ***
//       *

void Print(int n)
{
	int a = 0;
	int i = 0;
	int j = 0;
	for (i = 1; i <= n; ++i)
	{
		for (a = 1; a <= n - i;++a)
		{
			putchar(' ');
		}
		for (j = 1; j <= 2 * i - 1; ++j)
		{
			putchar('*');
		}
		printf("\n");
	}
	for (i = n-1; i >=1; --i)
	{
		for (a = 1; a <=n - i; ++a)
		{
			putchar(' ');
		}
		for (j = 1; j <= 2 * i - 1; ++j)
		{
			putchar('*');
		}
		printf("\n");
	}
}

//求出0～999之间的所有“水仙花数”并输出。 
//“水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身
//如；153＝1＋5＋3 ? ，则153是一个“水仙花数”
// 153 = 1 ^ 3 + 5 ^ 3 + 3 ^ 3
// 370 = 3 ^ 3 + 7 ^ 3 + 0 ^ 3
// 371 = 3 ^ 3 + 7 ^ 3 + 1 ^ 3
// 407 = 4 ^ 3 + 0 ^ 3 + 7 ^ 3

int Search()
{
	int n = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	for (n = 100; n < 1000; n++)
	{
		a = n % 10;
		b = n / 10 % 10;
		c = n / 100;
		if (n == a*a*a + b*b*b + c*c*c)
		{
			printf("%d\n", n);
		}
	}
}

int main()
{
	Search();
	system("pause");
}

