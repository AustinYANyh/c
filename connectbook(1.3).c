#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<windows.h>
//ʵ��һ��ͨѶ¼��
//ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ������
// �������Ա����䡢�绰��סַ

//�ṩ������
//1. �����ϵ����Ϣ
//2. ɾ��ָ����ϵ����Ϣ
//3. ����ָ����ϵ����Ϣ
//4. �޸�ָ����ϵ����Ϣ
//5. ��ʾ������ϵ����Ϣ
//6. ���������ϵ��
//7. ����������������ϵ��
//8. ������ϵ�˵��ļ�
//9. ������ϵ��

#define max_continfo_size 1000

//����
typedef struct Continfo
{
	char name[1024];
	//�Ա�  �����о�?
	char age[1024];
	char phone[1024];
	char address[1024];
}Continfo;

//typedef enum sex
//{
//	 male=1,
//	 female=2,
//	 secret=3
//}sex;

//��֯
typedef struct Contbook
{
	Continfo people[max_continfo_size];
	int size;  //[0,size)��ʾ��Ч��ͨѶ¼
}Contbook;

Contbook g_contbook;//����һ��ȫ�ֱ���

//����һ��һ��ִ��,�õ��ı���һ��Ҫ���ڶ���֮��

void init()//��ʼ������
{
	g_contbook.size = 0;
	for (int i = 0; i < max_continfo_size; ++i)
	{
		g_contbook.people[i].name[0] = '\0';//.��ʾ�ṹ���Ա�ķ���
		g_contbook.people[i].name[0] = '\0';
		g_contbook.people[i].age[0] = '\0';
		g_contbook.people[i].phone[0] = '\0';
		g_contbook.people[i].address[0] = '\0';
	}
}

void addconnection()
{
	printf("������ϵ��\n");
	if (g_contbook.size > max_continfo_size)
	{
		printf("������ϵ��ʧ����!��ȥɾ������!\n");
	}
	printf("��������ϵ�˵�����: ");
	//scanf("%s", g_contbook.people[g_contbook.size].name);
	//��ֹ����̫��,����һ��ָ��
	//����һ�������൱����һ�ݿ���,����g_contbook.people[g_contbook.size]��ֵ����ʼ��
	//�������޸Ĳ���Ӱ�쵽�����е�Ԫ��
	Continfo* peopleinfo = &g_contbook.people[g_contbook.size];
	scanf("%s", peopleinfo->name);
	//printf("����1��������,����2����Ů��,����3������! ");
	//printf("��������ϵ�˵��Ա�: ");
	//scanf("%d", g_contbook.people[g_contbook.size].sex);
	printf("��������ϵ�˵�����: "); 
	scanf("%s", peopleinfo->age);
	printf("��������ϵ�˵ĵ绰����: ");
	scanf("%s", peopleinfo->phone);
	printf("��������ϵ�˵�סַ: ");
	scanf("%s", peopleinfo->address);
	++g_contbook.size;
	system("cls");
	printf("������ϵ�˳ɹ�!\n");
}

void Printallconnection()
{
	if (g_contbook.size == 0)
	{
		system("cls");
		printf("ͨѶ¼��û���κ���ֵĶ���!\n");
	}
	else
	{
		printf("����������ϵ��: \n");
		for (int i = 0; i < g_contbook.size; ++i)
		{
			Continfo* info = &g_contbook.people[i];
			printf("[%d] ����:%s\t����:%s\t�绰����:%s\tסַ:%s\t \n",
				i + 1, info->name, info->age, info->phone, info->address);
		}
		printf("��ʾ��ϵ�˳ɹ�!\n");
	}
}

void deleteconnection()
{
	if (g_contbook.size == 0)
	{
		printf("ɾ��ʧ��!����ͨѶ¼�����������ɾ�!");
	}
	else
	{
		Printallconnection();
		while (1)
		{
			printf("��������Ҫɾ������ϵ�˵����: ");
			int num1 = 0;
			scanf("%d", &num1);
			if (num1<1 || num1>g_contbook.size)
			{
				printf("������������!�뿴�������!\n");
				continue;
			}
			else 
			{
				g_contbook.people[num1-1].name[0] = g_contbook.people[g_contbook.size - 1].name[0];
				g_contbook.people[num1-1].name[0] = g_contbook.people[g_contbook.size - 1].name[0];
				g_contbook.people[num1-1].age[0] = g_contbook.people[g_contbook.size - 1].name[0];
				g_contbook.people[num1-1].phone[0] = g_contbook.people[g_contbook.size - 1].name[0];
				g_contbook.people[num1-1].address[0] = g_contbook.people[g_contbook.size - 1].name[0];
				--g_contbook.size;
				printf("ɾ����ϵ�˳ɹ�!\n");
				return;
			}
		}
	}
}

void findconnection()
{
	printf("������ϵ�˳ɹ�!\n");
}

void updateconnection()
{
	printf("�޸���ϵ����Ϣ�ɹ�!\n");
}



void emptyconnection()
{
	printf("�Ƿ�ȷ�����������ϵ��???\nȷ������1,ȡ������2!\n");
	int num = 0;
	scanf("%d", &num);
	if (num == 1)
	{
		for (int i = 0; i < max_continfo_size; ++i)
		{
			g_contbook.people[i].name[0] = '\0';//.��ʾ�ṹ���Ա�ķ���
			g_contbook.people[i].name[0] = '\0';
			g_contbook.people[i].age[0] = '\0';
			g_contbook.people[i].phone[0] = '\0';
			g_contbook.people[i].address[0] = '\0';
			g_contbook.size = 0;
		}
		printf("�����ϵ�˳ɹ�!\n");
		Printallconnection();
	}
	else if (num==2)
	{
		return;
	}
}

void sortconnection()
{
	
}

void xianyu()
{

}

int menu()
{
	printf("======================\n");
	printf("1. �����ϵ����Ϣ\n");
	printf("2. ɾ��ָ����ϵ����Ϣ\n");
	printf("3. ����ָ����ϵ����Ϣ\n");
	printf("4. �޸�ָ����ϵ����Ϣ\n");
	printf("5. ��ʾ������ϵ����Ϣ\n");
	printf("6. ���������ϵ��\n");
	printf("7. ����������������ϵ��\n");
	printf("8. ������ϵ�˵��ļ�\n");
	printf("9. ������ϵ��\n");
	printf("0. �˳�ͨѶ¼\n");
	printf("====================\n");
	printf("����������ѡ��: ");
		int choice = 0;
		scanf("%d", &choice);
		return choice;
}

typedef void(*Func)();

int main()
{
	Func arr[] =//����ָ������
	{
		xianyu,
		addconnection,//�����ö���
		deleteconnection,
		findconnection,
		updateconnection,
		Printallconnection,
		emptyconnection,
		sortconnection,
		
	};

	while (1)
	{
		int choice = menu();
		if (choice < 0 || choice >= sizeof(arr)/sizeof(arr[0]))//�����Ժ��޸��鷳
		{
			printf("������������!\n");
			continue;
		}
		if (choice == 0)
		{
			printf("��ӭ���´�ʹ��!�ݰ�!");
			break;
		}
		arr[choice]();
	}
   system("pause");
   return 0;
}