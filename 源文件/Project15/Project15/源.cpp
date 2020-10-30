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
	p1 = p2 = (struct student*)malloc(num);    //����ʼ������һ���ڵ�Ŀռ�
	if (p1 == NULL){
		printf("out of memory,press any key to quit....\n");
		exit(0);
	}
	printf("please input the information of the %d`s student:",1);
	scanf_s("%d%s%d",&(*p1).stud_arr,(*p1).name,sizeof((*p1).name),&(*p1).score); // �����һ������Ϣ
	for (head = NULL; (*p1).stud_arr != 0;)
	{
		n++;                          //1������ʹͷ�����е�ַ��������
		if (!(n - 1)) head = p1;
		else { (*p2).next = p1;    p2 = p1; }  //4.���½ڵ�ĵ�ַ����һ���ڵ�󣬽�p2�����½ڵ㴦��
		p1 = (struct student*)malloc(num);  //2.������һ�ڵ�
		if (p1 == NULL) {
			printf("out of memory,press any key to quit....\n");
			exit(0);
		}
		printf("please input the information of the %d`s student:",n+1);
		scanf_s("%d%s%d", &(*p1).stud_arr, (*p1).name, sizeof((*p1).name), &(*p1).score);//3.������Ϣ
	}
	 (*p2).next = NULL;  //5.��p1�������½ڵ�ΪNULLʱ��
	 return (head);     //�뽫��һ�ڵ�ָ����һ�ڵ��ָ��(*p2).next��Ϊ�ա�
	  
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