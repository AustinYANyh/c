#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//ʵ��һ�����������������ַ����е�k���ַ�
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

void Blood(char str[],int size,int n)
{
	char tmp = { 0 };
	for (int i = 0; i < n; ++i)
	{
		tmp = str[0];//����Ҫ�������ַ�������,�´�ѭ���õڶ����ʼ���ַ�
		for (int j = 0; j < size; ++j)//��һλ����ǰһλ
		{
			str[j] = str[j + 1];
		}
		str[size] = tmp;//�Ѹ���ת���ַ�����ĩβ
	}
}
//�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ���
//���磺����s1 = AABCD��s2 = BCDAA������1������s1 = abcd��s2 = ACBD������0.
//
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC

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
			Blood(str1, size, 1);//ÿ����תһλȥ�Ƚ�
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
		printf("str2����str1��ת�õ���");
	}
	else if (a == 0)
	{
		printf("str2������str1��ת�õ���");
	}
   system("pause");
   return 0;
}