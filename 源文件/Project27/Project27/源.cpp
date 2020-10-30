#include <stdio.h>               //正则表达式匹配问题需要解决的问题
#include <string.h>              //1、解决输入为空问题，以选择的方式进行
#include <stdlib.h>              //2、解决输入的乱输问题    3、解决s字符串无法匹配p字符串问题（长度问题）       
#include <conio.h>               //4、解决s为空而p不为空的问题  5、解决'.'与'*'号的引入问题（核心算法）   
int main(void)                   
{
	int i,j;
	char a;
	char s[100] = { NULL };
	char p[100] = { NULL };
	char* m, * n;
	printf("if you want to input a string 's',if you want,you can choose 1,or you can choose 2:\n");
	printf("1:input    2:break\n");
	scanf_s("%d", &i);
	system("cls");
	if (!(i - 1))                        //构建用户选择的方式进行决定s是否为空
	{
		printf("please input a string s:\n");
		scanf_s("%s", s, sizeof(s));
	}
	system("cls");
	m = s;
	j = strlen(s);
	for (i = 0; i < j; ++i, ++m)
	{
		if (*m < 'a' || *m>'z')              //规定合法字符，防止乱输
		{
			printf("input error,press any key to quit....\n");
			exit(0);
		}
	}
	*m = '\0';
	printf("if you want to input a string 'p',if you want,you can choose 1,or you can choose 2:\n");
	printf("1:input    2:break\n");
	scanf_s("%d", &i);
	system("cls");
	if (!(i - 1))                     //构建用户选择的方式进行决定p是否为空
	{
		printf("please input a string p:\n");
		scanf_s("%s", p, sizeof(p));
	}
	system("cls");
	n = p;
	j = strlen(p);
	for (i = 0; i < j; ++i, ++n)
	{
		if (*n >= 'a' && *n <= 'z' || *n == '.' || *n == '*');  //规定合法字符，防止乱输
		else 
		{
			printf("input error,press any key to quit....\n");
			exit(0);
		}
	}
	*n = '\0';
	i = strlen(s);
	j = strlen(p);
	if (i > j)                          //解决s字符串无法匹配p字符串问题（长度问题）
	{
		printf("false\n");
		exit(0);
	}
	if (*s == '\0'&& *p != '\0')        //解决s为空而p不为空的问题 
	{
		printf("false\n");
		exit(0);
	}
	m = s;
	n = p;
	if (*n == NULL && *m == NULL)            //解决s和p都为空的问题
	{
		printf("ture\n");
		exit(0);
	}
	for (n=p; *n != '\0'; ++n)                 //核心算法
	{
		switch (*n)                            //用switch分类讨论
		{                                      //如为'.'则点能代替任何，直接m向前移
		case '.': ++m; break;                  //如为'*'则n与前一个相等的情况下，查找*m是否等于*n,并将m只要相等于n便向前滚动
		case'*':for (*n = *(n - 1); *n == *m; ++m); break;
		default:if (*m == *n)                  //如为字母则判断是否相等，相等m向前滚
		{                                      //否则m回到s的开头，准备重新让s字符串在p中查找
			++m;
		}
			   else
		{
			m = s;
		}break;
		}
		if (*m == '\0')break;                  //在p中一旦遍历完s立即跳出，以免出错，将m转超了
	}
	if (*m == '\0')                            //解决最后的输出
	{
		printf("ture\n");
	}
	else
	{
		printf("false\n");
	}
}