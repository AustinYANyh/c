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
//��д������һ�� 1�� 100 �����������г��ֶ��ٴ�����9
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
	//double sum = 0;//����Ľ��ΪС��,�ø�����
	//for (i = 1; i < 101; ++i)
	//{
	//	sum = sum+ pow(-1, i + 1)/i;//������Ϊ��,ż����Ϊ��
	//}
	//printf("%f\n", sum);


	//�ݹ�ͷǵݹ�ʵ��N�Ľ׳�

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
//�ݹ�дn^k
int nk(int n, int k)
{
	if (k == 1)
	{
		return n;
	}
	return n*nk(n, k - 1);
}

//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ� 
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
int DigitSum(int x)
{
	int j = 0;
	if (x < 10)
		{
			return x;
		}
		return x%10 + DigitSum(x / 10);
}

//�ݹ�ͷǵݹ�ֱ�ʵ��strlen
//int strlen(char* str)
//{
//	int i = 0;
//	for (; str[i]; ++i);//�ַ�������
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
//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
void dayinmeiyiwei(int x)
{
	if (x ==0)
	{
		return ;
	}
	//printf("%d ", x % 10);  �������ǵ��Ŵ�ӡ
	dayinmeiyiwei(x / 10);
	printf("%d ", x % 10);//�����������Ŵ�ӡ
}

//��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������

//�������о�����λ����

void  fanxiangpailie(char * string)
{
	char tmp;
	int mowei = strlen(string)-1;//ĩβԪ���±��ǳ��ȼ�һ
	//����ȷ����������,string[0]=="\0"
	if (string[0] == '\0')//�ж��ǲ���\0
	{
		return;
	}
	tmp= string[0];//����Ԫ�ش�����
	string[0] = string[mowei];//��ĩβ��Ԫ�ط��ڵ�һλ
	string[mowei] = '\0';//��ĩβ����\0,ȷ��ÿ�ζ��ҵ�β��
	fanxiangpailie(string + 1);//�������һλ
	string[mowei] = tmp;//�Ѵ�õĿ�ͷ,�����ȳ���ԭ���λ
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