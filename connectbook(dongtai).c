#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<windows.h>
//实现一个通讯录；
//通讯录可以用来存储1000个人的信息，每个人的信息包括：
// 姓名、性别、年龄、电话、住址

//提供方法：
//1. 添加联系人信息
//2. 删除指定联系人信息
//3. 查找指定联系人信息
//4. 修改指定联系人信息
//5. 显示所有联系人信息
//6. 清空所有联系人
//7. 以名字排序所有联系人
//8. 保存联系人到文件
//9. 加载联系人


//描述
typedef struct Continfo
{
	char name[1024];
	char sex[1024];
	char age[1024];
	char phone[1024];
	char address[1024];
}Continfo;


//组织
typedef struct Contbook
{
	Continfo* people;
	int size;  //[0,size)表示有效的通讯录
	int fullsize;
}Contbook;

Contbook g_contbook;//定义一个全局变量

//程序一行一行执行,用到的变量一定要放在定义之后

void init()//初始化操作
{
	g_contbook.size = 0;
	g_contbook.fullsize = 1000;
	g_contbook.people = (Continfo*)malloc(sizeof(Continfo)*g_contbook.fullsize);
	for (int i = 0; i < g_contbook.fullsize; ++i)
	{
		g_contbook.people[i].name[0] = '\0';//.表示结构体成员的访问
		g_contbook.people[i].sex[0] = '\0';
		g_contbook.people[i].age[0] = '\0';
		g_contbook.people[i].phone[0] = '\0';
		g_contbook.people[i].address[0] = '\0';
	}
}

void addconnection()
{
	printf("新增联系人\n");
	if (g_contbook.size > g_contbook.fullsize)
	{
		printf("空间不足!扩容1000!扩容成功!\n");
		g_contbook.fullsize += 1000;
		g_contbook.people = (Continfo*)realloc(g_contbook.people, g_contbook.fullsize*sizeof(Continfo));
	}
	printf("请输入联系人的姓名: ");
	//scanf("%s", g_contbook.people[g_contbook.size].name);
	//防止代码太长,创建一个指针
	//创建一个变量相当于是一份拷贝,是用g_contbook.people[g_contbook.size]的值来初始化
	//这样的修改不会影响到数组中的元素
	Continfo* peopleinfo = &g_contbook.people[g_contbook.size];
	scanf("%s", peopleinfo->name);
	printf("请输入联系人的性别: ");
	scanf("%s", peopleinfo->sex);
	printf("请输入联系人的年龄: ");
	scanf("%s", peopleinfo->age);
	printf("请输入联系人的电话号码: ");
	scanf("%s", peopleinfo->phone);
	printf("请输入联系人的住址: ");
	scanf("%s", peopleinfo->address);
	++g_contbook.size;
	system("cls");
	printf("新增联系人成功!\n");
}

void Printallconnection()
{
	if (g_contbook.size == 0)
	{
		system("cls");
		printf("通讯录里没有任何奇怪的东西!\n");
	}
	else
	{
		system("cls");
		printf("您的所有联系人: \n");
		for (int i = 0; i < g_contbook.size; ++i)
		{
			Continfo* info = &g_contbook.people[i];
			printf("[%d] 姓名:%s\t 性别:%s\t 年龄:%s\t 电话号码:%s\t  住址:%s\t \n",
				i + 1, info->name, info->sex, info->age, info->phone, info->address);
		}
		printf("显示联系人成功!\n");
	}
}

void deleteconnection()
{
	if (g_contbook.size == 0)
	{
		printf("删除失败!您的通讯录比您的脸都干净!\n");
	}
	else
	{
		Printallconnection();
		while (1)
		{
			printf("输入1000取消操作!! ");
			printf("请输入您要删除的联系人的序号: ");
			int num1 = 0;
			scanf("%d", &num1);
			if (num1 == 1000)
			{
				system("cls");
				printf("取消删除成功!\n");
				return;
			}

			else if (num1<1 || num1>g_contbook.size)
			{
				printf("您的输入有误!请看清楚再输!\n");
				continue;
			}

			else
			{
				g_contbook.people[num1 - 1] = g_contbook.people[g_contbook.size - 1];
				--g_contbook.size;
				printf("删除联系人成功!\n");
				return;
			}
		}
	}
}

void findconnection()
{
	if (g_contbook.size == 0)
	{
		printf("查找失败!您的通讯录比您的脸都干净!\n");
	}
	else
	{
		printf("请输入您要查找的联系人姓名: ");
		char name[1024] = { 0 };
		scanf("%s", name);
		for (int i = 0; i < g_contbook.size; ++i)
		{
			Continfo* info = &g_contbook.people[i];
			if (strcmp(info->name, name) == 0)
			{
				printf("[%d] 姓名:%s\t 性别:%s\t 年龄:%s\t 电话号码:%s\t  住址:%s\t \n",
					i + 1, info->name, info->sex, info->age, info->phone, info->address);
				continue;
			}
			else
			{
				system("cls");
				printf("未找到联系人\n");
				return;
			}
		}
		printf("查找联系人成功!\n");
	}
}

