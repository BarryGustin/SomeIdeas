#include <stdio.h>
#include <string.h>
int strcmp(char *, char*);
int main(void)
{
	char s1[80], s2[80];
	void *p1 = s1;
	void* p2 = s2;
	printf("please input a string s1:");
	gets_s(s1);
	printf("please input a string s2:");
	gets_s(s2);
	printf("%d\n",strcmp((char*)p1,(char*)p2));
}
int strcmp(char* n1, char* n2)
{
	int a, b,loop;
	a = strlen(n1);
	b = strlen(n2);
	a = a < b ? a : b;
	for (loop = 0; loop < a; loop++) {
		if (*n1 - *n2) {
			return (*n1-*n2);
			break;
		}
		 else {
			n1++;
		    n2++;
		}
	}
	if (loop == a )
		return 0;
}

