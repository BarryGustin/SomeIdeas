/*
C语言KMP算法实现
*/



#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int* getNext(char p[] );                                //模板串中求得next[]数组
int findEnd(char l[], char p[],int next[]);                        //查找主串中的模板串





 //模板串中求得next[]数组
int* getNext(char p[]) {
	int next[10] = { 0 };
	next[0] = -1;
	int k = -1;
	for (int i = 0; i < strlen(p);)
	{
		if (k == -1 || p[i] == p[k])
		{
			next[++i] = ++k;
		}
		else {
			k = next[k];
		}
	}
	return next;
}






//查找主串中的模板串
int findEnd(char l[], char p[],int next[]) {
	int j = 0;
	for (int i = 0; i < strlen(l); ++i)
	{
		if (l[i] == p[j])
		{
			j++;
			if (j == strlen(p))
			{
				return 1;
			}
			continue;
		}
		else {
			j = next[j];
		}
	}
	return 0;
}



int main(void)
{
	//给出主串
	char l[10] = { 'a','b','c','a','b','c','b','c' };

	//给出模板串
	char p[10] = { 'a','b','c','a','b','c','b','c' };

	//模板串中求得next[]数组
	int*next=NULL;
	next = getNext(p);

	//查找主串中的模板串
	if (findEnd(l, p ,next))
	{
		printf("true");
	}
	else {
		printf("false");
	}
	return 0;

}