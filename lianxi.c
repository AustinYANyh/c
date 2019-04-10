#include <stdio.h>
#include <string.h>
#include <assert.h>
//int main(){
//	              //0x100  0x200  0x300 
//	char * a[] = { "WORK", "AT", "ALIBABA" };
//	char **pa = a;
//	pa++;
//	printf("%s\n", *pa);


char* Strcpy(char *dest, const char *src)
{
	assert(*src != '\0');
	int i = 0;
	for (; dest[i] != '\0'; ++i)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
}
int Strcmp(const char* str1, const char* str2)
{
	assert(*str1 != '\0');
	assert(*str2 != '\0');
	for (int i = 0; str1[i] != '\0'&&str2[i] != '\0'; ++i)
	
	{
		if (str1[i]<str2[i])
		{
			return -1;
		}
		else if (str1[i]>str2[i])
		{
			return 1;
		}
		else
		{

		}

	}
		
}
int main(){
	char a[] = "bbbbbbbbb";
	char b[] = "bbbb";
	int ret=Strcmp(a, b);
	if (ret > 0)
	{
		printf("a>b\n");
	}
	else if (ret < 0)
	{
		printf("a<b\n");
	}
	else printf("a=b\n");
	system("pause");
}