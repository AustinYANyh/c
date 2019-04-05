#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>//使用时间戳时要加头文件

//创建命令行版本的菜单
int Menu()
{
	printf("=================\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("=================\n");
	printf("请输入您的选择:");
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
	for (int hang = 0; hang <maxhang; ++hang)
	{
		for (int lie = 0; lie < maxlie; ++lie)
		{
			qipan[hang][lie] = ' ';
		}
	}
	//设置随机数种子
	srand((unsigned int) time(0));//unsigned int 要括起来,整体性
}

void print()
{
	for (int hang = 0; hang < maxhang; ++hang)
	{
		printf("| %c | %c | %c |\n", qipan[hang][0],
			qipan[hang][1], qipan[hang][2]);
		if (hang != maxhang-1)//最后一行,不打印---
		{
			printf("|---|---|---|\n");
		}
	}
}

void wanjiaxingdong()
{
	while (1)
	{
		printf("请玩家落子(hang lie):");
		int hang = 0;
		int  lie = 0;
		scanf("%d %d", &hang, &lie);
		//检查用户输入的坐标是否合法
		//尽量把每种异常情况都考虑到
		//最大行列为3,下标最大为2,等于3也是非法
		if (hang < 0 || hang >= maxhang || lie < 0 || lie >= maxlie)
		{
			printf("您输入的坐标非法!请重新输入~\n");
			continue;//跳过此步,重新循环
		}
	   if (qipan[hang][lie] != ' ')
		{
			printf("此位置已被占用!请重新输入~");
			continue;
		}
		//如果玩家的输入合法,那么棋盘的' '变为'x'
		qipan[hang][lie] = 'x';
		break;//玩家落子成功,则循环结束
	}
	printf("玩家落子完毕!~\n");
}

void diannaoxingdong()
{
	printf("电脑落子!\n");
	while (1)
	{
		int hang = rand() % 3;//生成0-2的随机数
		int  lie = rand() % 3;
		if (qipan[hang][lie] != ' ')
		{
			continue;//如果电脑落子的位置被占用,重生成随机数
		}
		qipan[hang][lie] = 'o'; //如果电脑落子位置没被占用, 修改状态为'o';
		break;
	}
	printf("电脑落子完毕!\n");
}

//胜利的条件是行或列或对角线连成一条线
//判断是'x' 还是'o'
//平局是'h' 未分胜负是' '
int pingju()//棋盘已满,未分胜负为平局
{
	//查看棋盘是否已满,用数组遍历
	for (int hang = 0; hang < maxhang; ++hang)
	{
		for (int lie = 0; lie < maxlie; ++lie)
		{
			if (qipan[hang][lie]==' ')
			{
				return 0;//棋盘未满
			}
		}
	}
	return 1;//两重循环结束没有找到空格,返回1
}

char shifoushengli()
{
	for (int hang = 0; hang < maxhang; ++hang)
	{
		if (qipan[hang][0] == qipan[hang][1] &&
			qipan[hang][0] == qipan[hang][2])
		{
			return qipan[hang][0];//通过返回的值是'x' 还是'o' 判断哪方获胜
		}
	}
	for (int lie = 0; lie < maxlie; ++lie)
	{
		if (qipan[0][lie] == qipan[1][lie] &&
			qipan[0][lie] == qipan[2][lie])
		{
			return qipan[0][lie];
		}
	}
	//两条对角线0.0 1.1 2.2 / 0.2 1.1 2.0
	if (qipan[0][0] == qipan[1][1] && qipan[0][0] == qipan[2][2])
	{
		return qipan[0][0];
	}
	if (qipan[0][2] == qipan[1][1] && qipan[0][2] == qipan[2][0])
	{
		return qipan[0][2];
	}
	if (pingju())
	{
		return 'h';//棋盘满胜负未分,表示平局
	}
	return ' ';//棋盘未满胜负未分,接着下
}



void Game()
{
	//1.初始化棋盘
	init();
	char huosheng = ' ';
	while (1)
	{   //打印棋盘
		print();
		//2.玩家落子
		wanjiaxingdong();
		//3.检测胜负
		huosheng = shifoushengli();
		if (huosheng != ' ')//等于' ' 说明胜负未分,继续执行
		{
			break;//不等于' ' 说明胜负已分,跳出循环
		}
		//4.电脑落子
		diannaoxingdong();
		//5.检测胜负
		huosheng = shifoushengli();
		if (huosheng != ' ')
		{
			break;
		}
	}
	print();
	if (huosheng == 'x')
	{
		printf("恭喜您获胜!\n");
	}
	else if (huosheng == 'o')
	{
		printf("很遗憾,您输了!\n");
	}
	else if (huosheng == 'h')
	{
		printf("平局!\n");
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