#include<stdio.h>                                       //ʢ���ˮ��������
#include <string.h>                                     //���������֪���������������Ͱ����������ĳ˻��������ʢˮ����
#include <stdlib.h>                                     //��Ҫͬʱ�����������ı仯����������
#include <conio.h>
#define M  sizeof(struct information)
typedef struct information                              //��������
{
	int num;
	int high;
	struct information* next;
}date;
date* input()                                           //���뺯������̬����
{
	int i=0;
	date* p1, *p2, *head=NULL;
	p1 =p2 = (date*)malloc(M);
	if (p1 == NULL)                                     //�Ƿ����ռ�
	{
		printf("out of memory,press any key to quit.....\n");
		exit(0);
	}
	printf("please input the information of the chart:\n");
	p1->num = i++;
	scanf_s("%d",&p1->high);                            //��ֵ
	if (!(p1->high - 0))
	{
		system("cls");                                  //����������һ���ڵ�߶�Ϊ0�������
		printf("input error,press any key to quit.....\n");
		exit(0);
	}
	for (; p1->high != 0;)                              //ѭ��������������
	{
		if (!(i - 1))
		{
			head = p1;                                  //ע��ͷָ��
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
	system("cls");                                      //����
	if (!(i - 2))                                       //���ƽڵ�������Ч�������������
	{
		printf("please enter at least two valid numbers.....\n");
		exit(0);
	}
	p2->next = NULL;                                    //��������
	return head;
}

int calculate(date* head)                               //���㺯��
{
	date* p1, * p2;
	int max=0,numb;
	p1 = p2 = head;
	for (; p1 != NULL; p1 = p1->next)                   //������ָ���������Ѱ���������
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
	printf("%d\n", calculate(input()));                 //���
}