void updateconnection()
{
	if (g_contbook.size == 0)
	{
		printf("修改失败!您的通讯录比您的脸都干净!\n");
		return;
	}
	else
	{
		Printallconnection();
		while (1)
		{
			printf("请输入您要修改的联系人的序号: ");
			int num2 = 0;
			scanf("%d", &num2);
			if (num2<1 || num2>g_contbook.size)
			{
				printf("您的输入有误!请看清楚再输!\n");
				continue;
			}
			Continfo* info = &g_contbook.people[num2 - 1];
			printf("输入/表示跳过此项修改!");
			printf("请问(%s)新的名字是: ", info->name);
			char name[1024] = { 0 };
			scanf("%s", name);
			if (strcmp(name, "/") != 0)//如果输入的是空字符串就跳过,说明不修改
			{
				strcpy(info->name, name);
			}
			printf("请问(%s)新的性别是: ", info->sex);
			char sex[1024] = { 0 };
			scanf("%s", sex);
			if (strcmp(sex, "/") != 0)
			{
				strcpy(info->sex, sex);
			}
			printf("请问(%s)新的年龄是: ", info->age);
			char age[1024] = { 0 };
			scanf("%s", age);
			if (strcmp(age, "/") != 0)
			{
				strcpy(info->age, age);
			}
			printf("请问(%s)新的电话号码是: ", info->phone);
			char phone[1024] = { 0 };
			scanf("%s", phone);
			if (strcmp(phone, "/") != 0)
			{
				strcpy(info->phone, phone);
			}
			printf("请问(%s)新的住址是: ", info->address);
			char address[1024] = { 0 };
			scanf("%s", address);
			if (strcmp(address, "/") != 0)
			{
				strcpy(info->address, address);
			}
			printf("修改联系人信息成功!\n");
			return;
		}
	}
}



void emptyconnection()
{
	printf("是否确认清除所有联系人???\n确认输入1,取消输入2!\n");
	int num = 0;
	scanf("%d", &num);
	if (num == 1)
	{
		g_contbook.size = 0;
		printf("清空联系人成功!\n");
		Printallconnection();
	}
	else if (num == 2)
	{
		printf("我就知道你舍不得删掉!");
		return;
	}
	else printf("您的输入有误!是不是不想删!\n");
}


void sortconnection()
{
	//冒泡的方式以字典序进行排序
	if (g_contbook.size == 0)
	{
		system("cls");
		printf("啥都没有!怎么排序!\n");
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
	printf("排序联系人信息成功!\n");
	Printallconnection();
	return;
}

void infowrite()
{	//文件指针变量,文件在读写之前应该先打开文件,在使用结束之后应该关闭文件
	//ANSIC规定使用fopen函数打开文件,fclose关闭文件
	//"wb"含义是为了输出数据打开一个二进制文件,如果指定文件不存在建立一个新文件
	FILE* pf = fopen("connectbook.txt", "wb");
	if (pf == NULL)
	{
		perror("open file for write");
		exit(EXIT_FAILURE);
	}
	//写文件
	int i = 0;
	for (i = 0; i < g_contbook.size; i++)
	{
		//fwite功能是二进制输出,适用于文件
		fwrite(&g_contbook.people[i], sizeof(Continfo), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}

void inforead()
{
	// "rb"表示只读,为了输入数据打开一个已经存在的二进制文件
	FILE* pfread = fopen("connectbook.txt", "rb");
	if (pfread == NULL)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	Continfo temp = { 0 };
	int  i = 0;
	while (fread(&temp, sizeof(Continfo), 1, pfread))// fread表示二进制输入
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
	printf("1. 添加联系人信息\n");
	printf("2. 删除指定联系人信息\n");
	printf("3. 查找指定联系人信息\n");
	printf("4. 修改指定联系人信息\n");
	printf("5. 显示所有联系人信息\n");
	printf("6. 清空所有联系人\n");
	printf("7. 以名字排序所有联系人\n");
	printf("8. 保存联系人到文件\n");
	printf("9. 加载联系人\n");
	printf("0. 退出通讯录\n");
	printf("====================\n");
	printf("请输入您的选择: ");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

typedef void(*Func)();

int main()
{
	Func arr[] =//函数指针数组
	{
		xianyu,
		addconnection,//必须用逗号
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
		if (choice < 0 || choice >= sizeof(arr) / sizeof(arr[0]))//避免以后修改麻烦
		{
			printf("您的输入有误!\n");
			continue;
		}
		if (choice == 0)
		{
			printf("欢迎您下次使用!拜拜!");
			break;
		}
		arr[choice]();
	}
	system("pause");
	return 0;
}