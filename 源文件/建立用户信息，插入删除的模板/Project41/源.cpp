#include<stdio.h>
#include <string.h>
#include <stdlib.h>
int h[101];
int n;


void output(int h[101]);                        /*�����*/
void creat();                                   /*��ʼ����*/
void swap1(int x, int y);                       /*ֱ�Ӷ��ⲿ����h[101]�н��������滻*/
void siftdown1(int x);                          /*���ڶѣ������µ�����ֱ�Ӷ��ⲿ����h[101]*/
int* swap2(int x, int y, int h[101]);           /*���ڲ�����h[101]�н��������滻*/
int* siftdown2(int x, int num, int h[101]);     /*���ڶѣ������µ��������ڲ�����h[101]������*/
int* siftup(int n, int h[101]);                 /*���ڶѣ������ϵ��������ڲ�����h[101]������*/
void del(int x);                                /*ɾ�����ݺ���*/





/*���ڶѣ������ϵ��������ڲ�����h[101]������*/
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




/*���ڶѣ������µ�����ֱ�Ӷ��ⲿ����h[101]*/
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


/*���ڶѣ������µ��������ڲ�����h[101]������*/
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


/*ֱ�Ӷ��ⲿ����h[101]�н��������滻*/
void swap1(int x, int y)
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
	return;
}



/*���ڲ�����h[101]�н��������滻*/
int* swap2(int x, int y, int h[101])
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
	return h;
}


/*��ʼ����*/
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



/*�����*/
void output(int h[101])
{
	int H[101] = {0};
	int i;
	for (i = 1; i <= n; ++i)
	{
		H[i] = h[i];
	}
	int num = n;
	printf("���:\n");
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


/*ɾ�����ݺ���*/
void del(int x)
{
	int head = 1;
	if (h[head] == x)
	{
		h[head] = h[n];
		--n;
		siftdown2(head, n, h);
		printf("\n\nɾ�����ݳɹ�...\n");
		return;
	}
	while (head <= n / 2)
	{
		if (h[2 * head] == x && 2 * head <= n)
		{
			h[2 * head] = h[n];
			--n;
			siftdown2(2 * head, n, h);
			printf("\n\nɾ�����ݳɹ�...\n");
			return;
		}
		if (h[2 * head + 1] == x && 2 * head + 1 <= n)
		{
			h[2 * head + 1] = h[n];
			--n;
			siftdown2(2 * head + 1, n, h);
			printf("\n\nɾ�����ݳɹ�...\n");
			return;
		}
		head++;
	}
	printf("\n\n\nδ�ҵ�Ҫɾ�������ݣ���\n");
	return;
}




int main(void)
{
	printf("Ҫ�������:\n");
	scanf_s("%d",&n);
	int i, j;
	for (i = 1; i <= n; ++i)
	{
		printf("����%d����:\n",i);
		scanf_s("%d",&h[i]);
	}
	creat();
	output(h);
	system("cls");
	printf("\n***********************    �������   *************************\n\n");
	while (1)
	{
		printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf("\n�Ƿ����(ɾ��)��ӡ����:\n");
		printf("->����������1\n->ɾ��������2\n->��ӡ������3\n->������������0\n");
		printf("������:");
		scanf_s("%d", &i);
		printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n");
		system("cls");
		if (i == 1)
		{
			printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			printf("\n������Ҫ���������:\n");
			scanf_s("%d", &h[++n]);
			printf("\n\n�������ݳɹ�...\n");
			siftup(n, h);
			printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n");
			//system("cls");
		}
		if (i == 2)
		{
			printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			printf("\n������Ҫɾ��������:\n");
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
			printf("\n�Ƿ��ӡ����:\n");
			printf("->��ӡ���������ӡ��Կ�����򲻴�ӡ\n->���������������0\n->��Ҫ���ز���(ɾ��)��������1\n");
			printf("������:");
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
				printf("\n��Կ�������������%d���������,�Ƿ��������\n", 3 - j);
				printf("->������ӡ������1\n->��������������2\n->����Ҫ����(ɾ��)����������3\n");
				printf("������:");
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
					printf("�밴�涨���룡��\n");
				}
			}
		}
		if (j == 4)
		{
			printf("\n��Կ�������������Կ����3��\n");
			printf("->��ѡ�����(ɾ��)����������1\n->��������������0\n");
			printf("������:");
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
