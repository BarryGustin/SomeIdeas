
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int* getNext(char p[]);                                //模板串中求得next[]数组
//int findEnd(char l[], char p[], int next[]);                        //查找主串中的模板串




int next[100];
 //模板串中求得next[]数组
int* getNext(char p[]) {
	
	for (int i = 0; i < 100; ++i)
	{
		next[i] = -2;
	}
	next[0] = -1;
	int k = -1;
	for (int i = 0; i < strlen(p)-1;)
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
/*int findEnd(char l[], char p[], int next[]) {
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
*/



int main(void)
{

	//给出主串
	//char l[10] = { 'a','b','c','a','b','c','b','c' };

	//给出模板串
	int num;
	scanf_s("%d",&num);
	char p[100];
	scanf_s("%s",p,sizeof(p));

	//模板串中求得next[]数组
	int* next = NULL;
	next = getNext(p);
	for (int i = 0; i<num; ++i)
	{
		printf("%d  ",*(next+i));
	}



	//查找主串中的模板串
	/*if (findEnd(l, p, next))
	{
		printf("true");
	}
	else {
		printf("false");
	}*/


	return 0;

}