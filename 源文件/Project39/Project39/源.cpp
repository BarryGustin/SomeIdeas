#include <stdio.h>          /*Ѱ�ҳ��е�ͼ����Ҫȥ�ĵط���·�ߺ����·��*/
#include <string.h>                  /*����*/
#include <stdlib.h>
#include <math.h>


int a[101][101];                 /*�����ͼ*/
int w[101][101];                 /*ͼ�и��ص����ľ���*/
int book[10], minbook[10];       /*��¼·������̵��Ǹ�·��*/
int n,m;                          /*һ��n���ص�*/
int sum = 0, min = 99999999;     /*��¼·�̺����·��*/



/*����õص�*/
void dfs(int x)
{
	int i;
	if (x == 5)                  /*�����Ŀ�ĵأ����·��������Ƿ������·��*/
	{
		printf("���·��:\n");
		for (i = 1; i <= n; ++i)
		{
			if (book[i] == 1)
			{
				printf("%d  ",i);
			}
		}
		printf("\n���·��:\n");
		printf("%d\n",sum);
		if (sum < min)                     /*��Ϊ���·������minbook��¼*/
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
		if (a[x][i] == 1 && book[i] == 0)/*���x����i�ؼ���·����i��δ·��*/
		{
			book[i] = 1;                 /*�ߵ�i��*/
			sum += w[x][i];              /*��¼·��*/
			dfs(i);                      /*����i��*/
			sum -= w[x][i];              /*����·��*/
			book[i] = 0;                 /*�˳�i�أ�׼������һ������ѡ����һ·��*/
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
	printf("�������У�\n");                /*������ͼ*/
	scanf_s("%d",&n);
	printf("������·��\n");
	scanf_s("%d", &m);
	for (i = 0; i < m; ++i)
	{
		printf("�����%d����ͨ��·:\n",i+1);
		scanf_s("%d%d", &b, &c);
		printf("��·����:\n");
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
	book[1] = 1;                              /*��¼��λ��*/
	dfs(1);                                   /*�����һ��*/
	printf("·�����ٵ�·��Ϊ:\n");
	for (i = 1; i <= n; ++i)
	{
		if (minbook[i] == 1)
		{
			printf("%d  ",i);
		}
	}
	printf("\n����·��:\n");
	printf("%d\n",min);
}