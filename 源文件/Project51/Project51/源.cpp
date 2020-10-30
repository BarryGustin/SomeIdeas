/*
C����KMP�㷨ʵ��
*/



#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int* getNext(char p[] );                                //ģ�崮�����next[]����
int findEnd(char l[], char p[],int next[]);                        //���������е�ģ�崮





 //ģ�崮�����next[]����
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






//���������е�ģ�崮
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
	//��������
	char l[10] = { 'a','b','c','a','b','c','b','c' };

	//����ģ�崮
	char p[10] = { 'a','b','c','a','b','c','b','c' };

	//ģ�崮�����next[]����
	int*next=NULL;
	next = getNext(p);

	//���������е�ģ�崮
	if (findEnd(l, p ,next))
	{
		printf("true");
	}
	else {
		printf("false");
	}
	return 0;

}