#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ʵ��һ�����������������ַ����е�k���ַ�
// ABCD����һ���ַ��õ�BCDA ABCD���������ַ��õ�CDAB

//�Ƚ�Ҫ�������ַ�������,�����strcatƴ��

void Blodd(char str[], int n)
{
	int size = strlen(str);
	char tmp[1024] = { 0 };
	int i = 0;
	n %= size;  //��������ַ������ַ�������ȡ��������
	for (; i < size - n; ++i)
	{
		tmp[i] = str[i + n];  //�ò����������ַ�,��������������ʣ�µ�
	}
	for (i; i < size; ++i)
	{
		tmp[i] = str[(i + n) - size]; // ���ڰѿ�ͷ��,Ҳ�����������ַ��ó�����ֵ
	}
	strcpy(str, tmp);
}


int isBlood(char str1[], char str2[])
{
	int size = strlen(str1);
	strncat(str1, str1, size);
	strstr(str1, str2);
	if (strstr(str1, str2) != NULL)
	{
		return 1;
	}
	return 0;
}

//char str1[] = "ABCDE";
///*char str2[] = "CEDAB";*/
//Blodd(str1, 3);
//printf("%s", str1);

int main()
{
	int arr[10] = { 8, 12, 10, 11, 9, 11, 9, 2, 2, 8 };
	int i, sum=0;
	//for (i = 0; i < 10; ++i)  //���ҵ�������Ե�����д��
	//{
	//	sum ^= arr[i];
	//}
	//printf("%d ", sum);
	//printf("%d \n", 10 ^ 12);
	int a;// ������¼��һλ��1
	int num1 = 0;
	int num2 = 0; 
	for (i = 0; i < 32; ++i)
	{
		if (sum & 1 << i)    //��sum������ÿһλ ���Ƿ�Ϊ1,�����1,��¼λ��
		{
			a = i;
			break;
		}
	}
	for (i = 0; i < 10; ++i)
	{
		if (arr[i] & 1 << a) //�������в�����һλΪ1������Ϊһ��,��Ϊ1��Ϊһ��
		{
			num1 ^= arr[i];//���������ֱ����Ϳ����ҳ��������ֵ������ֵ�һ��
		}
		else
		{
			num2 ^= arr[i];
		}
	}
	printf("%d %d ", num1, num2);
	system("pause");
	return 0;
}

