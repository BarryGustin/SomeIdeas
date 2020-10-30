#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>




int a[11][11] = { {0,0,0,0,0,0,0,0,0,0,0},{0,1,2,1,0,0,0,0,0,2,3},{0,3,0,2,0,1,2,1,0,1,2}
,{0,4,0,1,0,1,2,3,2,0,1},{0,3,2,0,0,0,1,2,4,0,0},{0,0,0,0,0,0,0,1,5,3,0},{0,0,1,2,1,0,1,5,4,3,0}
,{0,0,1,2,3,1,3,6,2,1,0},{0,0,0,3,4,8,9,7,5,0,0},{0,0,0,0,3,7,8,6,0,1,2},{0,0,0,0,0,0,0,0,0,1,0} };
int book[11][11];
int m[11][11];
int x, y;
int num = 0;




void dfs(int x, int y,int num)
{
	int tx, ty;
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	int i;
	for (i = 0; i < 4; ++i)
	{
		tx = x + next[i][0];
		ty = y + next[i][1];
		if (a[tx][ty] == 0 || book[tx][ty] == num)
		{
			continue;
		}
		if (book[tx][ty] == 0)
		{
			
			book[tx][ty] = num;
			dfs(tx, ty,num);
			
		}
	}
	return;
}




int main(void)
{
	extern int a[11][11];
	extern int x, y;
	int h, z;
	printf("显示地图:\n");
	for (h = 0; h < 11; ++h)
	{
		for (z = 0; z < 11; ++z)
		{
			printf("%d",a[h][z]);
		}
		printf("\n");
	}
	for (h = 0; h < 11; ++h)
	{
		for (z = 0; z < 11; ++z)
		{
			if (a[h][z] > 0 && book[h][z] >= 0)
			{
				num--;
				book[h][z] = num;
				
				dfs(h, z, num);
			}
		}
	}
	for (h = 0; h < 11; ++h)
	{
		for (z = 0; z < 11; ++z)
		{
			printf("%3d",book[h][z]);
		}
		printf("\n");
	}
	printf("有%d个小岛\n",-num);
}