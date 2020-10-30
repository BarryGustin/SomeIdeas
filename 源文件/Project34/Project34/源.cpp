#include <stdio.h>               /*深度优先搜索问题*/
#include <stdlib.h>              /*1.遇到走每一步都有好几种可能是使用*/
#include <string.h>              /*2.用book记录每一步，防止这一步重走一次，甚至无限循环*/
                                 /*3.走每一步时，核心代码是循环每一步的好几种可能，走出某一步用book记录
								 */

int book[51][51];
int p, q, min, j = 0, x, y;
char m[51][51] = { {'#','#','#','#','#','#'},{'#','.','.','#','.','#'},
{'#','.','.','.','.','#'},{'#','.','.','#','.','#'},{'#','.','#','.','.','#'},
{'#','.','.','.','#','#'},{'#','#','#','#','#','#'} };


void dfs(int x, int y, int step)
{
	int next[4][2] = { { 0,1 }, {1,0},{-1,0},{0,-1} };
	int tx, ty;
	int i;
	if (x == p && y == q)
	{
		++j;
		if (j == 1)
		{
			min = step;
		}
		else if(step < min)
		{
			min = step;
			printf("%d\n",min);
		}
		return;
	}
	for (i = 0; i < 4; ++i)
	{
		tx = x + next[i][0];
		ty = y + next[i][1];
		if (m[tx][ty] == '#')
		{
			continue;
		}
		if (book[tx][ty] == 0)
		{
			book[tx][ty] = 1;
			dfs(tx, ty, step + 1);
			book[tx][ty] = 0;
		}
	}
	return;
}



int main(void)
{
	int s,i;
	extern int x, y, p, q;
	extern char m[51][51] ;
	printf("您是否想自行建立地图：\n");
	printf("如果想（选1）\t如果不想（选2）：\n");
	scanf_s("%d",&s);
	if (s == 1)
	{
		int h, z;
		printf("建立地图的规模：\n");
		printf("横\t纵：\n");
		scanf_s("%d%d", &h, &z);
		printf("建立地图（'#'为障碍物，'.'为路）：\n");
		for (i = 0; i < h; ++i)
		{
			scanf_s("%s",m[i],sizeof(m[i]));
		}
	}
	else if (s == 2)
	{
		int h, z;
		for (h = 0; h <= 7; ++h)
		{
			for (z = 0; z <= 6; ++z)
			{
				printf("%c",m[h][z]);
			}
			printf("\n");
		}
	}
	printf("输入起始位置：\n");
	printf("x=");
	scanf_s("%d",&x);
	printf("y=");
	scanf_s("%d", &y);
	printf("输入终止位置：\n");
	printf("p=");
	scanf_s("%d", &p);
	printf("q=");
	scanf_s("%d", &q);
	book[x][y] = 1;
	if (m[p][q] == '#')
	{
		printf("指定到达位置是障碍物哦！！！");
		exit(0);
	}
	dfs(x,y,0);
	if ((x != p || y != q) && min == 0)
	{
		printf("路好像封死了，无法走到指定位置");
	}
	else if (x == p || y == q)
	{
		printf("您要到达的位置就是起始位置哦!!");
	}
	else
	{
		printf("最少需要%d步欧~~~\n", min);
	}
		
}