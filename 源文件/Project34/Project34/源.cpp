#include <stdio.h>               /*���������������*/
#include <stdlib.h>              /*1.������ÿһ�����кü��ֿ�����ʹ��*/
#include <string.h>              /*2.��book��¼ÿһ������ֹ��һ������һ�Σ���������ѭ��*/
                                 /*3.��ÿһ��ʱ�����Ĵ�����ѭ��ÿһ���ĺü��ֿ��ܣ��߳�ĳһ����book��¼
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
	printf("���Ƿ������н�����ͼ��\n");
	printf("����루ѡ1��\t������루ѡ2����\n");
	scanf_s("%d",&s);
	if (s == 1)
	{
		int h, z;
		printf("������ͼ�Ĺ�ģ��\n");
		printf("��\t�ݣ�\n");
		scanf_s("%d%d", &h, &z);
		printf("������ͼ��'#'Ϊ�ϰ��'.'Ϊ·����\n");
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
	printf("������ʼλ�ã�\n");
	printf("x=");
	scanf_s("%d",&x);
	printf("y=");
	scanf_s("%d", &y);
	printf("������ֹλ�ã�\n");
	printf("p=");
	scanf_s("%d", &p);
	printf("q=");
	scanf_s("%d", &q);
	book[x][y] = 1;
	if (m[p][q] == '#')
	{
		printf("ָ������λ�����ϰ���Ŷ������");
		exit(0);
	}
	dfs(x,y,0);
	if ((x != p || y != q) && min == 0)
	{
		printf("·��������ˣ��޷��ߵ�ָ��λ��");
	}
	else if (x == p || y == q)
	{
		printf("��Ҫ�����λ�þ�����ʼλ��Ŷ!!");
	}
	else
	{
		printf("������Ҫ%d��ŷ~~~\n", min);
	}
		
}