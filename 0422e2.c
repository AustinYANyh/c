#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>

//int main()
//{
//	int arr[10] = { 1, 6, 7, 9, 2, 7, 9, 1, 5, 6 };
//	int sum = 0;
//	for (int i = 0; i < 10; ++i)
//	{
//		sum ^= arr[i];
//	}
//	int pos = 0;
//	int num1 = 0;
//	int num2 = 0;
//	for (int i = 0; i < 32; ++i)
//	{
//		if (sum & 1 << i)
//		{
//			pos = i;
//			break;
//		}
//	}
//	for (int i = 0; i < 10; ++i)
//	{
//		if (arr[i] & 1 << pos)
//		{
//			num1 ^= arr[i];
//		}
//		else
//		{
//			num2 ^= arr[i];
//		}
//	}
//	printf("%d %d", num1, num2);
//	system("pause");
//	return 0;
//}

//#define and &&
//
//char * Strstr(const char* str1,const char* str2)
//{
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	if (*str2 == '\0')
//	{
//		return NULL;
//	}
//	char *chazhao = (char*)str1;
//	char *zichuan = (char*)str2;
//	while (*chazhao != '\0')
//	{
//		char *panduan = chazhao;
//		while (*zichuan == *panduan and *zichuan != '\0' and *panduan != '\0')
//		{
//			panduan++;
//			zichuan++;
//		}
//		if (*zichuan == '\0')
//		{
//			return chazhao;
//		}
//	++chazhao;
//	}
//}
//
//int main()
//{
//		char str1[1024] = "wuyiqunawan";
//		char str2[1024] = "quna";
//		Strstr(str1, str2);
//		printf("%p ", str1);
//		printf("%p ", Strstr(str1, str2));
//	system("pause");
//	return 0;
//}


//数组中的奇数放在后面,偶数放在前面

void Sort(int arr[],int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] % 2 != 0)
		{
			int tmp = arr[i];
			arr[i] = arr[size - 1];
			arr[size - 1] = tmp;
			size--;
			i--;
		}
		else
		{
			continue;
		}
	}
}

void sort(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (arr[j-1] >arr[j]) //注意边界问题
			{
				int tmp;
				tmp = arr[j];
				arr[j ] = arr[j-1];
				arr[j - 1] = tmp;
			}
		}
	}
}

int main()
{
	int arr[10] = { 6, 8, 1, 3, 4, 7, 2, 9, 15, 17 };
	Sort(arr, 10);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	sort(arr, 10);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}