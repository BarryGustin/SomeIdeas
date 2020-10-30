#include<stdio.h>                                                  /*�γ̱�2����*/
#include<stdlib.h>                                                 /*˼·�뷨������ͼ�ķ���������ͼ���ٷŵ�������ȥ���ӵ�һ����ʼ���ӵڶ����Ŀγ̣�ÿһ���Ŀγ� */
#include <string.h>                                                /*֮����������ϣ��������Ƶ������ļ�����book�����¼�Ƿ������У��Լ���¼����*/


int Class[100][100];                                                /*��ͼ*/
int n;                                                              /*n�ſ�*/

typedef struct queue                                                /*�����������Ϊ�γ̺ͼ���*/
{
	int point;
	int num;
}date;


/*Ѱ��һ�������а�����ֵ����Ԫ��*/
int Max(int a[])
{
	int Max=0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > Max)
		{
			Max = a[i];
		}
	}
	return Max;
}



/*Ѱ��һ�������а�����ֵ��������������±�*/
int  print(int a[])
{
	int max = Max(a);
	printf("[");
	for (int i = 1; i <=max; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(a[j]==i)
			{ 
				printf("%d,",j);
			}
		}
	}
	printf("\b]\n");
	return 1;
}


/*�����㷨*/
int  Array(int a)
{
	date p[100];                                                          /*�������*/
	int head = 0; int tail = 0;
	p[tail].point = a;
	p[tail].num = 1;                                                       /*�ӵ�һ����ʼ*/
	tail++;
	int book[100];
	for (int i = 0; i <= n; ++i)
	{
		book[i] = 0;
	}
	book[a] = 1;
	while (head != tail)
	{
		for (int i = 0; i < n; ++i)
		{
			if (Class[p[head].point][i] == 1&&p[head].num+1>book[i])    /*�����γ�֮�����νӹ�ϵʱ��������һ������Ӧ�еļ�������Ԥ�ȵļ���ʱ��������У�����Ԥ�ȵ�book����*/
			{
				p[tail].point = i;
				p[tail].num = p[head].num + 1;
				tail++;
				book[i] = p[head].num + 1;
			}
		}
		head++;
	}
	for (int i = 0; i < n; ++i)                                        /*����ܷ�������пγ�*/
	{
		if (book[i] == 0)
		{
			return 0;
		}
	}
	return print(book);                                                 /*��������*/
}


int main(void)
{
	extern int n;
	scanf_s("%d",&n);
	for (int i = 0; ; ++i)
	{
		int l, k;
		scanf_s("%d%d",&l,&k);
		if (l >= n || k >= n)
		{
			printf("��������");
			exit(0);
		}
		if (l == k)
		{
			break;
		}
		Class[k][l] = 1;
	}
	int zhen = 0;
	for (int i = 0; i < n; ++i)                                       /*ÿһ���γ̶���Ϊ�׵㣨��һ����ȥ����*/
	{
		if (Array(i)==1)
		{
			zhen = 1;
			break;
		}
	}
	if (zhen == 0)                                                    /*������ɵĲ���*/
	{
		printf("[ ]\n");
	}
}


/*
8
1 0 
2 0 
3 1 
4 1 
3 2 
4 3 
5 3
6 0 
7 6
3 6 
3 7 
0 0
*/