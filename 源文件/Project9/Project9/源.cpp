#include <stdio.h>
#include <string.h>
int main(void)
{
	char a[80],b[80];
	char* p=a;
	int i,num;
	printf("������ԭ�ģ�");
	gets_s(a);
	printf("���ԭ�ģ�");
	printf("%s\n", a);
	printf("����......\n������룺"); 
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
	printf("���������룺");
	gets_s(b);
	printf("������룺");
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
	printf("���ԭ�ģ�");
	printf("%s\n", b);
}
