#include<stdio.h>                     /*��̸��С������*/
#include <string.h>                   /*1.���ڽӱ��ͼ���Ż���ͼ�ɽ���ʱ�临�Ӷ�*/
#include <stdlib.h>                   /*2.�ýṹ�彨��һ���ѣ��Ż�˼·����*/
#include <math.h>                     /*���ڽӱ�����Ż�����󽵵�ʱ�临�Ӷȣ���С��������������*/


typedef struct queue                   /*�����ṹ��*/
{                                      /*�����ṹ����;���ں��潨���ṹ������h[]*/
	int lon;                           /*h[]�е�ÿһ�����ݴ�lonָ�ڵ�top���������ľ���*/
	int top;                           /*topָδ�����������Ľڵ�*/
}date;


int u[101], v[101], w[101];            /*������ӱ����ڵ��Ƿ�������������book[]*/
int first[101] = { -1 }, next[101] = {-1};/*�����h[]*/
int book[10];
date h[101];


/*���ڶѣ������ϵ��������ڲ�����h[101]������*/
void siftup(int n)
{
	int i = n, flag = 0, j;
	while (i >= 1 && flag == 0)
	{
		if (h[i].lon < h[i / 2].lon && i / 2 >= 1)
		{
			j = i / 2;
			date t;
			t = h[i];
			h[i] = h[i / 2];
			h[i / 2] = t;
			i = j;
		}
		else
		{
			flag = 1;
		}
	}
	return ;
}


/*���ڶѣ������µ�����ֱ�Ӷ��ⲿ����h[101]*/
void siftdown2(int x, int num)
{
	int n = num, flag = 0;
	int i, j;
	j = x;
	while (j <= n && flag == 0)
	{
		if (h[j].lon > h[2 * j].lon && 2 * j <= n)
		{
			i = 2 * j;
		}
		else
		{
			i = j;
		}
		if (h[i].lon > h[2 * j + 1].lon && 2 * j + 1 <= n)
		{
			i = 2 * j + 1;
		}
		if (i != j)
		{
			date t;
			t = h[i];
			h[i] = h[j];
			h[j] = t;
			j = i;
		}
		else
		{
			flag = 1;
		}
	}
	return;
}



int main(void)
{
	int n, m, i, j, k;
	int count = 0, sum = 0;
	int dis[101] = {0};               /*dis[]�����Ǵ�����δ�������ĵ㵽�������ľ���*/
	int head = 1;
	printf("������:");
	scanf_s("%d",&n);
	printf("����·:");
	scanf_s("%d", &m);
	for (i = 1; i <= 2*n+1; ++i)      /*��ʼ��dis[]*/
	{
		dis[i] = 9999999;
	}
	for (i = 1; i <= m; ++i)                  /*����ӱ��ͼ��ע��������ͼ*/
	{
		printf("��%d��·:\n",i);
		scanf_s("%d%d%d", &u[i], &v[i], &w[i]);
		u[m + i] = v[i];
		v[m + i] = u[i];
		w[m + i] = w[i];
		next[i] = first[u[i]];
		first[u[i]] = i;
		//printf("++%d\n", first[u[i]]);
		next[m + i] = first[u[m + i]];
		first[u[m + i]] = m + i;
		//printf("**%d\n", first[u[m + i]]);
	}
	book[1] = 1;
	count = 1;
	for (i = 1; i <= 2 * m; ++i)                      /*��ʼ����*/
	{
		h[i].lon = 999999;
	}
	for (i = 1; i <= n - 1; ++i)
	{
		k = first[count];                                 /*���¼���Ľڵ�Ѱ�����ĳ���*/
		//printf("//%d\n", first[count]);
		//printf("%d\n", k);
		while (k != -1)                                   /*Ѱ�ҳ���*/
		{
			//printf("1");
			//printf("%d\n", k);
			if (dis[v[k]] > w[k] && book[v[k]] != 1)      /*�����������Ľڵ�δ��������������ĵ㵽�������ľ������*/
			{
				//printf("1");
				//printf("%d\n", k);
				dis[v[k]] = w[k];                         /*���ó�������Ҹ���dis[]����*/
				h[head].lon = w[k];
				h[head].top = v[k];
				//printf("++%d\n", h[head].top);
				//printf("**%d\n", h[head].lon);
				siftup(head);                             /*����Ԫ����ѣ�ʹ�����³�Ϊ��С��*/
				head++;
			}
			///printf("%d\n",k);
			k = next[k];                                  /*��ѭ��Ѱ����һ������*/
		}
		count = h[1].top;                      /*Ѱ�����½ڵ�����г��ߺ�*/
		//printf("++%d\n", h[1].top);          /*��������̵ı�������Ľڵ����������*/
		book[count] = 1;
		sum += h[1].lon;                       /*��·������*/
		//printf("*%d\n", h[1].lon);
		head--;                                /*����̵ĳ���һ����*/
		h[1] = h[head];                        /*���������һ�����ݶ����һ��*/
		siftdown2(1, head - 1);                /*���±���Ϊ��С��*/
	}
	printf("\n\n%d  ",sum);
}







/*
6
9
2
4
11
3
5
13
4
6
3
5
6
4
2
3
6
4
5
7
1
2
1
3
4
9
1
3
2





++9        
**18
//9
9
19
19
++3
**2
17
17
++2
**1
10
10
++0
**0
//-1
-1
//16
16
116
15
11
11
++4
**11
10
//18
18
118
18
18
++4
**9
114
12
12
++5
**13
10
//17
17
117
16
16
++5
**7
13
13
++6
**3
110
10
*/