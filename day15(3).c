#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<assert.h>


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

//int arr[10] = { 1, 3, 9, 3, 2, 5, 8, 8, 9, 1 };
//int size = sizeof(arr) / sizeof(arr[0]);
//sort(arr, 10);
//for (int i = 0; i < size; ++i)
//{
//	printf("%d ", arr[i]);
//}
//int num1, num2 = 0;
//find(arr, 10, &num1, &num2);
//printf("  %d %d", num1, num2);


//3.模拟实现strcpy
//4.模拟实现strcat

char * Strcpy(char * dest, const char * src)
{
	assert(dest != NULL);
	assert(src != NULL);
	int i = 0;
	int len = strlen(src) - 1;
	for (; i <=len; ++i)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return dest;
}

//char str1[] = "abcdefghijklm";
//char str2[] = "luzihanbaobao";
//Strcpy(str1, str2);
//printf("%s", str1);

char * Strcat(char * dest, const char * src)
{
	assert(dest != NULL);
	assert(src != NULL);
	int i = 0;
	for (i = 0; dest[i]!= '\0';++i)
	{
		;
	}
	for (int j=0; src[j]!='\0'; ++i,++j)
	{
		dest[i] = src[j];
	}
	dest[i] = '\0';
	return dest;
}

//char str1[1024] = "wozuixihuan";
//char str2[1024] = "luzihanbaobao";
//Strcat(str1, str2);
//printf("%s", str1);

//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以多少汽水。
//编程实现。
int num(int n)
{
	if (n != 0)//等于0是喝不了汽水的
	{
		if (n != 1)//给的钱大于1元的情况下
		{
			if (n % 2 == 0)
			{
				return n + num(n / 2);//喝完的2个瓶子等于1元钱
			}
			else
			{
				return (n-1) + num((n / 2) + 1);//
			}
		}
		else
		{
			return 1;//只有1元钱就只能喝一瓶
		}
	}
}

int main()
{
	int num1 = 0;
	scanf("%d", &num1);
	num(num1);
	printf("%d", num(num1));
   system("pause");
   return 0;
}