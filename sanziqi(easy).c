#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>//ʹ��ʱ���ʱҪ��ͷ�ļ�

//���������а汾�Ĳ˵�
int Menu()
{
	printf("=================\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.������Ϸ\n");
	printf("=================\n");
	printf("����������ѡ��:");
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
	for (int hang = 0; hang <maxhang; ++hang)
	{
		for (int lie = 0; lie < maxlie; ++lie)
		{
			qipan[hang][lie] = ' ';
		}
	}
	//�������������
	srand((unsigned int) time(0));//unsigned int Ҫ������,������
}

void print()
{
	for (int hang = 0; hang < maxhang; ++hang)
	{
		printf("| %c | %c | %c |\n", qipan[hang][0],
			qipan[hang][1], qipan[hang][2]);
		if (hang != maxhang-1)//���һ��,����ӡ---
		{
			printf("|---|---|---|\n");
		}
	}
}

void wanjiaxingdong()
{
	while (1)
	{
		printf("���������(hang lie):");
		int hang = 0;
		int  lie = 0;
		scanf("%d %d", &hang, &lie);
		//����û�����������Ƿ�Ϸ�
		//������ÿ���쳣��������ǵ�
		//�������Ϊ3,�±����Ϊ2,����3Ҳ�ǷǷ�
		if (hang < 0 || hang >= maxhang || lie < 0 || lie >= maxlie)
		{
			printf("�����������Ƿ�!����������~\n");
			continue;//�����˲�,����ѭ��
		}
	   if (qipan[hang][lie] != ' ')
		{
			printf("��λ���ѱ�ռ��!����������~");
			continue;
		}
		//�����ҵ�����Ϸ�,��ô���̵�' '��Ϊ'x'
		qipan[hang][lie] = 'x';
		break;//������ӳɹ�,��ѭ������
	}
	printf("����������!~\n");
}

void diannaoxingdong()
{
	printf("��������!\n");
	while (1)
	{
		int hang = rand() % 3;//����0-2�������
		int  lie = rand() % 3;
		if (qipan[hang][lie] != ' ')
		{
			continue;//����������ӵ�λ�ñ�ռ��,�����������
		}
		qipan[hang][lie] = 'o'; //�����������λ��û��ռ��, �޸�״̬Ϊ'o';
		break;
	}
	printf("�����������!\n");
}

//ʤ�����������л��л�Խ�������һ����
//�ж���'x' ����'o'
//ƽ����'h' δ��ʤ����' '
int pingju()//��������,δ��ʤ��Ϊƽ��
{
	//�鿴�����Ƿ�����,���������
	for (int hang = 0; hang < maxhang; ++hang)
	{
		for (int lie = 0; lie < maxlie; ++lie)
		{
			if (qipan[hang][lie]==' ')
			{
				return 0;//����δ��
			}
		}
	}
	return 1;//����ѭ������û���ҵ��ո�,����1
}

char shifoushengli()
{
	for (int hang = 0; hang < maxhang; ++hang)
	{
		if (qipan[hang][0] == qipan[hang][1] &&
			qipan[hang][0] == qipan[hang][2])
		{
			return qipan[hang][0];//ͨ�����ص�ֵ��'x' ����'o' �ж��ķ���ʤ
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
	//�����Խ���0.0 1.1 2.2 / 0.2 1.1 2.0
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
		return 'h';//������ʤ��δ��,��ʾƽ��
	}
	return ' ';//����δ��ʤ��δ��,������
}



void Game()
{
	//1.��ʼ������
	init();
	char huosheng = ' ';
	while (1)
	{   //��ӡ����
		print();
		//2.�������
		wanjiaxingdong();
		//3.���ʤ��
		huosheng = shifoushengli();
		if (huosheng != ' ')//����' ' ˵��ʤ��δ��,����ִ��
		{
			break;//������' ' ˵��ʤ���ѷ�,����ѭ��
		}
		//4.��������
		diannaoxingdong();
		//5.���ʤ��
		huosheng = shifoushengli();
		if (huosheng != ' ')
		{
			break;
		}
	}
	print();
	if (huosheng == 'x')
	{
		printf("��ϲ����ʤ!\n");
	}
	else if (huosheng == 'o')
	{
		printf("���ź�,������!\n");
	}
	else if (huosheng == 'h')
	{
		printf("ƽ��!\n");
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