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

int main()
{
	char str[] = "ABCD";
	int size = strlen(str) - 1;
	Blood(str, size, 3);
	printf("%s", str);
   system("pause");
   return 0;
}