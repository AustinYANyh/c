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
}//3.���ʵ�֣� 
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩

void  fanxiangpailie(char * string)
{
	char tmp;
	int mowei = strlen(string) - 1;//ĩβԪ���±��ǳ��ȼ�һ
	//����ȷ����������,string[0]=="\0"
	if (string[0] == '\0')//�ж��ǲ���\0
	{
		return;
	}
	tmp = string[0];//����Ԫ�ش�����
	string[0] = string[mowei];//��ĩβ��Ԫ�ط��ڵ�һλ
	string[mowei] = '\0';//��ĩβ����\0,ȷ��ÿ�ζ��ҵ�β��
	fanxiangpailie(string + 1);//�������һλ
	string[mowei] = tmp;//�Ѵ�õĿ�ͷ,�����ȳ���ԭ���λ
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
	for (; str[i]; ++i)//����
	{
		if (str[i] == ' ')
		{
			reverse(str, start, i);//����һ��������ת
			start = i + 1;//��ͷ��Ϊ�ղŵ�ĩβ+1
		}
	}
	reverse(str, start, i);//����\0ʱ��start�����һ�����ʵĴ���
	reverse(str, 0, i);//��������
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