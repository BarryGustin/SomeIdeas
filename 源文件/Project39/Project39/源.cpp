#include <stdio.h>          /*寻找城市地图中想要去的地方的路线和最短路线*/
#include <string.h>                  /*深搜*/
#include <stdlib.h>
#include <math.h>


int a[101][101];                 /*定义地图*/
int w[101][101];                 /*图中个地点相距的距离*/
int book[10], minbook[10];       /*记录路径和最短的那个路径*/
int n,m;                          /*一共n个地点*/
int sum = 0, min = 99999999;     /*记录路程和最短路程*/



/*处理该地点*/
void dfs(int x)
{
	int i;
	if (x == 5)                  /*如果到目的地，输出路径，检查是否是最短路径*/
	{
		printf("输出路径:\n");
		for (i = 1; i <= n; ++i)
		{
			if (book[i] == 1)
			{
				printf("%d  ",i);
			}
		}
		printf("\n输出路程:\n");
		printf("%d\n",sum);
		if (sum < min)                     /*如为最短路径，用minbook记录*/
		{
			min = sum;
			for (i = 1; i <= n; ++i)
			{
				minbook[i] = book[i];
			}
		}
	}
	for (i = 1; i <= n; ++i)
	{
		if (book[i] == 1)
		{
			continue;
		}
		if (a[x][i] == 1 && book[i] == 0)/*如果x地与i地间有路，且i地未路过*/
		{
			book[i] = 1;                 /*走到i地*/
			sum += w[x][i];              /*记录路程*/
			dfs(i);                      /*处理i地*/
			sum -= w[x][i];              /*倒退路程*/
			book[i] = 0;                 /*退出i地，准备在上一函数中选择下一路径*/
		}
	}
	return;
}




int main(void)
{
	extern int a[101][101], w[101][101];
	extern int n, m;
	int i, j;
	int b, c, d;
	printf("几个城市：\n");                /*建立地图*/
	scanf_s("%d",&n);
	printf("几条道路：\n");
	scanf_s("%d", &m);
	for (i = 0; i < m; ++i)
	{
		printf("输入第%d条交通道路:\n",i+1);
		scanf_s("%d%d", &b, &c);
		printf("道路距离:\n");
		scanf_s("%d",&d);
		a[b][c] = 1;
		w[b][c] = d;
	}
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			if (i != j && a[i][j] != 1)
			{
				a[i][j] = 2;
			}
		}
	}
	book[1] = 1;                              /*记录初位置*/
	dfs(1);                                   /*处理第一步*/
	printf("路程最少的路径为:\n");
	for (i = 1; i <= n; ++i)
	{
		if (minbook[i] == 1)
		{
			printf("%d  ",i);
		}
	}
	printf("\n最少路程:\n");
	printf("%d\n",min);
}