#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//���������а汾�Ĳ˵�
int Menu()
{
	printf("=================\n");
	printf("1.��ʼ��Ϸ\n");
	printf("2.������Ϸ\n");
	printf("=================\n");
	printf("����������ѡ��:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
//�ú궨��ĺô����ڱ����Ժ��޸�
#define maxhang 3
#define maxlie 3
char qipan[maxhang][maxlie];

void init()
{
	for (int i = 0; i <maxhang; ++i)
	{
		for (int j = 0; j < maxlie; ++j)
		{
			qipan[maxhang][maxlie] = " ";
		}
	}
}

void Print()
{
	for (int i = 0; i < maxhang; ++i)
	{
		printf("| %c | %c | %c |\n", qipan[maxhang][0],
			qipan[maxhang][1], qipan[maxhang][2]);
		if (i != maxhang-1)//���һ��,����ӡ---
		{
			printf("|---|---|---|\n");
		}
	}
	system("pause");
}

void wanjiaxingdong()
{

}

void shifoushengli()
{

}

void diannaoxingdong()
{

}

void Game()
{
	//1.��ʼ������ӡ����
	init();
	while (1)
	{
		Print();
		//2.�������
		wanjiaxingdong();
		//3.���ʤ��
		shifoushengli();
		//4.��������
		diannaoxingdong();
		//5.���ʤ��
		shifoushengli();
	}
}

int main()
{
	while (1)
	{
		int choice = Menu();
		if (choice == 1)
		{
			Game();
		}
		else if (choice == 0)
		{
			printf("GoodBye!\n");
		}
		else printf("������������!\n");
	}

system("pause");
return 0;
}