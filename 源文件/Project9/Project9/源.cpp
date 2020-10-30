#include <stdio.h>
#include <string.h>
int main(void)
{
	char a[80],b[80];
	char* p=a;
	int i,num;
	printf("请输入原文：");
	gets_s(a);
	printf("输出原文：");
	printf("%s\n", a);
	printf("加密......\n输出密码："); 
	num = strlen(a);
	for (i = 0; i < num; i++)
	{
		if (*p >='0' && *p <= '9')
		{
			*p = 105 - *p;
		}
		if (*p >= 'A' && *p <= 'Z')
		{
			*p = 155 - *p;
		}
		if (*p >= 'a' && *p <= 'z')
		{
			*p = 219 - *p;
		}
		p++;
	}
	printf("%s\n",a);
	printf("请输入密码：");
	gets_s(b);
	printf("输出密码：");
	printf("%s\n", b);
	p = b;
	num = strlen(b);
	for (i = 0; i < num; i++)
	{
		if (*p >= '0' && *p <= '9')
		{
			*p = 105 - *p;
		}
		if (*p >= 'A' && *p <= 'Z')
		{
			*p = 155 - *p;
		}
		if (*p >= 'a' && *p <= 'z')
		{
			*p = 219 - *p;
		}
		p++;
	}
	printf("输出原文：");
	printf("%s\n", b);
}
