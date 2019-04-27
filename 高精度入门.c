#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Reverse(char * str)
{
	char tmp;
	int len = strlen(str);
	for (int i = 0, j = len - 1; i <= j; ++i, --j)
	{
		tmp = str[i];
		str[i] = str[j] - '0';
		str[j] = tmp - '0';
	}
	return len;
}

int add(char * str1, char * str2, int len1, int len2, char * sum)
{
	int maxlen = len1 > len2 ? len1 : len2;
	//int maxlen = MAX(len1, len2);
	int i = 0;
	int tmp = 0;
	for (; i < maxlen; ++i)
	{
		tmp = str1[i] + str2[i] + sum[i];
		sum[i] = tmp % 10;
		sum[i + 1] = tmp / 10;
	}
	return maxlen + sum[i];
}


int mul(char *str1, char *str2, int len1,int len2, char *sum)
{
	int i, j, tmp;
	for (i = 0; i < len1; i++)
	{
		for (j = 0; j < len2; j++)
		{
			tmp = str1[i] * str2[j] + sum[i + j];
			sum[i + j] = tmp % 10;
			sum[i + j + 1] += tmp / 10;
		}
	}
	return len1 + len2 - !sum[i + j - 1];
}

void printNumber(char * num, int len)
{
	int i;
	for (i = len - 1; i >= 0; i--)
	{
		putchar(num[i] + '0');
	}
}

int main()
{
	char a[1024] = { 0 };
	char b[1024] = { 0 };
	char sum[1024] = { 0 };
	scanf("%s%s", a, b);
	int c = Reverse(a);
	int d = Reverse(b);
	int lens = mul(a, b, c, d, sum);
	printNumber(sum, lens);
	system("pause");
	return 0;
}