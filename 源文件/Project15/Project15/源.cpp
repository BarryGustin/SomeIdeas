#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define num sizeof(struct student)
struct student
{
	int stud_arr;
	char name[20];
	int score;
	struct student* next;
};
struct student* input(void)
{
	struct student* p1, * p2, * head;
	int n=0;
	p1 = p2 = (struct student*)malloc(num);    //链表开始，开辟一个节点的空间
	if (p1 == NULL){
		printf("out of memory,press any key to quit....\n");
		exit(0);
	}
	printf("please input the information of the %d`s student:",1);
	scanf_s("%d%s%d",&(*p1).stud_arr,(*p1).name,sizeof((*p1).name),&(*p1).score); // 输入第一个人信息
	for (head = NULL; (*p1).stud_arr != 0;)
	{
		n++;                          //1、建立使头函数有地址，而定义
		if (!(n - 1)) head = p1;
		else { (*p2).next = p1;    p2 = p1; }  //4.将新节点的地址给上一个节点后，将p2拉到新节点处。
		p1 = (struct student*)malloc(num);  //2.开辟下一节点
		if (p1 == NULL) {
			printf("out of memory,press any key to quit....\n");
			exit(0);
		}
		printf("please input the information of the %d`s student:",n+1);
		scanf_s("%d%s%d", &(*p1).stud_arr, (*p1).name, sizeof((*p1).name), &(*p1).score);//3.输入信息
	}
	 (*p2).next = NULL;  //5.在p1创建的新节点为NULL时，
	 return (head);     //须将上一节点指向下一节点的指针(*p2).next赋为空。
	  
}
void output(struct student*n)
{
	struct student* p; 
	int q=0;
		for(p = n;p != NULL;p = (*p ).next)
		{
			printf("output the information of the %d`s student\n",++q);
			printf("%d\t%s\t%d\n", (*p ).stud_arr, (*p ).name,(*p ).score);
		}
}
struct student*  amax (struct student* n)
{
	struct student* p1,*p2;
	for (p1=p2 = n,p1 = (*p1).next; p1 != NULL; p1 = (*p1).next)
	{
		if ((*p2).score < (*p1).score)  p2 = p1;
	}
	return (p2);
}
void point(struct student* n)
{
	printf("putout the information of the best student:\n");
	printf("%d\t%s\t%d\n", (*n).stud_arr, (*n).name, (*n).score);
}
int main (void)
{
	struct student* p;                                        
	printf("                                                  student number   name   score\n");
	p = input();
	output(p);
	p=amax(p);
	point(p);
	return (0);
}