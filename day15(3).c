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
	for (int i = 0; i < size; ++i)//���ѭ����������
	{
		for (int j = 0; j<size-1-i; ++j)//�����Ƚ�����Ԫ�صĴ�С,i֮ǰ���Ѿ��ź�,ֻ���ź����Ԫ��
		{
			if (arr[j] >arr[j + 1]) 
			{
				swap(&arr[j + 1], &arr[j]);
			}
		}
	}
}

void find(int arr[], int size,int *num1,int * num2)//�Ƚ����ڵ��ź��������Ԫ��,�����ͬ����ֻ����һ��
{
	int tmp = 0;
	for (int i = 0; i < size; i += 2)//һ��������Ԫ�رȽ�
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
			tmp++; //�ѵ�һ���ҳ������ָ�ֵ��num1,�ڶ����ҵ��ĸ�ֵ��num2
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


//3.ģ��ʵ��strcpy
//4.ģ��ʵ��strcat

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

//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
//��20Ԫ�����Զ�����ˮ��
//���ʵ�֡�
int num(int n)
{
	if (n != 0)//����0�ǺȲ�����ˮ��
	{
		if (n != 1)//����Ǯ����1Ԫ�������
		{
			if (n % 2 == 0)
			{
				return n + num(n / 2);//�����2��ƿ�ӵ���1ԪǮ
			}
			else
			{
				return (n-1) + num((n / 2) + 1);//
			}
		}
		else
		{
			return 1;//ֻ��1ԪǮ��ֻ�ܺ�һƿ
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