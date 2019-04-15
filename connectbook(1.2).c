#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
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

#define max_continfo_size 1000

//描述
typedef struct Continfo
{
	char name[1024];
	//性别  采用列举?
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

//组织
typedef struct Contbook
{
	Continfo people[max_continfo_size];
	int size;  //[0,size)表示有效的通讯录
}Contbook;

Contbook g_contbook;//定义一个全局变量

//程序一行一行执行,用到的变量一定要放在定义之后

void init()//初始化操作
{
	g_contbook.size = 0;
	for (int i = 0; i < max_continfo_size; ++i)
	{
		g_contbook.people[i].name[0] = '\0';//.表示结构体成员的访问
		g_contbook.people[i].name[0] = '\0';
		g_contbook.people[i].age[0] = '\0';
		g_contbook.people[i].phone[0] = '\0';
		g_contbook.people[i].address[0] = '\0';
	}
}

void addconnection()
{
	printf("新增联系人\n");
	if (g_contbook.size > max_continfo_size)
	{
		printf("新增联系人失败啦!快去删掉几个!\n");
	}
	printf("请输入联系人的姓名: ");
	//scanf("%s", g_contbook.people[g_contbook.size].name);
	//防止代码太长,创建一个指针
	//创建一个变量相当于是一份拷贝,是用g_contbook.people[g_contbook.size]的值来初始化
	//这样的修改不会影响到数组中的元素
	Continfo* peopleinfo = &g_contbook.people[g_contbook.size];
	scanf("%s", peopleinfo->name);
	//printf("数字1代表男性,数字2代表女性,数字3代表保密! ");
	//printf("请输入联系人的性别: ");
	//scanf("%d", g_contbook.people[g_contbook.size].sex);
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

void deleteconnection()
{
	printf("删除联系人成功!\n");
}

void findconnection()
{
	printf("查找联系人成功!\n");
}

void updateconnection()
{
	printf("修改联系人信息成功!\n");
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
		int i = 0;
		printf("您的%d条联系人: \n",i+1);
		for (; i < g_contbook.size; ++i)
		{
			Continfo* info = &g_contbook.people[i];
			printf("[%d] %s\t%s\t%s\t%s\t \n", i+1,info->name, info->age, info->phone, info->address);
		}
		printf("显示联系人成功!\n");
	}
}

void emptyconnection()
{
	printf("是否确认清除所有联系人???!\n");
		printf("清空联系人成功!\n");
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
		
	};

	while (1)
	{
		int choice = menu();
		if (choice < 0 || choice >= sizeof(arr)/sizeof(arr[0]))//避免以后修改麻烦
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