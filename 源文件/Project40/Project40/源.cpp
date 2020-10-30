#include <stdio.h>
#include <stdlib.h>

typedef  struct queue
{
	int x;
	int book[10];
	int top;
}date;

int main(void)
{
	date a[101][101];
	int n, m;
	int i, j, p, d;
	printf("几个城市:\n");
	scanf_s("%d",&n);
	printf("几条路:\n");
	scanf_s("%d",&m);
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			if (i == j)
			{
				a[i][j].x = 0;
				a[i][j].top = 1;
				a[i][j].book[a[i][j].top++] = i;
			}
			else
			{
				a[i][j].x = 99999;
				a[i][j].top = 1;
				a[i][j].book[a[i][j].top++] = i;
				a[i][j].book[a[i][j].top] = j;
			}
		}
	}
	for (p = 1; p <= m; ++p)
	{
		printf("第%d条道路\n",p);
		scanf_s("%d%d%d", &i, &j, &d);
		a[i][j].x = d;
	}
	for (p = 1; p <= n; ++p)
	{
		for (i = 1; i <= n; ++i)
		{
			for (j = 1; j <= n; ++j)
			{
				if (a[i][j].x > a[i][p].x + a[p][j].x)
				{
					a[i][j].x = a[i][p].x + a[p][j].x;
					a[i][j].book[a[i][j].top++] = p;
					a[i][j].book[a[i][j].top] = j;
				}
			}
		}
	}
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			printf("%d  ",a[i][j].x);
		}
		printf("\n");
	}
	printf("需要从哪到哪的最短路径：\n");
	scanf_s("%d %d", &i, &j);
	if (i == j)
	{
		printf("宁就在此处。");
		exit(0);
	}
	printf("最短路径：\n");
	for (p = 1; p <= a[i][j].top; ++p)
	{
		printf("%d  ",a[i][j].book[p]);
	}
	printf("\n路程为:\n%d\n",a[i][j].x);
}
/*
1
2
2

1
3
6

1
4
4

2
3
3

3
1
7

3
4
1

4
1
5

4
3
12
*/
