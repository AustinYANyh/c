#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<string.h>


//unsigned int reverse(unsigned int data)
//{
//	int tmp1, tmp2 = 0;
//	int i, j;
//	for (i = 0,j = 31; i < j; ++i,--j)
//	{
//		tmp1 = data;
//		data[j] = data;
//	}
//}
unsigned int reverse1(unsigned int x)
{
	int i;
	int tmp, sum = 0;
	for (i = 0; i < 32; x /= 2, ++i)
	{
		tmp = x % 2;
		sum = sum * 2 + tmp;
	}
	return sum;
}//3.编程实现： 
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）

void  fanxiangpailie(char * string)
{
	char tmp;
	int mowei = strlen(string) - 1;//末尾元素下标是长度减一
	//首先确定跳出条件,string[0]=="\0"
	if (string[0] == '\0')//判断是不是\0
	{
		return;
	}
	tmp = string[0];//把首元素存起来
	string[0] = string[mowei];//把末尾的元素放在第一位
	string[mowei] = '\0';//给末尾补上\0,确保每次都找到尾部
	fanxiangpailie(string + 1);//光标下移一位
	string[mowei] = tmp;//把存好的开头,后入先出的原则归位
}


int Strlen(char * str)
{
	int i = 0;
	for (; str[i]; ++i);
	return i;
}


void reverse(char * str, int start, int end)
{
	char tmp;
	int i, j;
	for (i = start, j = end - 1; i < j; i++, j--)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}

char * fanxiangpailie2(char * str)
{
	int i = 0;
	int start=0;
	for (; str[i]; ++i)//遍历
	{
		if (str[i] == ' ')
		{
			reverse(str, start, i);//将第一个单词逆转
			start = i + 1;//开头变为刚才的末尾+1
		}
	}
	reverse(str, start, i);//遇到\0时，start是最后一个单词的词首
	reverse(str, 0, i);//整体逆序
	return str;
}


int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int c = (a + b) >> 1;
	printf("%d\n", c);
	system("pause");
	return 0;
}