#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//创建命令行版本的菜单
int Menu()
{
	printf("=================\n");
	printf("1.开始游戏\n");
	printf("2.结束游戏\n");
	printf("=================\n");
	printf("请输入您的选择:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
//用宏定义的好处在于便于以后修改
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
		if (i != maxhang-1)//最后一行,不打印---
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
	//1.初始化并打印棋盘
	init();
	while (1)
	{
		Print();
		//2.玩家落子
		wanjiaxingdong();
		//3.检测胜负
		shifoushengli();
		//4.电脑落子
		diannaoxingdong();
		//5.检测胜负
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
		else printf("您的输入有误!\n");
	}

system("pause");
return 0;
}