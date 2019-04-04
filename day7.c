#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void swap(int arr1[], int arr2[], int n)
{
	int tmp;
	for (int i = 0; i < n; ++i)
	{
		tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
}
void dayin(int arr[], int n)
{
	int i = 0;
	for (i; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//int main()
//{
	//int arr1[] = { 9, 5, 2, 7, 6 };
	//int arr2[] = { 1, 2, 3, 4, 5, 66 };
	//swap(arr1, arr2,6);
	//dayin(arr1, 6);
//编写程序数一下 1到 100 的所有整数中出现多少次数字9
int shujiu(int y, int n)
{
	int count = 0;
	int x = 0;
	for (x = y; x < n + 1; ++x)
	{
		for (int j = x; j; j /= 10)
		{
			if (j % 3 == 0)
			{
				count++;
			}
		}
	}
	return count;
}
//
//int main()
//{
//	int count = 0;
//	shujiu(1,100);
//	printf("%d", count);
//
//system("pause");
//return 0;
//}


	//int count = 0;
	//int x = 0;
	//for (x = 1; x < 101; ++x)
	//{
	//	for (int j = x; j; j /= 10)
	//	{
	//		if (j % 9 == 0)
	//		{
	//			count++;
	//		}
	//	}
	//}
	//printf("%d\n", count);
	//int i = 0;
	//double sum = 0;//计算的结果为小数,用浮点型
	//for (i = 1; i < 101; ++i)
	//{
	//	sum = sum+ pow(-1, i + 1)/i;//奇数项为正,偶数项为负
	//}
	//printf("%f\n", sum);


	//递归和非递归实现N的阶乘

//int jiecheng(int x)
//{
//	if (x == 1)
//	{
//		return 1;
//	}
//	return x * jiecheng(x - 1);
//}

int jiecheng(int n)
{
	int sum = 1;
	for (int i = 1; i < n + 1; ++i)
	{
		sum = sum*i;
	}
	return sum;
}
//递归写n^k
int nk(int n, int k)
{
	if (k == 1)
	{
		return n;
	}
	return n*nk(n, k - 1);
}

//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和， 
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
int DigitSum(int x)
{
	int j = 0;
	if (x < 10)
		{
			return x;
		}
		return x%10 + DigitSum(x / 10);
}

//递归和非递归分别实现strlen
//int strlen(char* str)
//{
//	int i = 0;
//	for (; str[i]; ++i);//字符串遍历
//		return i;
//}

int shuzuchangdu(char* str)
{
	if (*str == '\0')
	{
		return 0;
	}          
	return 1 + shuzuchangdu(str + 1);
}
//递归方式实现打印一个整数的每一位
void dayinmeiyiwei(int x)
{
	if (x ==0)
	{
		return ;
	}
	//printf("%d ", x % 10);  放这里是倒着打印
	dayinmeiyiwei(x / 10);
	printf("%d ", x % 10);//放下面是正着打印
}

//编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。

//反向排列就是首位互换

void  fanxiangpailie(char * string)
{
	char tmp;
	int mowei = strlen(string)-1;//末尾元素下标是长度减一
	//首先确定跳出条件,string[0]=="\0"
	if (string[0] == '\0')//判断是不是\0
	{
		return;
	}
	tmp= string[0];//把首元素存起来
	string[0] = string[mowei];//把末尾的元素放在第一位
	string[mowei] = '\0';//给末尾补上\0,确保每次都找到尾部
	fanxiangpailie(string + 1);//光标下移一位
	string[mowei] = tmp;//把存好的开头,后入先出的原则归位
}


//int main()
//{
	//int a, b;
	//scanf("%d %d", &a, &b);
	//int c=nk(a, b);
	//printf("%d\n", c);
	//char str="abcdefghijk";
	//printf("%d\n", strlen("abcdefghijk"));
	//char str = "luzihanshizuibangdebaobao";
	//printf("%d\n", shuzuchangdu("luzihanshizuibangdebaobao"));
int main()
{
	char str[]= "wozuixihuanlubaobao";
	fanxiangpailie(str);
	puts(str);
	system("pause");
	return 0;
}