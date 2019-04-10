#include <stdio.h>
#include <string.h>
#include <assert.h>
char* Strstr(const char* str1, const char* str2)
{
	assert(*str1 != NULL);//参数合法化校验
	assert(*str2 != NULL);
	if (*str2 == '\0')
	{
		return NULL;
	}
	char* chazhao_ptr = str1;//记录被查字符串位置
	
	//被查字符串遇到'\0',说明找完了
	while (*chazhao_ptr != '\0')
		
	{   
		char* panduan_ptr = chazhao_ptr;
     	char* zichuan_ptr = str2;                                                   //保证两个指针都有效
		while (*panduan_ptr == *zichuan_ptr&& *panduan_ptr != '\0'&&zichuan_ptr != '\0')

		{
			++panduan_ptr;
			++zichuan_ptr;
		}//有第一位相同,两者同时后移,继续比较
		if (*zichuan_ptr == '\0')//说明找到了
		{
			return chazhao_ptr;	
		}
		++chazhao_ptr;//没找到,被查字符串后移继续找	
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