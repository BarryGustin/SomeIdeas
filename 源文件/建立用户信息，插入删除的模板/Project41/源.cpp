#include<stdio.h>
#include <string.h>
#include <stdlib.h>
int h[101];
int n;


void output(int h[101]);                        /*输出堆*/
void creat();                                   /*初始建堆*/
void swap1(int x, int y);                       /*直接对外部变量h[101]中将两个数替换*/
void siftdown1(int x);                          /*对于堆，作向下调整，直接对外部变量h[101]*/
int* swap2(int x, int y, int h[101]);           /*对内部变量h[101]中将两个数替换*/
int* siftdown2(int x, int num, int h[101]);     /*对于堆，作向下调整，对内部变量h[101]作调整*/
int* siftup(int n, int h[101]);                 /*对于堆，作向上调整，对内部变量h[101]作调整*/
void del(int x);                                /*删除数据函数*/





/*对于堆，作向上调整，对内部变量h[101]作调整*/
int* siftup(int n, int h[101])
{
	int i = n, flag = 0, j;
	while (i >= 1 && flag == 0)
	{
		if (h[i] < h[i / 2] && i >= 1)
		{
			j = i / 2;
			h = swap2(j, i, h);
			i = j;
		}
		else
		{
			j = i;
			flag = 1;
		}
	}
	return h;
}




/*对于堆，作向下调整，直接对外部变量h[101]*/
void siftdown1(int x)
{
	while (x <= n)
	{
		if (h[x] > h[2 * x] && 2 * x <= n)
		{
			swap1(x, 2 * x);
		}
		if (h[x] > h[2 * x + 1] && 2 * x + 1 <= n)
		{
			swap1(x, 2 * x + 1);
		}
		x = 2 * x;
	}
}


/*对于堆，作向下调整，对内部变量h[101]作调整*/
int* siftdown2( int x,int num,int h[101])
{
	int n = num, flag = 0;
	int i, j;
	j = x;
	while (j <= n && flag == 0)
	{
		if (h[j] > h[2 * j] && 2 * j <= n)
		{
			i = 2 * j;
		}
		else
		{
			i = j;
		}
		if (h[i] > h[2 * j + 1] && 2 * j + 1 <= n)
		{
			i = 2 * j + 1;
		}
		if (i != j)
		{
			h = swap2(j, i, h);
			j = i;
		}
		else
		{
			flag = 1;
		}
	}
	return h;
}


/*直接对外部变量h[101]中将两个数替换*/
void swap1(int x, int y)
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
	return;
}



/*对内部变量h[101]中将两个数替换*/
int* swap2(int x, int y, int h[101])
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
	return h;
}


/*初始建堆*/
void creat()
{
	int i, j;
	for (i = n / 2; i >= 1; --i)
	{
		j = i;
		siftdown1(j);
	}
	return;
}



/*输出堆*/
void output(int h[101])
{
	int H[101] = {0};
	int i;
	for (i = 1; i <= n; ++i)
	{
		H[i] = h[i];
	}
	int num = n;
	printf("输出:\n");
	for (i = 1; num != 0; ++i)
	{
		printf("%d  ",H[1]);
		H[1] = H[num];
		--num;
		siftdown2(1,num, H);
	}
	printf("\n");
	return;
}


/*删除数据函数*/
void del(int x)
{
	int head = 1;
	if (h[head] == x)
	{
		h[head] = h[n];
		--n;
		siftdown2(head, n, h);
		printf("\n\n删除数据成功...\n");
		return;
	}
	while (head <= n / 2)
	{
		if (h[2 * head] == x && 2 * head <= n)
		{
			h[2 * head] = h[n];
			--n;
			siftdown2(2 * head, n, h);
			printf("\n\n删除数据成功...\n");
			return;
		}
		if (h[2 * head + 1] == x && 2 * head + 1 <= n)
		{
			h[2 * head + 1] = h[n];
			--n;
			siftdown2(2 * head + 1, n, h);
			printf("\n\n删除数据成功...\n");
			return;
		}
		head++;
	}
	printf("\n\n\n未找到要删除的数据！！\n");
	return;
}




int main(void)
{
	printf("要排序的数:\n");
	scanf_s("%d",&n);
	int i, j;
	for (i = 1; i <= n; ++i)
	{
		printf("输入%d数据:\n",i);
		scanf_s("%d",&h[i]);
	}
	creat();
	output(h);
	system("cls");
	printf("\n***********************    建堆完成   *************************\n\n");
	while (1)
	{
		printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf("\n是否插入(删除)打印数据:\n");
		printf("->插入请输入1\n->删除请输入2\n->打印请输入3\n->结束程序输入0\n");
		printf("请输入:");
		scanf_s("%d", &i);
		printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n");
		system("cls");
		if (i == 1)
		{
			printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			printf("\n请输入要加入的数据:\n");
			scanf_s("%d", &h[++n]);
			printf("\n\n插入数据成功...\n");
			siftup(n, h);
			printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n");
			//system("cls");
		}
		if (i == 2)
		{
			printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			printf("\n请输入要删除的数据:\n");
			scanf_s("%d", &j);
			del(j);
			printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n");
			//system("cls");
		}
		if (i == 0)
		{
			break;
		}
		for (j = 1; j <= 3; ++j)
		{
			printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			printf("\n是否打印序列:\n");
			printf("->打印须请输入打印密钥，否则不打印\n->如结束程序请输入0\n->如要返回插入(删除)数据输入1\n");
			printf("请输入:");
			scanf_s("%d", &i);
			if (i == 595957157)
			{
				output(h);
				printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n");
				break;
			}
			if (i == 0)
			{
				exit(0);
			}
			if (i == 1)
			{
				system("cls");
				break;
				
			}
			else
			{
				if (j == 3)
				{
					continue;
				}
				printf("\n密钥输入错误，您还有%d次输入机会,是否结束程序\n", 3 - j);
				printf("->继续打印请输入1\n->结束程序请输入2\n->如需要插入(删除)数据请输入3\n");
				printf("请输入:");
				scanf_s("%d", &i);
				printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n");
				system("cls");
				if (i == 1)
				{
					continue;
				}
				if (i == 2)
				{
					exit(0);
				}
				if (i == 3)
				{
					break;
				}
				else
				{
					printf("请按规定输入！！\n");
				}
			}
		}
		if (j == 4)
		{
			printf("\n密钥输入错误，输入密钥超过3次\n");
			printf("->可选择插入(删除)数据请输入1\n->结束程序请输入0\n");
			printf("请输入:");
			scanf_s("%d", &i);
			printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n");
			system("cls");
			if (i == 1);
			if (i == 0)
			{
				exit(0);
			}
		}
	}
}






/*
14
99
5
36
7
22
17
46
12
2
19
25
28
1
92
*/
