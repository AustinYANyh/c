#include <stdio.h>
#include <string.h>
#include <assert.h>
char* Strstr(const char* str1, const char* str2)
{
	assert(*str1 != NULL);//�����Ϸ���У��
	assert(*str2 != NULL);
	if (*str2 == '\0')
	{
		return NULL;
	}
	char* chazhao_ptr = str1;//��¼�����ַ���λ��
	
	//�����ַ�������'\0',˵��������
	while (*chazhao_ptr != '\0')
		
	{   
		char* panduan_ptr = chazhao_ptr;
     	char* zichuan_ptr = str2;                                                   //��֤����ָ�붼��Ч
		while (*panduan_ptr == *zichuan_ptr&& *panduan_ptr != '\0'&&zichuan_ptr != '\0')

		{
			++panduan_ptr;
			++zichuan_ptr;
		}//�е�һλ��ͬ,����ͬʱ����,�����Ƚ�
		if (*zichuan_ptr == '\0')//˵���ҵ���
		{
			return chazhao_ptr;	
		}
		++chazhao_ptr;//û�ҵ�,�����ַ������Ƽ�����	
	}
	return NULL;
}
int main()
{
	char str1[] = "aaabcdef";
	char str2[] = "bcd";
	int ret=Strstr(str1,str2);
	printf("%p\n", str1);
	printf("%p\n", ret);
	system("pause");
}