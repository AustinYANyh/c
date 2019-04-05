#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

#define maxhang 9
#define maxlie  9
#define dileishuliang 10

int Menu()
{
	printf("=============\n");
	printf("1. 开始游戏  \n");
	printf("0. 结束游戏  \n");
	printf("=============\n");
	printf("请输入您的选择:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void init(char wanjiaditu[maxhang][maxlie],char dileiditu[maxhang][maxlie])
{
	for (int hang = 0; hang < maxhang; ++hang)
	{
		for (int lie = 0; lie < maxlie; ++lie)
		{
			wanjiaditu[hang][lie] = '*';//全部初始化为*
		}
	}
	//随机生成地雷,用0表示不是地雷,用1表示是地雷
	for (int hang = 0; hang < maxhang; ++hang)
	{
		for (int lie = 0; lie < maxlie; ++lie)
		{
			dileiditu[hang][lie] = '0';
		}
	}
	int s = dileishuliang;
	srand((unsigned int)time(0));//随机数种子
	while (s>0)
	{
		int hang = rand() % maxhang;
		int lie = rand() % maxlie;
		if (dileiditu[hang][lie] == '1')//表明此处已经是地雷
		{
			continue;//重新生成
		}
		dileiditu[hang][lie] = '1';
		--s;
	}
}

void dayinditu(char wanjiaditu[maxhang][maxlie])
{
	//第一行要附带坐标(开头空格,其余每列分别是数字)
	printf("    ");
	for (int lie = 0; lie < maxlie; ++lie)
	{
		printf("%d ", lie);
	}
	printf("\n");
	//数字的下面的分割线,每一列打一个---,加减循环次数调长度
	for (int lie = 0; lie < maxlie-1 ; ++lie)
	{
		printf("---");
	}
	printf("\n");
	for (int hang = 0; hang < maxhang; ++hang)
	{
		printf(" %d| ",hang);
		for (int lie = 0; lie < maxlie; ++lie)
		{   
			printf("%c ", wanjiaditu[hang][lie]);
		}
		printf("\n");
	}
}

void gengxinwanjiaditu(int hang,int lie,char wanjiaditu[maxhang][maxlie]
	,char dileiditu[maxhang][maxlie])
{
	int n = 0;
	if (hang - 1 >= 0 && lie - 1 >= 0 && hang - 1 < maxhang
		&&lie - 1 < maxlie&&dileiditu[hang - 1][lie - 1] == '1')
	{
		++n;
	}
	if (hang - 1 >= 0 && lie  >= 0 && hang - 1 < maxhang
		&&lie  < maxlie&&dileiditu[hang - 1][lie ] == '1')
	{
		++n;
	}
	if (hang - 1 >= 0 && lie - 1 >= 0 && hang - 1 < maxhang
		&&lie - 1 < maxlie&&dileiditu[hang - 1][lie - 1] == '1')
	{
		++n;
	}
	if (hang >= 0 && lie + 1 >= 0 && hang  < maxhang
		&&lie + 1 < maxlie&&dileiditu[hang ][lie + 1] == '1')
	{
		++n;
	}
	if (hang >= 0 && lie - 1 >= 0 && hang  < maxhang
		&&lie - 1 < maxlie&&dileiditu[hang ][lie - 1] == '1')
	{
		++n;
	}
	if (hang +1 >= 0 && lie +1>= 0 && hang  < maxhang
		&&lie +1 < maxlie&&dileiditu[hang +1][lie+1 ] == '1')
	{
		++n;
	}
	if (hang + 1 >= 0 && lie - 1 >= 0 && hang + 1 < maxhang
		&&lie - 1 < maxlie&&dileiditu[hang + 1][lie - 1] == '1')
	{
		++n;
	}
	if (hang + 1 >= 0 && lie  >= 0 && hang + 1 < maxhang
		&&lie  < maxlie&&dileiditu[hang + 1][lie ] == '1')
	{
		++n;
	}
	//得到了周围八个格子的地雷的个数
	wanjiaditu[hang][lie] = '0'+ n;//把地雷个数显示在最中心的格子上
}

void game()
{
	//1.创建地图
	char wanjiaditu[maxhang][maxlie];
	char dileiditu[maxhang][maxlie];
	init(wanjiaditu,dileiditu);
	int konggeshuliang = 0;
	//2.打印地图
	while (1)
	{
		dayinditu(wanjiaditu);
		dayinditu(dileiditu);//调试使用
	//3.提示用户输入坐标:
		printf("请先输入一组坐标(hang lie):");
		int hang = 0;
		int lie = 0;
		scanf("%d %d", &hang, &lie);
		//清理之前的棋盘
		system("cls");
		//检测玩家输入的坐标的合法性
		if (hang < 0 || hang >= maxhang || lie < 0 || lie >= maxlie)
		{
			printf("您的输入不合法!请重新输入!\n");
			continue;
		}
		if (wanjiaditu[hang][lie] != '*')
		{
			printf("翻开过了!少年!\n");
			continue;
		}
		//4.判断玩家翻开的地方是否是地雷
		if (dileiditu[hang][lie] == '1')
		{
			printf("很遗憾!您被炸死了!~\n");
			dayinditu(dileiditu);//结束之后告诉玩家地雷位置分布
			return;
		}
		++konggeshuliang;
		//判断游戏是否胜利(非地雷区域都被翻开)
		if (konggeshuliang == maxhang*maxlie - dileishuliang)
		{
			printf("一不小心被你找完了!胜利!~\n");
			dayinditu(dileiditu);
			break;
		}
		//5.统计周围地雷的数量
		gengxinwanjiaditu(hang, lie, wanjiaditu,dileiditu);
	}
}


int main()
{
	while (1)
	{
		int choice = Menu();
		if (choice == 1)
		{
			game();
		}
		if (choice == 0)
		{
			printf("GOODBYE!\n");
			break;
		}
	}
system("pause");
return 0;
}