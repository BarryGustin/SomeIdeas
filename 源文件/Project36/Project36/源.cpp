#include<stdio.h>                 /*用深度搜索的方法求图中的炸弹炸死的最多的位置*/
#include <string.h>
#include <stdlib.h>
#include <math.h>


int x, y;
char a[51][51] = { {'#','#','#','#','#','#'},{'#','.','.','#','.','#'},
{'#','.','.','.','.','#'},{'#','.','.','#','.','#'},{'#','.','#','.','.','#'},
{'#','.','.','.','#','#'},{'#','#','#','#','#','#'} };
int book[51][51];
int maxx, maxy;
int boom1=0, boom=0;


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


/*用深度搜索的方法遍历图中可以放炸弹的点*/
void dfs(int x, int y)
{
	int i;
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	int tx, ty;
	boom1 = find(x, y);
	if (boom1 > boom)
	{
		boom = boom1;
		maxx = x;
		maxy = y;//printf("(%d,%d)\n", maxx, maxy);
	}
	for (i = 0; i < 4; ++i)
	{
		tx = x + next[i][0];
		ty = y + next[i][1];
		if (a[tx][ty] == 'g' || a[tx][ty] == '#' || book[tx][ty] == 1)
		{
			continue;
		}
		if (book[tx][ty] == 0)
		{
			book[tx][ty] = 1;
			dfs(tx, ty);
			book[tx][ty] = 0;
		}
	}
	return;
}




int main(void)
{
	extern int x, y;
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
	book[x][y] = 1;
	//printf("%c\n",a[4][4]);
	dfs(x, y);
	printf("(%d,%d)\n", maxx, maxy);
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

