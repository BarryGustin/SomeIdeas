#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int a[5][4] = { {5,3,5,3},{1,5,3,0},{2,3,5,1},{6,1,1,5},{1,5,5,4} };
int book[5][4];
int p, q;
int h, z;
int flag = 0;
int j = 0;
int enfront;

void dfs(int x, int y, int front)
{
	if (enfront == 1)
	{
		if (x == p+1 && y == q  && front == 1)
		{
			printf("possible\n");
			printf("路径为：\n");
			flag = 1;
			for (h = 0; h < 5; ++h)
			{
				for (z = 0; z < 4; ++z)
				{
					if (book[h][z] == 1)
					{
						printf("(%d,%d)  ", h + 1, z + 1);
					}
				}
			}
			return;
		}
	}

	if (enfront == 2)
	{
		if (x == p -1 && y == q && front == 2)
		{
			printf("possible\n");
			printf("路径为：\n");
			flag = 1;
			for (h = 0; h < 5; ++h)
			{
				for (z = 0; z < 4; ++z)
				{
					if (book[h][z] == 1)
					{
						printf("(%d,%d)  ", h + 1, z + 1);
					}
				}
			}
			return;
		}
	}
	if (enfront == 4)
	{
		if (x == p  && y == q-1 && front == 4)
		{
			printf("possible\n");
			printf("路径为：\n");
			flag = 1;
			for (h = 0; h < 5; ++h)
			{
				for (z = 0; z < 4; ++z)
				{
					if (book[h][z] == 1)
					{
						printf("(%d,%d)  ", h + 1, z + 1);
					}
				}
			}
			return;
		}
	}
	if (enfront == 3)
	{
		if (x == p && y == q + 1 && front == 3)
		{
			printf("possible\n");
			printf("路径为：\n");
			flag = 1;
			for (h = 0; h < 5; ++h)
			{
				for (z = 0; z < 4; ++z)
				{
					if (book[h][z] == 1)
					{
						printf("(%d,%d)  ", h + 1, z + 1);
					}
				}
			}
			/*printf("\n");
			for (h = 0; h < 5; ++h)
			{
				for (z = 0; z < 4; ++z)
				{
					printf("%d  ", book[h][z]);

				}
				printf("\n");
			}*/
			return;
		}
	}
	if (x<0 || x>p || y<0 || y>q)
	{
		return;
	}
	if (book[x][y] == 1 && x != 0&& y != 0)
	{
		return;
	}
	if (front == 1 && a[x][y] == 5)
	{
		book[x][y] = 1;
		a[x][y] = 6;
		dfs(x+1, y, 1);
		a[x][y] = 5;
		book[x][y] = 0;
	}
	if (front == 2 && a[x][y] == 5)
	{
		book[x][y] = 1;
		a[x][y] = 6;
		dfs(x - 1, y, 2);
		a[x][y] = 5;
		book[x][y] = 0;
	}
	if (front == 3 && a[x][y] == 5)
	{
		book[x][y] = 1;
		dfs(x,y+1,3);
		book[x][y] = 0;
	}
	if (front == 4 && a[x][y] == 5)
	{
		book[x][y] = 1;
		dfs(x, y - 1, 4);
		book[x][y] = 0;
	}
	if (front == 1 && a[x][y] == 6)
	{
		book[x][y] = 1;
		dfs(x+1, y, 1);
		book[x][y] = 0;
	}
	if (front == 2 && a[x][y] == 6)
	{
		book[x][y] = 1;
		dfs(x - 1, y, 2);
		book[x][y] = 0;
	}
	if (front == 3 && a[x][y] == 6)
	{
		book[x][y] = 1;
		a[x][y] = 5;
		dfs(x , y+1, 3);
		a[x][y] = 6;
		book[x][y] = 0;
	}
	if (front == 4 && a[x][y] == 6)
	{
		book[x][y] = 1;
		a[x][y] = 5;
		dfs(x, y-1, 2);
		a[x][y] = 6;
		book[x][y] = 0;
	}
	if (front == 1 && a[x][y] == 1)
	{
		book[x][y] = 1;
		dfs(x , y+1, 3);
		dfs(x, y - 1, 4);
		book[x][y] = 0;
	}
	if (front == 2 && a[x][y] == 1)
	{
		book[x][y] = 1;
		a[x][y] = 2;
		dfs(x, y+1, 3);
		a[x][y] = 3;
		dfs(x, y - 1, 4);
		a[x][y] = 1;
		book[x][y] = 0;
	}
	if (front == 3 && a[x][y] == 1)
	{
		book[x][y] = 1;
		a[x][y] = 3;
		dfs(x+1, y , 1);
		a[x][y] = 4;
		dfs(x-1, y, 2);
		a[x][y] = 1;
		book[x][y] = 0;
	}
	if (front == 4 && a[x][y] == 1)
	{
		book[x][y] = 1;
		dfs(x-1, y , 2);
		dfs(x + 1, y, 1);
		book[x][y] = 0;
	}
	if (front == 1 && a[x][y] == 2)
	{
		book[x][y] = 1;
		a[x][y] = 1;
		dfs(x, y + 1, 3);
		a[x][y] = 4;
		dfs(x, y - 1, 4);
		a[x][y] = 2;
		book[x][y] = 0;
	}
	if (front == 2 && a[x][y] == 2)
	{
		book[x][y] = 1;
		dfs(x, y + 1, 3);
		dfs(x, y - 1, 4);
		book[x][y] = 0;
	}
	if (front == 3 && a[x][y] == 2)
	{
		book[x][y] = 1;
		a[x][y] = 3;
		dfs(x+1, y, 1);
		a[x][y] = 4;
		dfs(x-1, y, 2);
		a[x][y] = 2;
		book[x][y] = 0;
	}
	if (front == 4 && a[x][y] == 2)
	{
		book[x][y] = 1;
		a[x][y] = 2;
		dfs(x + 1, y, 1);
		a[x][y] = 1;
		dfs(x - 1, y, 2);
		book[x][y] = 0;
	}
	if (front == 1 && a[x][y] == 3)
	{
		book[x][y] = 1;
		a[x][y] = 1;
		dfs(x, y + 1, 3);
		a[x][y] = 4;
		dfs(x, y - 1, 4);
		a[x][y] = 3;
		book[x][y] = 0;
	}
	if (front == 3 && a[x][y] == 3)
	{
		book[x][y] = 1;
		dfs(x+1, y , 1);
		dfs(x - 1, y, 2);
		book[x][y] = 0;
	}
	if (front == 2 && a[x][y] == 3)
	{
		book[x][y] = 1;
		dfs(x, y -1, 4);
		dfs(x, y + 1, 3);
		book[x][y] = 0;
	}
	if (front == 4 && a[x][y] == 3)
	{
		book[x][y] = 1;
		a[x][y] = 1;
		dfs(x-1, y, 2);
		a[x][y] = 2;
		dfs(x+1, y, 1);
		a[x][y] = 3;
		book[x][y] = 0;
	}
	if (front == 1 && a[x][y] == 4)
	{
		book[x][y] = 1;
		dfs(x, y - 1, 4);
		dfs(x, y + 1, 3);
		book[x][y] = 0;
	}
	if (front == 2 && a[x][y] == 4)
	{
		book[x][y] = 1;
		a[x][y] = 2;
		dfs(x, y + 1, 3);
		a[x][y] = 3;
		dfs(x, y - 1, 4);
		a[x][y] = 4;
		book[x][y] = 0;
	}
	if (front == 3 && a[x][y] == 4)
	{
		book[x][y] = 1;
		dfs(x - 1, y, 2);
		dfs(x + 1, y, 1);
		book[x][y] = 0;
	}
	if (front == 4 && a[x][y] == 4)
	{
		book[x][y] = 1;
		a[x][y] = 1;
		dfs(x-1, y , 2);
		a[x][y] = 2;
		dfs(x+1, y , 1);
		a[x][y] = 4;
		book[x][y] = 0;
	}
	return;
}



int main(void)
{
	extern int a[5][4];
	extern int h, z;
	extern int p, q, enfront;
	printf("输入想到的位置:\n");
	printf("p=");
	scanf_s("%d",&p);
	p--;
	printf("q=");
	scanf_s("%d", &q);
	q--;
	printf("最终朝向:\n");
	scanf_s("%d",&enfront);
	int front = 3;
	book[0][0] = 1;
	dfs(0, 0, 3);
	if (flag == 0)
	{
		printf("impossible\n");
	}
	
}