#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0;
	int b = 1;
	int c;
	c = a;
	a = b;
	b = c;
	printf("%d %d", a, b);
	system("pause");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 10; //01010
	int b = 20; //10100
	a = a^b; //a=11110 b=10100
	b = a^b; //b=01010 a=11110
	a = a^b; //a=10100
	printf("a=%d\nb=%d\n", a, b);
	system("pause");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[10] = { 1, 9, 5, 48, 52, 64, 98, 7505, 944, 10 };
	int max = 0;
	for (int i = 0; i < 11; ++i)
	{
		if (arr[i]>max)
		{
			max = arr[i];
		}
	}
	printf("%d\n", max);
	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h> 
int main()
{
	int a;
	int b;
	int c;
	scanf("%d %d %d", &a, &b, &c);
	int max, min;
	if (a>b)
	{
		max = a;
		min = b;
	}
	if (a < b)
	{
		max = b;
		min = a;
	}
	if (c>max)
	{
		printf("%d %d %d", c, max, min);
	}
	if (c < min)
	{
		printf("%d %d %d", max, min, c);
	}
	else printf("%d %d %d", max, c, min);
	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h> 
int zuidagongyueshu(int x, int y)
{
	if (x%y == 0)
	{
		return y;//80%40==0,80��40�����Լ������40
	}//80%70==10,��ʱ������70��10�����Լ��,���Ϊ10
	//��ô,10����80��70�����Լ��
	else return zuidagongyueshu(y, x%y);
}
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int c = zuidagongyueshu(a, b);
	printf("%d", c);
	system("pause");
	return 0;
}

int main()
{
	while (1)
	{
		char a;
		a=getchar();
		if (a<='z'&&a>='a')
		{
			putchar(a-('a'-'A'));//�������Сд��ĸ,ת��Ϊ��д��ĸ
		}
		else if (a <= 'Z'&&a >= 'A')
		{
			putchar(a - ('A' - 'a'));//��������д��ĸ,ת��ΪСд��ĸ
		}
		else if (isalnum(a))
		{
			// ��������������,��ʲôҲ����
		}
		if (a == ' ')//�趨��������Ϊ������ַ�Ϊ�ո�
		{
			break;
		}
		else putchar(a);//�������֮����������
	}
	system("pause");
	return 0;
}
