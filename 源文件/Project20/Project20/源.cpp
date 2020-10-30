#include <stdio.h>
#include <stdlib.h>
#define  M  sizeof(struct people)
typedef struct people
{
	int num;
	struct people* next;
}student;
student* put (void)
{
	int num;
	printf("please input the number of element:\n");
	scanf_s("%d",&num);
	student** a,*head=NULL;
	int i; 
	a = (student**)malloc(sizeof(student*) * num);
	if (a == NULL)
	{
		printf("out of memory,press any key to quit.....\n");
		exit(0);
	}
	for (i = 0; i < num ; ++i)
	{
		a[i] = (student*)malloc(M);
		if (i - 0) a[i - 1]->next = a[i];
		else head = a[0];
		//printf("please input the information of the NO.%d student:\n",i+1);
		a[i]->num = i + 1;
	}
	a[i - 1]->next = a[0];
	return head;
}
student* del(student* head)
{
	int i,delnum;
	student* p, * q;
	printf("please input the delnum:\n");
	scanf_s("%d",&delnum);
	for (p =q= head,i = 1;p!=p->next; p = p->next)
	{
		if (!(i % delnum - 0))
		{
			q->next = p->next;
		}
		q = p;
		++i;
	}
	return p;
}
int main(void)
{
	student* end;
	end = del(put());
	printf("output the end student number:\n");
	printf("%d\n",end->num);
}