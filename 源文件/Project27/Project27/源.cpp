#include <stdio.h>               //������ʽƥ��������Ҫ���������
#include <string.h>              //1���������Ϊ�����⣬��ѡ��ķ�ʽ����
#include <stdlib.h>              //2������������������    3�����s�ַ����޷�ƥ��p�ַ������⣨�������⣩       
#include <conio.h>               //4�����sΪ�ն�p��Ϊ�յ�����  5�����'.'��'*'�ŵ��������⣨�����㷨��   
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
	if (!(i - 1))                        //�����û�ѡ��ķ�ʽ���о���s�Ƿ�Ϊ��
	{
		printf("please input a string s:\n");
		scanf_s("%s", s, sizeof(s));
	}
	system("cls");
	m = s;
	j = strlen(s);
	for (i = 0; i < j; ++i, ++m)
	{
		if (*m < 'a' || *m>'z')              //�涨�Ϸ��ַ�����ֹ����
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
	if (!(i - 1))                     //�����û�ѡ��ķ�ʽ���о���p�Ƿ�Ϊ��
	{
		printf("please input a string p:\n");
		scanf_s("%s", p, sizeof(p));
	}
	system("cls");
	n = p;
	j = strlen(p);
	for (i = 0; i < j; ++i, ++n)
	{
		if (*n >= 'a' && *n <= 'z' || *n == '.' || *n == '*');  //�涨�Ϸ��ַ�����ֹ����
		else 
		{
			printf("input error,press any key to quit....\n");
			exit(0);
		}
	}
	*n = '\0';
	i = strlen(s);
	j = strlen(p);
	if (i > j)                          //���s�ַ����޷�ƥ��p�ַ������⣨�������⣩
	{
		printf("false\n");
		exit(0);
	}
	if (*s == '\0'&& *p != '\0')        //���sΪ�ն�p��Ϊ�յ����� 
	{
		printf("false\n");
		exit(0);
	}
	m = s;
	n = p;
	if (*n == NULL && *m == NULL)            //���s��p��Ϊ�յ�����
	{
		printf("ture\n");
		exit(0);
	}
	for (n=p; *n != '\0'; ++n)                 //�����㷨
	{
		switch (*n)                            //��switch��������
		{                                      //��Ϊ'.'����ܴ����κΣ�ֱ��m��ǰ��
		case '.': ++m; break;                  //��Ϊ'*'��n��ǰһ����ȵ�����£�����*m�Ƿ����*n,����mֻҪ�����n����ǰ����
		case'*':for (*n = *(n - 1); *n == *m; ++m); break;
		default:if (*m == *n)                  //��Ϊ��ĸ���ж��Ƿ���ȣ����m��ǰ��
		{                                      //����m�ص�s�Ŀ�ͷ��׼��������s�ַ�����p�в���
			++m;
		}
			   else
		{
			m = s;
		}break;
		}
		if (*m == '\0')break;                  //��p��һ��������s�������������������mת����
	}
	if (*m == '\0')                            //����������
	{
		printf("ture\n");
	}
	else
	{
		printf("false\n");
	}
}