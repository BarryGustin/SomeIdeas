#include<stdio.h>             /*用广度搜索的方法寻找炸弹炸死人最多的点*/
#include <string.h>
#include <stdlib.h>
#include <math.h>




typedef struct quene
{
	int x;
	int y;
}date;

char a[51][51] = { {'#','#','#','#','#','#'},{'#','.','.','#','.','#'},
{'#','.','.','.','.','#'},{'#','.','.','#','.','#'},{'#','.','#','.','.','#'},
{'#','.','.','.','#','#'},{'#','#','#','#','#','#'} };
char book[51][51];
int x, y;
int head = 1, tail = 1;
date que[2025];


/*搜索炸死的人数*/
int find(int x, int y)
{
	int boom = 0;
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	int i, tx, ty;
	for (i = 0; i < 4; ++i)
	{
		//printf("%d\n", boom);
		tx = x;
		ty = y;
		while (a[tx][ty] != '#')
		{
			
			tx = tx + next[i][0];
			ty = ty + next[i][1];
			//printf("%d,%d\n", tx, ty);
			if (a[tx][ty] == 'g')
			{

				boom++;
			}
		}
	}//printf("  %d", boom);
	//printf("(%d,%d)\n", x, y);
	return boom;
}


/*用广度搜索的方法遍历图中可以放炸弹的点*/
int dfs(int x, int y)
{
	int f = 0, i;
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	int boom1 = 0, boom = 0;
	int tx, ty;
	tx = que[tail].x;
	ty = que[tail].y;
	boom1 = find(tx, ty);
	//printf("%d\n", boom1);
	if (boom1 >= boom)
	{
		boom = boom1;
		f = tail;
	}
	while (head <= tail)
	{
		for (i = 0; i < 4; ++i)
		{
			tx = que[head].x + next[i][0];
			ty = que[head].y + next[i][1];
			if ((a[tx][ty] == 'g' || a[tx][ty] == '#') || book[tx][ty] == 1)
			{
				continue;
			}
			if (book[tx][ty] == 0)
			{
				//printf("%c\n%d,%d\n%c", a[tx][ty],tx,ty,a[4][4]);
				
				book[tx][ty] = 1;
				tail++;
				que[tail].x = tx;
				que[tail].y = ty;//printf("(%d,%d)\n", tx, ty);
			}
			boom1 = find(tx, ty);
			
			if (boom1 >= boom)
			{
				//printf("     %d",boom1);
				boom = boom1;
				f = tail;
				//printf("(%d,%d)\n", que[f].x, que[f].y);
				//printf("%d\n", f);
			}
		}
		head++;
	}
	return f;
}




int main(void)
{
	extern int x, y, q, p;
	int s, i;
	extern char a[51][51];
	printf("您是否想自行建立地图：\n");
	printf("如果想（选1）\t如果不想（选2）：\n");
	scanf_s("%d", &s);
	if (s == 1)
	{
		int h, z;
		printf("建立地图的规模：\n");
		printf("横\t纵：\n");
		scanf_s("%d%d", &h, &z);
		printf("建立地图（'#'为障碍物，'.'为路,'g'为炸弹）：\n");
		for (i = 0; i < h; ++i)
		{
			scanf_s("%s", a[i], sizeof(a[i]));
		}
	}
	else if (s == 2)
	{
		int h, z;
		for (h = 0; h <= 7; ++h)
		{
			for (z = 0; z <= 6; ++z)
			{
				printf("%c", a[h][z]);
			}
			printf("\n");
		}
	}
	/*for (i = 0; i < h; i++)
	{
		for (s = 0; s < z; ++s)
		{
			printf("%c", a[i][s]);
		}
		printf("\n");
	}*/
	printf("输入起始位置：\n");
	printf("x=");
	scanf_s("%d", &x);
	printf("y=");
	scanf_s("%d", &y);
	/*printf("输入终止位置：\n");
	printf("p=");
	scanf_s("%d", &p);
	printf("q=");
	scanf_s("%d", &q);*/
	que[head].x = x;
	que[head].y = y;
	book[x][y] = 1;
	//printf("%c\n",a[4][4]);
	i=dfs(x, y);
	printf("(%d,%d)\n", que[i].x, que[i].y);
}






