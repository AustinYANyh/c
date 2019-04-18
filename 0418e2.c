#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 实现一个函数，可以左旋字符串中的k个字符
// ABCD左旋一个字符得到BCDA ABCD左旋两个字符得到CDAB

//先将要左旋的字符存起来,随后用strcat拼接

void Blodd(char str[],int n)
{
	int size = strlen(str);
	char tmp[1024] = { 0 };
	int i = 0;
	for (; i < n; ++i) 
	{
		tmp[i]= str[i];              //问题是怎么把前两位拿掉
	}
	//现在的字符串还是ABCD
	for (i = n; i < size; ++i)
	{
		str[i - n]=str[i];
	}
		strcat(str, tmp);
}


int isBlood(char str1[],char str2[])
{
	int size = strlen(str1) ;
	strncat(str1, str1,size);
	strstr(str1, str2);
	if (strstr(str1, str2) != NULL)
	{
		return 1;
	}
	return 0;
}

//int main()
//{
//	char str1[1024] = "ABCD";
//	char str2[1024] = "CDAB";
		////printf("%s", str);
		//int a=isBlood(str1, str2);
		//if (a == 1)
		//{
		//	printf("找到了");
		//}
		//else
		//{
		//	printf("没找到");
		//}
//	Blodd(str1, 2);
//	printf("%s", str1);
//	 system("pause");
//	return 0;
//}
// 练习动态内存开辟
//malloc
//calloc
//realloc
//free
//函数

int main()
{
	char* p = (char*)malloc(100 * sizeof(char));
	if (p == NULL)
	{
		exit(EXIT_FAILURE);
	}
	free(p);

	char arr[] = { 0 };
	char* p2 = (char*)calloc(sizeof(arr) / sizeof(arr[0]), sizeof(arr));
	if (p2 == NULL)
	{
		exit(EXIT_FAILURE);
	}
	/*free(p2);*/		//释放之后,p2变为野指针

	p2 = (char*)realloc(p2, 100 * sizeof(arr));
	free(p2);			//野指针如果再次释放会断言失败

	system("pause");
	return 0;
}
