#include <stdio.h>
#include <string.h>
#define  space 80
void del_repeat(char a[]);
int main(void)
{
	char a[space], b[space];
	int i, j, num, q;
	printf("please input a string:\n");
	gets_s(a);
	num = strlen(a);
	a[num] = '\0';
	j = 0;
	for (i = 0; i < num; i++)
	{
		if (a[i] >= 'A' && a[i] <= 'Z')
		{

			b[j] = a[i];
			j++;
		}
	}
	b[j] = '\0';
	printf("Î´É¾³ýÇ°µÄb:\n");
	printf("%s\n", b);
	q = strlen(b);
	if (q)
	{
		printf("output a string:\n");
		del_repeat(b);
	}
	else
		printf("error!!!");
}
void del_repeat(char a[])
{
	int q, i, j, k;
	q = strlen(a);
	for (i = 1; i < q; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (a[i] == a[j])
			{
				for (k = i; k < q; k++)
				{
					a[k] = a[k + 1];
				}
				a[k] = '\0';
				i--;
				q--;

			}
		}
	}
	printf("%s\n", a);
}
