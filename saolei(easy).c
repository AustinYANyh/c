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
	printf("1. ��ʼ��Ϸ  \n");
	printf("0. ������Ϸ  \n");
	printf("=============\n");
	printf("����������ѡ��:");
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
			wanjiaditu[hang][lie] = '*';//ȫ����ʼ��Ϊ*
		}
	}
	//������ɵ���,��0��ʾ���ǵ���,��1��ʾ�ǵ���
	for (int hang = 0; hang < maxhang; ++hang)
	{
		for (int lie = 0; lie < maxlie; ++lie)
		{
			dileiditu[hang][lie] = '0';
		}
	}
	int s = dileishuliang;
	srand((unsigned int)time(0));//���������
	while (s>0)
	{
		int hang = rand() % maxhang;
		int lie = rand() % maxlie;
		if (dileiditu[hang][lie] == '1')//�����˴��Ѿ��ǵ���
		{
			continue;//��������
		}
		dileiditu[hang][lie] = '1';
		--s;
	}
}

void dayinditu(char wanjiaditu[maxhang][maxlie])
{
	//��һ��Ҫ��������(��ͷ�ո�,����ÿ�зֱ�������)
	printf("    ");
	for (int lie = 0; lie < maxlie; ++lie)
	{
		printf("%d ", lie);
	}
	printf("\n");
	//���ֵ�����ķָ���,ÿһ�д�һ��---,�Ӽ�ѭ������������
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
	//�õ�����Χ�˸����ӵĵ��׵ĸ���
	wanjiaditu[hang][lie] = '0'+ n;//�ѵ��׸�����ʾ�������ĵĸ�����
}

void game()
{
	//1.������ͼ
	char wanjiaditu[maxhang][maxlie];
	char dileiditu[maxhang][maxlie];
	init(wanjiaditu,dileiditu);
	int konggeshuliang = 0;
	//2.��ӡ��ͼ
	while (1)
	{
		dayinditu(wanjiaditu);
		dayinditu(dileiditu);//����ʹ��
	//3.��ʾ�û���������:
		printf("��������һ������(hang lie):");
		int hang = 0;
		int lie = 0;
		scanf("%d %d", &hang, &lie);
		//����֮ǰ������
		system("cls");
		//���������������ĺϷ���
		if (hang < 0 || hang >= maxhang || lie < 0 || lie >= maxlie)
		{
			printf("�������벻�Ϸ�!����������!\n");
			continue;
		}
		if (wanjiaditu[hang][lie] != '*')
		{
			printf("��������!����!\n");
			continue;
		}
		//4.�ж���ҷ����ĵط��Ƿ��ǵ���
		if (dileiditu[hang][lie] == '1')
		{
			printf("���ź�!����ը����!~\n");
			dayinditu(dileiditu);//����֮�������ҵ���λ�÷ֲ�
			return;
		}
		++konggeshuliang;
		//�ж���Ϸ�Ƿ�ʤ��(�ǵ������򶼱�����)
		if (konggeshuliang == maxhang*maxlie - dileishuliang)
		{
			printf("һ��С�ı���������!ʤ��!~\n");
			dayinditu(dileiditu);
			break;
		}
		//5.ͳ����Χ���׵�����
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