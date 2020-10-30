#include <stdio.h>                                 //力扣的两数之和题
#include <string.h>
#include <stdlib.h>
#define M  sizeof(struct names)
typedef struct names
{
	int dat;
	int num;
	struct names* next;
}date;
date* input()
{
	int i = 0;
	date* p1, * p2, * head=NULL;
	p1 = p2 = (date*)malloc (M);
	if (p1 == NULL)
	{
		printf("out of memory,press any key to quit.....\n");
		exit(0);
	}
	printf("please input a number:\n");
	scanf_s("%d",&p1->dat);
	p1->num = i++;
	for (; p1->dat != 0;)
	{
		if (!(i - 1))
		{
			head = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
		p1 = (date*)malloc(M);
		if (p1 == NULL)
		{
			printf("out of memory,press any key to quit.....\n");
			exit(0);
		}
		printf("please input a number:\n");
		scanf_s("%d", &p1->dat);
		p1->num = i++;
	}
	p2->next = NULL;
	return head;
}

date* delet (date* head)
{
	date* p1, * p2, * p3;
	for (p1 = head; p1!=NULL;p1 = p1->next)
	{
		for (p2 = p1->next,p3 = p1; p2!=NULL;p2 = p2->next)
		{
			if (p1->dat == p2->dat)
			{
				p3->next = p2->next;
			}
			else
			{
				p3 = p2;
			}
		}
	}
	return head;
}

int main(void)
{
	int a,i=0;
	printf("please input a number of add:\n");
	scanf_s("%d",&a);
	date* p1, * p2;
	p1 = p2 = delet(input());
	for (; p1!=NULL; p1 = p1->next)
	{
		for (p2=p1->next; p2!=NULL; p2 = p2->next)
		{
			if (!(p1->dat + p2->dat - a))
			{
				i++;
				printf("the end:\n");
				printf("[%d,%d]\n",p1->num,p2->num);
				exit(0);                                //只输出一组时加上该语句
			}
		}
	}
	if (!i)
	{
		printf("no any answer,press any key to quit....\n");
	}
}