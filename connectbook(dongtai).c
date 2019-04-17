#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
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


//����
typedef struct Continfo
{
	char name[1024];
	char sex[1024];
	char age[1024];
	char phone[1024];
	char address[1024];
}Continfo;


//��֯
typedef struct Contbook
{
	Continfo* people;
	int size;  //[0,size)��ʾ��Ч��ͨѶ¼
	int fullsize;
}Contbook;

Contbook g_contbook;//����һ��ȫ�ֱ���

//����һ��һ��ִ��,�õ��ı���һ��Ҫ���ڶ���֮��

void init()//��ʼ������
{
	g_contbook.size = 0;
	g_contbook.fullsize = 1000;
	g_contbook.people = (Continfo*)malloc(sizeof(Continfo)*g_contbook.fullsize);
	for (int i = 0; i < g_contbook.fullsize; ++i)
	{
		g_contbook.people[i].name[0] = '\0';//.��ʾ�ṹ���Ա�ķ���
		g_contbook.people[i].sex[0] = '\0';
		g_contbook.people[i].age[0] = '\0';
		g_contbook.people[i].phone[0] = '\0';
		g_contbook.people[i].address[0] = '\0';
	}
}

void addconnection()
{
	printf("������ϵ��\n");
	if (g_contbook.size > g_contbook.fullsize)
	{
		printf("�ռ䲻��!����1000!���ݳɹ�!\n");
		g_contbook.fullsize += 1000;
		g_contbook.people = (Continfo*)realloc(g_contbook.people, g_contbook.fullsize*sizeof(Continfo));
	}
	printf("��������ϵ�˵�����: ");
	//scanf("%s", g_contbook.people[g_contbook.size].name);
	//��ֹ����̫��,����һ��ָ��
	//����һ�������൱����һ�ݿ���,����g_contbook.people[g_contbook.size]��ֵ����ʼ��
	//�������޸Ĳ���Ӱ�쵽�����е�Ԫ��
	Continfo* peopleinfo = &g_contbook.people[g_contbook.size];
	scanf("%s", peopleinfo->name);
	printf("��������ϵ�˵��Ա�: ");
	scanf("%s", peopleinfo->sex);
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
		system("cls");
		printf("����������ϵ��: \n");
		for (int i = 0; i < g_contbook.size; ++i)
		{
			Continfo* info = &g_contbook.people[i];
			printf("[%d] ����:%s\t �Ա�:%s\t ����:%s\t �绰����:%s\t  סַ:%s\t \n",
				i + 1, info->name, info->sex, info->age, info->phone, info->address);
		}
		printf("��ʾ��ϵ�˳ɹ�!\n");
	}
}

void deleteconnection()
{
	if (g_contbook.size == 0)
	{
		printf("ɾ��ʧ��!����ͨѶ¼�����������ɾ�!\n");
	}
	else
	{
		Printallconnection();
		while (1)
		{
			printf("����1000ȡ������!! ");
			printf("��������Ҫɾ������ϵ�˵����: ");
			int num1 = 0;
			scanf("%d", &num1);
			if (num1 == 1000)
			{
				system("cls");
				printf("ȡ��ɾ���ɹ�!\n");
				return;
			}

			else if (num1<1 || num1>g_contbook.size)
			{
				printf("������������!�뿴�������!\n");
				continue;
			}

			else
			{
				g_contbook.people[num1 - 1] = g_contbook.people[g_contbook.size - 1];
				--g_contbook.size;
				printf("ɾ����ϵ�˳ɹ�!\n");
				return;
			}
		}
	}
}

void findconnection()
{
	if (g_contbook.size == 0)
	{
		printf("����ʧ��!����ͨѶ¼�����������ɾ�!\n");
	}
	else
	{
		printf("��������Ҫ���ҵ���ϵ������: ");
		char name[1024] = { 0 };
		scanf("%s", name);
		for (int i = 0; i < g_contbook.size; ++i)
		{
			Continfo* info = &g_contbook.people[i];
			if (strcmp(info->name, name) == 0)
			{
				printf("[%d] ����:%s\t �Ա�:%s\t ����:%s\t �绰����:%s\t  סַ:%s\t \n",
					i + 1, info->name, info->sex, info->age, info->phone, info->address);
				continue;
			}
			else
			{
				system("cls");
				printf("δ�ҵ���ϵ��\n");
				return;
			}
		}
		printf("������ϵ�˳ɹ�!\n");
	}
}

