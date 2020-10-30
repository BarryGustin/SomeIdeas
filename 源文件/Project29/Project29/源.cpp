#include <stdio.h>               //解决无重复字符的最长子串问题
#include <stdlib.h>              //1.扫描字符串，解决重复字符问题。
#include <string.h>              //2.解决相邻的字符重复的问题
int main(void)
{
	char a[100];
	char* p, * q, * m, * n;
	int i, j;
	printf("please input a string:\n");
	scanf_s("%s",a,sizeof(a));
	a[sizeof(a)-1] = '\0';
	p = q = m = n = a;
	i = j = 1;
	while (*(++p) != '\0')           //扫描字符串
	{
		if (*p != *q)                //相邻的字符串不相等，进行接下来的处理
		{
			i = 1;                   //计数
			m = n;
			while (m != p)           //用m扫描这一串相邻俩个字符都不同的字符串
			{
				if (*(m++) != *p)    //与新进入字符串的字符不一样时，计数
				{
					++i;
				}
				else                 //一样时将字符串头拉到该位置
					n = p;
			}
		}
		else                        //相邻两个字符一样时处理
		{
			if (i > j)
				j = i;
			i = 1;
			n = p;
		}
		if (i > j)                  //每次循环结束时的处理，取最大的数，意味着最长
			j = i;
		q = p;
	}
	printf("%d\n",j);
}