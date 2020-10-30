#include<stdio.h>                /*最长回文子串（栈的应用）问题，要解决的问题如下：*/
#include <stdlib.h>              /*1.找到可能为回文序列的子串*/
#include<string.h>               /*2.判断找到的序列是否为回文序列*/
                                 /*3.找到最长的回文序列*/
/*判断回文序列*/                 /*思路：*/
int measure(char a[])            /*寻找可疑的序列（利用函数cut_off）*/
{                                /*判断可疑的序列是否为回文序列（利用函数measure）*/
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


/*寻找可疑的序列，筛选最长的回文序列*/
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
				for (i = 0; p + i != q+1; ++i)         /*将可疑的序列放入a[]*/
				{                                      /*准备交给measure判断*/
					a[i] = *(p + i);
				}
				a[i] = '\0';
				len = strlen(c);
				//printf("%s\n",a);
				if (measure(a) && i > len)              /*筛选最长*/
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