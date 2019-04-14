#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//4.实现strchr




//char * Strstr(const char* str1, const char* str2)
//{
//	assert( str1!=NULL);
//	assert( str2!=NULL);
//	if (*str2 == '\0')
//	{
//		return NULL;
//	}
//	char *chazhao = (char *)str1;
//	while (*chazhao != '\0')//被查字符串遇到\0说明找完了
//	{
//		char *panduan = chazhao;
//		char *zichuan = (char *)str2;
//		while (*panduan == *zichuan&& *panduan != '\0'&& *zichuan != '\0')
//		{
//			++panduan;//第一位相同的话,两者同时后移,继续比较
//			++zichuan;
//		}
//		if (*zichuan == '\0')//如果找到,返回的是指向第一个被包含字符的位置
//		{
//			return chazhao;
//		}
//		++chazhao;//并不完全相同,被查字符串后移继续查找
//	}
//}

//5.实现strcmp
//int Strcmp(const char* str1, const char* str2)
//{
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	int i = 0;
//	int len = 0;
//	int len1 = strlen(str1);
//	int len2 = strlen(str2);
//	if (len1 >= len2)
//	{
//		len = len1;
//	}
//	else
//	{
//		len = len2;
//	}
//	for ( i = 0; i<len;  ++i)
//	{
//		if (str1[i]<str2[i])//a 97  b 98
//		{
//			return 1;// 数值上a比b小,但是字典序 a 比 b 大 返回值大于0
//		}
//		else if (str1[i]>str2[i])// b 98  a  97 
//		{
//			return -1; //数值上b比a大, 但是字典序 b 比 a 小 返回值小于0
//		}
//		else if (str1[i] == str2[i] && str1[i] != '\0')
//		{
//			continue;
//		}
//		else if (str1[i] == '\0'&&str2[i] == '\0')
//		{
//			return 0;
//		}
//		else break;
//	}
//	return 0;
//}


//int main(){
//	char a[] = "abbbbbbb";
//	char b[] = "abbbbbbb";
//	int ret = Strcmp(a, b);
//	if (ret > 0)
//	{
//		printf("a>b\n");
//	}
//	else if (ret < 0)
//	{
//		printf("a<b\n");
//	}
//	else if (ret == 0)
//	{
//		printf("a=b\n");
//	}
//	system("pause");
//}


//6.实现memcpy

//void * Memcpy(void * dest, const void * src, size_t num)//size_t num 是字节
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* p1 = (char*)dest;
//	const char* p2 = (const char*)src;
//	for (size_t i = 0; i < num; ++i)
//	{
//		p1[i] = p2[i];
//	}
//	return dest;
//}

//char arr1[4] = { 0 };
//char arr2[5] = { 1, 5, 6, 7, 8 };
//Memcpy(arr1, arr2, 16);
//for (int i = 0; i < 4; ++i)
//{
//	printf("%d ", arr1[i]);
//}

//7.实现memmove
//void * Memmove(void * dest, const void * src, size_t num)//size_t num 是字节
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* p1 = (char*)dest;
//	const char* p2 = (const char*)src;
//	if (dest >= src&&p1 < p2 + num)      
//	{
//		for (size_t i = num-1; i > 0; --i)
//		{
//			p1[i] = p2[i];
//		}
//		return dest;
//	}
//}

char* Strchr(const char *str, char c)
{
	if (str == NULL)
	{
		return NULL;
	}

	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] == (char*)c)
		{
			return &str[i];
		}
	}
	return NULL;
}


int main()
{
	char str[] = "wo de luzihan shi cunzhu";
	char l = 'l';
	Strchr(str, l);
	printf("%p\n", str);
	printf("%p\n", Strchr(str, l));
	system("pause");
	return 0;
}