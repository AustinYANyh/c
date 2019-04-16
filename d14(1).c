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

int main()
{
	char str[] = "ABCD";
	int size = strlen(str) - 1;
	Blood(str, size, 3);
	printf("%s", str);
   system("pause");
   return 0;
}