#include<stdio.h>                                                  /*课程表2问题*/
#include<stdlib.h>                                                 /*思路想法，建立图的方法，遍历图，再放到队列中去，从第一级开始连接第二级的课程，每一级的课程 */
#include <string.h>                                                /*之间可以随意上，依次类推第三，四级，用book数组记录是否进入队列，以及记录级数*/


int Class[100][100];                                                /*存图*/
int n;                                                              /*n门课*/

typedef struct queue                                                /*定义队列内容为课程和级数*/
{
	int point;
	int num;
}date;


/*寻找一个数组中按数组值最大的元素*/
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



/*寻找一个数组中按数组值排序，输出排序后的下标*/
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


/*核心算法*/
int  Array(int a)
{
	date p[100];                                                          /*定义队列*/
	int head = 0; int tail = 0;
	p[tail].point = a;
	p[tail].num = 1;                                                       /*从第一级开始*/
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
			if (Class[p[head].point][i] == 1&&p[head].num+1>book[i])    /*当两课程之间有衔接关系时，并且下一级级数应有的级数大于预先的级数时，计入队列，更新预先的book级数*/
			{
				p[tail].point = i;
				p[tail].num = p[head].num + 1;
				tail++;
				book[i] = p[head].num + 1;
			}
		}
		head++;
	}
	for (int i = 0; i < n; ++i)                                        /*检查能否完成所有课程*/
	{
		if (book[i] == 0)
		{
			return 0;
		}
	}
	return print(book);                                                 /*能完成输出*/
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
			printf("输入有误！");
			exit(0);
		}
		if (l == k)
		{
			break;
		}
		Class[k][l] = 1;
	}
	int zhen = 0;
	for (int i = 0; i < n; ++i)                                       /*每一个课程都作为首点（第一级）去测试*/
	{
		if (Array(i)==1)
		{
			zhen = 1;
			break;
		}
	}
	if (zhen == 0)                                                    /*不能完成的操作*/
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