#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 实现一个函数，可以左旋字符串中的k个字符
// ABCD左旋一个字符得到BCDA ABCD左旋两个字符得到CDAB

//先将要左旋的字符存起来,随后用strcat拼接

void Blodd(char str[], int n)
{
	int size = strlen(str);
	char tmp[1024] = { 0 };
	int i = 0;
	n %= size;  //如果左旋字符多于字符串长度取余数即可
	for (; i < size - n; ++i)
	{
		tmp[i] = str[i + n];  //拿不掉左旋的字符,所以我们拿下来剩下的
	}
	for (i; i < size; ++i)
	{
		tmp[i] = str[(i + n) - size]; // 现在把开头的,也就是左旋的字符拿出来赋值
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
	//for (i = 0; i < 10; ++i)  //查找单独不配对的数的写法
	//{
	//	sum ^= arr[i];
	//}
	//printf("%d ", sum);
	//printf("%d \n", 10 ^ 12);
	int a;// 用来记录哪一位是1
	int num1 = 0;
	int num2 = 0; 
	for (i = 0; i < 32; ++i)
	{
		if (sum & 1 << i)    //在sum里面找每一位 看是否为1,如果是1,记录位置
		{
			a = i;
			break;
		}
	}
	for (i = 0; i < 10; ++i)
	{
		if (arr[i] & 1 << a) //在数组中查找那一位为1的数归为一组,不为1的为一组
		{
			num1 ^= arr[i];//对两组数分别异或就可以找出两组数种单独出现的一个
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

