#include<stdio.h>                /*������Ӵ���ջ��Ӧ�ã����⣬Ҫ������������£�*/
#include <stdlib.h>              /*1.�ҵ�����Ϊ�������е��Ӵ�*/
#include<string.h>               /*2.�ж��ҵ��������Ƿ�Ϊ��������*/
                                 /*3.�ҵ���Ļ�������*/
/*�жϻ�������*/                 /*˼·��*/
int measure(char a[])            /*Ѱ�ҿ��ɵ����У����ú���cut_off��*/
{                                /*�жϿ��ɵ������Ƿ�Ϊ�������У����ú���measure��*/
	char b[1000] = { NULL };
	int len, i, mid, next, top;
	len = strlen(a);
	mid = len / 2 - 1;
	top = 0;
	for (i = 0; i <= mid; ++i)
	{
		b[++top] = a[i];  
	}
	if (!(len % 2))
	{
		next = mid + 1;
	}
	else
	{
		next = mid + 2;
	}
	for (i = next; i <len; ++i)
	{
		//printf("%d\n",top);
		if (b[top] != a[i])
			break;
		--top;
	}
	if (!top)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


/*Ѱ�ҿ��ɵ����У�ɸѡ��Ļ�������*/
char c[1000] = { NULL };
char* cut_off(char s[])
{
	char* p, * q;
	int i=0, len,j;
	char a[1000];
	for (p = s; *p != '\0'; ++p)
	{
		for (q = p; *q != '\0'; ++q)
		{
			if (*p == *q)
			{
				for (i = 0; p + i != q+1; ++i)         /*�����ɵ����з���a[]*/
				{                                      /*׼������measure�ж�*/
					a[i] = *(p + i);
				}
				a[i] = '\0';
				len = strlen(c);
				//printf("%s\n",a);
				if (measure(a) && i > len)              /*ɸѡ�*/
				{
					//printf("%d\n", measure(a));
					for (j = 0; j < i; ++j)
					{
						c[j] = a[j];
					}
					c[j] = '\0';
				}
			}
		}
	}
	return c;
}


int main(void)
{
	char s[1000];
	printf("please input a string:\n");
	scanf_s("%s",s,sizeof(s));
	s[sizeof(s) - 1] = '\0';
	printf("%s\n", cut_off(s));
}