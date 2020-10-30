#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
   {
	char str[3][21], desk[61];
	int i, j,k;
	scanf_s("%p%p%p", str[0], str[1], str[2]);
	k = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 21; j++)
		{
			if (str[i][j] == '\0')   break;
			else
			{
				desk[k] = str[i][j];
				k++;
			}
		}
	}desk[k] = '\0';
	printf("%s\n",desk);
}