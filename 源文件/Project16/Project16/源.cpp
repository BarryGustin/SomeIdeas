#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M  sizeof(struct student)
struct student
{
	char name[20];
	int num;
	char sex[2];
	char work[2];
	union
	{
		int clas;
		char posi[20];
	}does;
	struct student* next;
};

struct student * input(void)
{
	struct student* p1, * p2, * head=NULL;
	p1 = p2 = (struct student*)malloc(M);
	printf("please input the information of NO.%d student :\n",1);
	scanf_s("%s", p1->name, sizeof(p1->name));
	scanf_s("%d", &p1->num);
	scanf_s("%s", p1->sex, sizeof(p1->sex));
	scanf_s("%s", p1->work, sizeof(p1->work));
	
	if (!(*p1->work - 's'))
	{
		scanf_s("%d", &p1->does.clas);
	}
	else if (!(*p1->work - 't'))
	{
		scanf_s("%s", p1->does.posi, sizeof(p1->does));
	}
	else;

	int n = 0;
	for (;p1->num!=0 ;)
	{
		n++;
		if (!(n - 1))  head = p1;
		else
		{
			(*p2).next = p1;    
			p2 = p1;
		}
		p1 = (struct student*)malloc(M); 
		printf("please input the information of NO.%d student :\n",n+1);
		scanf_s("%s", p1->name, sizeof(p1->name));
		scanf_s("%d", &p1->num);
		scanf_s("%s", p1->sex, sizeof(p1->sex));
		scanf_s("%s", p1->work, sizeof(p1->work));
		if (!(*p1->work - 's'))
		{
			scanf_s("%d", &(*p1).does.clas);
		}
		else if (!(*p1->work - 't'))
		{
			scanf_s("%s", p1->does.posi, sizeof(p1->does.posi));
		}
	}    
	(*p2).next = NULL;
	return (head);
}



struct student* creat(struct student* n)
{
	struct student* p1;
	p1 = (struct student*)malloc(M);
	if (p1 == NULL) {
		printf("out of memory,press any key to quit....\n");
		exit(0);
	}
	printf("please input the information of NO.%d student :\n", 1);
	scanf_s("%s", p1->name, sizeof(p1->name));
	scanf_s("%d" ,&p1->num);
	scanf_s("%s",p1->sex, sizeof(p1->sex));
	scanf_s("%s", p1->work, sizeof(p1->work));
	if (!(*p1->work - 's'))
	{
		scanf_s("%d", &(*p1).does.clas);
	}
	else if (!(*p1->work - 't'))
	{
		scanf_s("%s", p1->does.posi, sizeof(p1->does.posi));
	}
	else;

	(*p1).next = n;
	if (!(p1->num))
		p1 = NULL;
	n = p1;
	return(n);
}

void output(struct student* n)
{
	struct student* p;
	int i;
	for (p = n, i = 1; p != NULL; p = p->next, i++)
	{
		printf("output the information of NO.%d student :\n", i);
		printf("%s\t%d\t%s\t%s\t", p->name, p->num, p->sex, p->work);
		if (!(*(*p).work - 's'))
			printf("%d\n", (*p).does.clas);
		else
			printf("%s\n", p->does.posi);
	}
}

int main(void)
{
	struct student* l;
	l = input();
	output(creat(l));
	return 0;
}


