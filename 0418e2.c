#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ʵ��һ�����������������ַ����е�k���ַ�
// ABCD����һ���ַ��õ�BCDA ABCD���������ַ��õ�CDAB

//�Ƚ�Ҫ�������ַ�������,�����strcatƴ��

void Blodd(char str[],int n)
{
	int size = strlen(str);
	char tmp[1024] = { 0 };
	int i = 0;
	for (; i < n; ++i) 
	{
		tmp[i]= str[i];              //��������ô��ǰ��λ�õ�
	}
	//���ڵ��ַ�������ABCD
	for (i = n; i < size; ++i)
	{
		str[i - n]=str[i];
	}
		strcat(str, tmp);
}


int isBlood(char str1[],char str2[])
{
	int size = strlen(str1) ;
	strncat(str1, str1,size);
	strstr(str1, str2);
	if (strstr(str1, str2) != NULL)
	{
		return 1;
	}
	return 0;
}

//int main()
//{
//	char str1[1024] = "ABCD";
//	char str2[1024] = "CDAB";
		////printf("%s", str);
		//int a=isBlood(str1, str2);
		//if (a == 1)
		//{
		//	printf("�ҵ���");
		//}
		//else
		//{
		//	printf("û�ҵ�");
		//}
//	Blodd(str1, 2);
//	printf("%s", str1);
//	 system("pause");
//	return 0;
//}
// ��ϰ��̬�ڴ濪��
//malloc
//calloc
//realloc
//free
//����

int main()
{
	char* p = (char*)malloc(100 * sizeof(char));
	if (p == NULL)
	{
		exit(EXIT_FAILURE);
	}
	free(p);

	char arr[] = { 0 };
	char* p2 = (char*)calloc(sizeof(arr) / sizeof(arr[0]), sizeof(arr));
	if (p2 == NULL)
	{
		exit(EXIT_FAILURE);
	}
	/*free(p2);*/		//�ͷ�֮��,p2��ΪҰָ��

	p2 = (char*)realloc(p2, 100 * sizeof(arr));
	free(p2);			//Ұָ������ٴ��ͷŻ����ʧ��

	system("pause");
	return 0;
}
