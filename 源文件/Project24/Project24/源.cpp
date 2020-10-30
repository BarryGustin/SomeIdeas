#include<stdio.h>                                       //盛最多水容器问题
#include <string.h>                                     //由题分析可知，由两个隔板的最低板和两隔板间距的乘积决定最多盛水量。
#include <stdlib.h>                                     //故要同时考虑两个量的变化，故用链表
#include <conio.h>
#define M  sizeof(struct information)
typedef struct information                              //定义链表
{
	int num;
	int high;
	struct information* next;
}date;
date* input()                                           //输入函数（动态链表）
{
	int i=0;
	date* p1, *p2, *head=NULL;
	p1 =p2 = (date*)malloc(M);
	if (p1 == NULL)                                     //是否分配空间
	{
		printf("out of memory,press any key to quit.....\n");
		exit(0);
	}
	printf("please input the information of the chart:\n");
	p1->num = i++;
	scanf_s("%d",&p1->high);                            //赋值
	if (!(p1->high - 0))
	{
		system("cls");                                  //清屏，若第一个节点高度为0，则错误
		printf("input error,press any key to quit.....\n");
		exit(0);
	}
	for (; p1->high != 0;)                              //循环创建各个数据
	{
		if (!(i - 1))
		{
			head = p1;                                  //注意头指针
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
		printf("please input the information of the chart:\n");
		p1->num = i++;
		scanf_s("%d", &p1->high);
	}
	system("cls");                                      //清屏
	if (!(i - 2))                                       //控制节点至少有效两个，否则出错。
	{
		printf("please enter at least two valid numbers.....\n");
		exit(0);
	}
	p2->next = NULL;                                    //结束链表
	return head;
}

int calculate(date* head)                               //计算函数
{
	date* p1, * p2;
	int max=0,numb;
	p1 = p2 = head;
	for (; p1 != NULL; p1 = p1->next)                   //用两个指针遍历链表寻找最大的面积
	{
		for (p2=p1; p2 != NULL; p2 = p2->next)
		{
			numb = (p2->num - p1->num) * (p1->high < p2->high ? p1->high : p2->high);
			if (numb > max)
			{
				max = numb;
			}
		}
	}
	printf("output the maxmum water capacity:\n");
	return max;
}

int main(void)
{
	printf("%d\n", calculate(input()));                 //输出
}