/*
#############
#gg.ggg#ggg.#
###.#g#g#g#g#
#.......#..g#
#g#.###.#g#g#
#gg.ggg.#.gg#
#g#.#g#.#.#.#
##g...g.....#
#g#.#g###.#g#
#...g#ggg.gg#
#g#.#g#g#.#g#
#gg.ggg#g.gg#
#############
*/




 /*
typedef struct note
{
	int x;
	int y;
	int f;
	int step;
}date;
int p, q, min, j = 0, x, y;
char book[51][51];
char m[51][51] = { {'#','#','#','#','#','#'},{'#','.','.','#','.','#'},
{'#','.','.','.','.','#'},{'#','.','.','#','.','#'},{'#','.','#','.','.','#'},
{'#','.','.','.','#','#'},{'#','#','#','#','#','#'} };
date que[2501];
int head=1;
int tail=1;


void dfs(int x,int y)
{
	int next[4][2] = { { 0,1 }, {1,0},{-1,0},{0,-1} };
	int tx, ty;
	int i;
	que[head].x = x;
	que[head].y = y;
	while (head <= tail)
	{
		for (i = 0; i < 4; ++i)
		{
			tx = que[head].x + next[i][0];
			ty = que[head].y + next[i][1];
			if (que[tail].x == p && que[tail].y == q)
			{
				//printf("%d\n", min);
				j = 1;
				min = que[tail].step;
				break;
			}
			if (m[tx][ty] == '#')
			{
				continue;
			}
			else if (book[tx][ty] == 0)
			{
				tail++;
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].f = head;
				que[tail].step = que[head].step + 1;
				//printf("%d\n", que[tail].step);
			}
		}
		if (j == 1)
		{
			break;
		}
		//printf("%d\n", min);
		head++;
	}
	return;
}




int main(void)
{
	int s, i;
	extern int x, y, p, q;
	extern char m[51][51];
	printf("您是否想自行建立地图：\n");
	printf("如果想（选1）\t如果不想（选2）：\n");
	scanf_s("%d", &s);
	if (s == 1)
	{
		int h, z;
		printf("建立地图的规模：\n");
		printf("横\t纵：\n");
		scanf_s("%d%d", &h, &z);
		printf("建立地图（'#'为障碍物，'.'为路）：\n");
		for (i = 0; i < h; ++i)
		{
			scanf_s("%s", m[i], sizeof(m[i]));
		}
	}
	else if (s == 2)
	{
		int h, z;
		for (h = 0; h <= 7; ++h)
		{
			for (z = 0; z <= 6; ++z)
			{
				printf("%c", m[h][z]);
			}
			printf("\n");
		}
	}
	printf("输入起始位置：\n");
	printf("x=");
	scanf_s("%d", &x);
	printf("y=");
	scanf_s("%d", &y);
	printf("输入终止位置：\n");
	printf("p=");
	scanf_s("%d", &p);
	printf("q=");
	scanf_s("%d", &q);
	book[x][y] = 1;
	que[head].f = 0;
	que[head].step = 0;
	dfs(x,y);
	printf("\n%d\n",min);
	int f[100];
	for (i = 0; tail!=1; ++i)
	{
		f[i] = tail;
		//printf("%d,%d<-",que[tail].x,que[tail].y);
		tail = que[tail].f;
		printf("%d\n",tail);
	 }
	f[i] = tail;
	for (; i != 0; --i)
	{
		printf("(%d,%d)->", que[f[i]].x, que[f[i]].y);
	}
	printf("(%d,%d)\n", que[f[i]].x, que[f[i]].y);
}*/