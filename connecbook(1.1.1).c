#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
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

Contbook g_contbook;//����һ��ȫ�ֱ���

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
//����
typedef struct continfo
{
	char name[1024];
	//�Ա�  �����о�?
	char age[1024];
	char phone[1024];
	char address[1024];
}continfo;

//��֯
typedef struct Contbook
{
	continfo people[max_continfo_size];
	int size;  //[0,size)��ʾ��Ч��ͨѶ¼
}Contbook;


void addconnection()
{
	printf("������ϵ��\n");
	printf("��������ϵ�˵�����: ");
	//scanf("%s", g_contbook.people[g_contbook.size].name);
	//��ֹ����̫��,����һ��ָ��
	//����һ�������൱����һ�ݿ���,����g_contbook.people[g_contbook.size]��ֵ����ʼ��
	//�������޸Ĳ���Ӱ�쵽�����е�Ԫ��
	continfo* peopleinfo = &g_contbook.people[g_contbook.size];
	scanf("%s", peopleinfo->name);
	printf("��������ϵ�˵��Ա�: ");
	scanf("%s", peopleinfo->name);
	printf("��������ϵ�˵�����: "); 
	scanf("%s", peopleinfo->age);
	printf("��������ϵ�˵ĵ绰����: ");
	scanf("%s", peopleinfo->phone);
	printf("��������ϵ�˵�סַ: ");
	scanf("%s", peopleinfo->address);
	printf("������ϵ�˳ɹ�!\n");
}

void deleteconnection()
{
	printf("ɾ����ϵ�˳ɹ�!\n");
}

void findconnection()
{
	printf("������ϵ�˳ɹ�!\n");
}

void updateconnection()
{
	printf("�޸���ϵ����Ϣ�ɹ�!\n");
}

void Printallconnection()
{
	printf("��ʾ��ϵ�˳ɹ�!\n");
}

void emptyconnection()
{
	printf("�Ƿ�ȷ�����������ϵ��???!\n");
		printf("�����ϵ�˳ɹ�!\n");
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
	printf("����������ѡ��: \n");
		int choice = 0;
		scanf("%d", &choice);
		return choice;
}

typedef void(*Func)();

int main()
{
	Func arr[] =//����ָ������
	{
		addconnection,//�����ö���
		deleteconnection,
		findconnection,
		updateconnection,
		Printallconnection,
		emptyconnection,
		sortconnection,
		xianyu,
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