#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int orderlist_sum, orderlist_i;
int strick;
char num[100];
char NumEnd[100];
int fun;


void TrOrFro()
{
	orderlist_i++;
	if (orderlist_sum == orderlist_i)
	{
		exit(0);
	}
}


void OrderStart()
{
	char a[10];
	scanf_s("%s",a,sizeof(a));
	TrOrFro();
	return;
}


void Dochoose()
{
	char a[10];
	scanf_s("%s",a,sizeof(a));
	if (strcmp(a, "NUM"))
	{
		scanf_s("%s", num, sizeof(num));
		TrOrFro();
		Dochoose();
	}
	else if (strcmp(a, "CHANGE"))
	{
		scanf_s("%d",&strick);
		TrOrFro();
		Dochoose();
	}
	else if (strcmp(a,"ADD"))
	{
		fun = 1;
		TrOrFro();
		Dochoose();
	}
	else if (strcmp(a, "SUB"))
	{
		fun = 2;
		TrOrFro();
		Dochoose();
	}
	else if (strcmp(a, "MUL"))
	{
		fun = 3;
		TrOrFro();
		Dochoose();
	}
	else if (strcmp(a, "DIV"))
	{
		fun = 4;
		TrOrFro();
		Dochoose();
	}
	else if (strcmp(a, "MOD"))
	{
		fun = 5;
		TrOrFro();
		Dochoose();
	}
	else if (strcmp(a, "EQUAL"))
	{


	}
	else if (strcmp(a, "CLEAR"))
	{
		memset(num, NULL, sizeof(num));
		memset(NumEnd, NULL, sizeof(NumEnd));
		TrOrFro();
		Dochoose();
	}
}

int main(void)
{
	extern int orderlist_sum, orderlist_i;
	//printf("输入命令行数:");
	scanf_s("%d",&orderlist_sum);
	//printf("程序开始:\n");
	for (; 1;)
	{
		OrderStart();
		Dochoose();
	}
	return 0;
}