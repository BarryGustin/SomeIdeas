#include<stdio.h>                     /*再谈最小生成树*/
#include <string.h>                   /*1.用邻接表存图，优化地图可降低时间复杂度*/
#include <stdlib.h>                   /*2.用结构体建立一个堆，优化思路见下*/
#include <math.h>                     /*用邻接表与堆优化，大大降低时间复杂度，最小生成树的最简代码*/


typedef struct queue                   /*建立结构体*/
{                                      /*建立结构体用途是在后面建立结构体数组h[]*/
	int lon;                           /*h[]中的每一个数据存lon指节点top到生成树的距离*/
	int top;                           /*top指未加入生成树的节点*/
}date;


int u[101], v[101], w[101];            /*建立领接表及检测节点是否在生成树中用book[]*/
int first[101] = { -1 }, next[101] = {-1};/*定义堆h[]*/
int book[10];
date h[101];


/*对于堆，作向上调整，对内部变量h[101]作调整*/
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


/*对于堆，作向下调整，直接对外部变量h[101]*/
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
	int dis[101] = {0};               /*dis[]作用是存所有未加入数的点到生成树的距离*/
	int head = 1;
	printf("几个城:");
	scanf_s("%d",&n);
	printf("几条路:");
	scanf_s("%d", &m);
	for (i = 1; i <= 2*n+1; ++i)      /*初始化dis[]*/
	{
		dis[i] = 9999999;
	}
	for (i = 1; i <= m; ++i)                  /*用领接表存图，注意是无向图*/
	{
		printf("第%d条路:\n",i);
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
	for (i = 1; i <= 2 * m; ++i)                      /*初始化堆*/
	{
		h[i].lon = 999999;
	}
	for (i = 1; i <= n - 1; ++i)
	{
		k = first[count];                                 /*用新加入的节点寻找他的出边*/
		//printf("//%d\n", first[count]);
		//printf("%d\n", k);
		while (k != -1)                                   /*寻找出边*/
		{
			//printf("1");
			//printf("%d\n", k);
			if (dis[v[k]] > w[k] && book[v[k]] != 1)      /*如果出边连向的节点未加入数中且连向的点到生成树的距离更短*/
			{
				//printf("1");
				//printf("%d\n", k);
				dis[v[k]] = w[k];                         /*将该出边入堆且更新dis[]数组*/
				h[head].lon = w[k];
				h[head].top = v[k];
				//printf("++%d\n", h[head].top);
				//printf("**%d\n", h[head].lon);
				siftup(head);                             /*有新元素入堆，使其重新成为最小堆*/
				head++;
			}
			///printf("%d\n",k);
			k = next[k];                                  /*再循环寻找下一条出边*/
		}
		count = h[1].top;                      /*寻找完新节点的所有出边后*/
		//printf("++%d\n", h[1].top);          /*将堆中最短的边所连向的节点加入生成树*/
		book[count] = 1;
		sum += h[1].lon;                       /*总路径更新*/
		//printf("*%d\n", h[1].lon);
		head--;                                /*将最短的出边一处堆*/
		h[1] = h[head];                        /*用数组最后一个数据顶替第一个*/
		siftdown2(1, head - 1);                /*向下遍历为最小堆*/
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