#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//实现一个函数，可以左旋字符串中的k个字符
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

void Blood(char str[],int size,int n)
{
	char tmp = { 0 };
	for (int i = 0; i < n; ++i)
	{
		tmp = str[0];//把需要左旋的字符存起来,下次循环拿第二个最开始的字符
		for (int j = 0; j < size; ++j)//后一位补到前一位
		{
			str[j] = str[j + 1];
		}
		str[size] = tmp;//把刚旋转的字符放在末尾
	}
}
//判断一个字符串是否为另外一个字符串旋转之后的字符串
//例如：给定s1 = AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC

int isBlood(char str1[],char str2[],int size, int n)
{
	if (strlen(str1) != strlen(str2))
	{
		return 0;

	}
	if (strcmp(str1, str2) == 0)
	{
		return 1;
	}
	else
	{
		for (n = 1; n < size; ++n)
		{
			Blood(str1, size, 1);//每次旋转一位去比较
			if (strcmp(str1, str2) == 0)
			{
				return 1;
			}
		}
		return 0;
	}
}

int main()
{
	char str1[] = "AABCDA";
	char str2[] = "BCDAAA";
	int size = strlen(str1) - 1;
	int n = 0;
	int a=isBlood(str1, str2, size, n);
	if (a == 1)
	{
		printf("str2是由str1旋转得到的");
	}
	else if (a == 0)
	{
		printf("str2不是由str1旋转得到的");
	}
   system("pause");
   return 0;
}