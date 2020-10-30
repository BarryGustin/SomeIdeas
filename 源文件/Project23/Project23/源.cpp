#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
char b[15];
char* p = b;
int change(int a)
{
	int i, m;
	if (a > 3999 && a < 0)
	{
		printf("input error,press any key to quit.....\n");
		exit(0);
	}
	else if (a >= 1000 && a <= 3999)
	{
		m = a / 1000;
		a = a % 1000;
		for (i = 0; i < m; ++i)
		{
			*(p++) = 'M';
		}
	}
	else if (a >= 900 && a < 1000)
	{
		a = a % 900;
		*(p++) = 'C';
		*(p++) = 'M';
	}
	else if (a >= 500 && a < 900)
	{
		a = a % 500;
		*(p++) = 'D';
	}
	else if (a >= 400 && a < 500)
	{
		a = a % 400;
		*(p++) = 'C';
		*(p++) = 'D';
	}
	else if (a >= 100 && a < 400)
	{
		m = a / 100;
		a = a % 100;
		for (i = 0; i < m; ++i)
		{
			*(p++) = 'C';
		}
	}
	else if (a >= 90 && a < 100)
	{
		a = a % 90;
		*(p++) = 'X';
		*(p++) = 'C';
	}
	else if (a >= 50 && a < 90)
	{
		a = a % 50;
		*(p++) = 'L';
	}
	else if (a >= 40 && a < 50)
	{
		a = a % 40;
		*(p++) = 'X';
		*(p++) = 'L';
	}
	else if (a >= 10 && a < 40)
	{
		m = a / 10;
		a = a % 10;
		for (i = 0; i < m; ++i)
		{
			*(p++) = 'X';
		}
	}
	else if (!(a - 9))
	{
		a = a % 9;
		*(p++) = 'I';
		*(p++) = 'X';
	}
	else if (a >= 5 && a < 9)
	{
		a = a % 5;
		*(p++) = 'V';
	}
	else if (!(a - 4))
	{
		a = a % 4;
		*(p++) = 'I';
		*(p++) = 'V';
	}
	else if (a >= 1 && a < 4)
	{
		m = a / 1;
		a = a % 1;
		for (i = 0; i < m; ++i)
		{
			*(p++) = 'I';
		}
	}
	return a;
}
int main(void)
{
	int a;
	printf("please input a number(1~3999)\n");
	scanf_s("%d",&a);
	system("cls");
	if (!(a - 0))
	{
		printf("input error,press any key to quit.....\n");
		exit(0);
	}
	for (; a != 0; a=change(a));
	*p='\0';
	printf("output a Arabic number:\n");
	printf("%s\n",b);
}