void updateconnection()
{
	if (g_contbook.size == 0)
	{
		printf("�޸�ʧ��!����ͨѶ¼�����������ɾ�!\n");
		return;
	}
	else
	{
		Printallconnection();
		while (1)
		{
			printf("��������Ҫ�޸ĵ���ϵ�˵����: ");
			int num2 = 0;
			scanf("%d", &num2);
			if (num2<1 || num2>g_contbook.size)
			{
				printf("������������!�뿴�������!\n");
				continue;
			}
			Continfo* info = &g_contbook.people[num2 - 1];
			printf("����/��ʾ���������޸�!");
			printf("����(%s)�µ�������: ", info->name);
			char name[1024] = { 0 };
			scanf("%s", name);
			if (strcmp(name, "/") != 0)//���������ǿ��ַ���������,˵�����޸�
			{
				strcpy(info->name, name);
			}
			printf("����(%s)�µ��Ա���: ", info->sex);
			char sex[1024] = { 0 };
			scanf("%s", sex);
			if (strcmp(sex, "/") != 0)
			{
				strcpy(info->sex, sex);
			}
			printf("����(%s)�µ�������: ", info->age);
			char age[1024] = { 0 };
			scanf("%s", age);
			if (strcmp(age, "/") != 0)
			{
				strcpy(info->age, age);
			}
			printf("����(%s)�µĵ绰������: ", info->phone);
			char phone[1024] = { 0 };
			scanf("%s", phone);
			if (strcmp(phone, "/") != 0)
			{
				strcpy(info->phone, phone);
			}
			printf("����(%s)�µ�סַ��: ", info->address);
			char address[1024] = { 0 };
			scanf("%s", address);
			if (strcmp(address, "/") != 0)
			{
				strcpy(info->address, address);
			}
			printf("�޸���ϵ����Ϣ�ɹ�!\n");
			return;
		}
	}
}



void emptyconnection()
{
	printf("�Ƿ�ȷ�����������ϵ��???\nȷ������1,ȡ������2!\n");
	int num = 0;
	scanf("%d", &num);
	if (num == 1)
	{
		g_contbook.size = 0;
		printf("�����ϵ�˳ɹ�!\n");
		Printallconnection();
	}
	else if (num == 2)
	{
		printf("�Ҿ�֪�����᲻��ɾ��!");
		return;
	}
	else printf("������������!�ǲ��ǲ���ɾ!\n");
}


void sortconnection()
{
	//ð�ݵķ�ʽ���ֵ����������
	if (g_contbook.size == 0)
	{
		system("cls");
		printf("ɶ��û��!��ô����!\n");
		return;
	}

	int a = 0;
	for (a = 0; a < g_contbook.size - 1; ++a)
	{
		for (int b = 0; b<g_contbook.size - a - 1; ++b)
		{
			if (strcmp(g_contbook.people[b].name, g_contbook.people[b + 1].name) > 0)
			{


				Continfo tmp = g_contbook.people[b];
				g_contbook.people[b] = g_contbook.people[b + 1];
				g_contbook.people[b + 1] = tmp;


			}
		}
	}
	printf("������ϵ����Ϣ�ɹ�!\n");
	Printallconnection();
	return;
}

void infowrite()
{	//�ļ�ָ�����,�ļ��ڶ�д֮ǰӦ���ȴ��ļ�,��ʹ�ý���֮��Ӧ�ùر��ļ�
	//ANSIC�涨ʹ��fopen�������ļ�,fclose�ر��ļ�
	//"wb"������Ϊ��������ݴ�һ���������ļ�,���ָ���ļ������ڽ���һ�����ļ�
	FILE* pf = fopen("connectbook.txt", "wb");
	if (pf == NULL)
	{
		perror("open file for write");
		exit(EXIT_FAILURE);
	}
	//д�ļ�
	int i = 0;
	for (i = 0; i < g_contbook.size; i++)
	{
		//fwite�����Ƕ��������,�������ļ�
		fwrite(&g_contbook.people[i], sizeof(Continfo), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}

void inforead()
{
	// "rb"��ʾֻ��,Ϊ���������ݴ�һ���Ѿ����ڵĶ������ļ�
	FILE* pfread = fopen("connectbook.txt", "rb");
	if (pfread == NULL)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	Continfo temp = { 0 };
	int  i = 0;
	while (fread(&temp, sizeof(Continfo), 1, pfread))// fread��ʾ����������
	{
		g_contbook.people[i] = temp;		i++;		g_contbook.size++;
	}
	fclose(pfread);
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
		infowrite,
		inforead
	};
	init();
	while (1)
	{
		int choice = menu();
		if (choice < 0 || choice >= sizeof(arr) / sizeof(arr[0]))//�����Ժ��޸��鷳
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