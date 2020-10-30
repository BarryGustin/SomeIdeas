#include<stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct stu_situation
{
	char name[20];
	int  stuNum;
	char sex;
	struct stu_situation* next;
}date;




date* addStu();                                              /*½¨Á´*/ 
date* delet(date* head);                                     /*É¾Á´*/
void print(date* head);                                      /*´òÓ¡*/




/*½¨Á´*/
date* addStu() {
	date* head=NULL,*p=NULL,*q=NULL;
	head=q= (date*)malloc(sizeof(date));
	scanf_s("%s", head->name,sizeof(head->name));
	scanf_s("%d ", &head->stuNum);
	scanf_s("%c", &head->sex);
	while (strcmp(head->name, "#") != 0)
	{
		p = (date*)malloc(sizeof(date));
		scanf_s("%s",p->name,sizeof(head->name));
		if (strcmp(p->name, "#") == 0)
		{
			break;
		}
		scanf_s("%d ", &p->stuNum);
		scanf_s("%c", &p->sex);
		q->next = p;
		q = p;
		q->next = NULL;
	}
	return head;
}




/*É¾³ý*/
date* delet(date* head) {
	int n;
	int flag = 1;
	scanf_s("%d",&n);
	if (head->stuNum == n)
	{
		flag = 0;
		head = head->next;
		return head;
	}
	date* p = head;
	while (p->next != NULL)
	{
		if (p->next->stuNum == n)
		{
			flag = 0;
			p->next= p->next->next;
			return head;
		}
		p = p->next;
	}
	if (flag==1)
	{
		printf("no!\n");
		exit(0);
	}
	return head;
}




/*´òÓ¡*/
void print(date* head)
{
	while (head != NULL)
	{
		printf("%s %d %c\n",head->name,head->stuNum,head->sex);
		head = head->next;
	}
	return;
}

int main(void )
{
	date* head=NULL;
	head = addStu();
	head=delet(head);
	print(head);
	return 0;
}



/*
Lidong 101 M
Xidong 102 F
jj 103 M
qq 104 F
*/