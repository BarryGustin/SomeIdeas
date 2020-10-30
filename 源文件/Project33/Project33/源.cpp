#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


/*二进制转十进制*/
double two_ten(double p)
{
	int q, i, t;
	int a;
	double b;
	double ten = 0;

	a = (int)p;
	q = printf("%d\n", a);
	q = q - 1;
	system("cls");
	//printf("%d\n", q);
	for (i = 0; i < q; ++i)
	{
		t = a % 10;
		if (t >= 2)
		{
			system("cls");
			printf("input error,press any key to quit.....\n");
			exit(0);
		}
		ten = ten + t * pow(2, i);
		a = a / 10;
	}
	//printf("%lf\n",ten);
	b = p - (int)p;
	q = printf("%lf\n", b);
	q = q - 3;
	system("cls");
	//printf("%d\n", q);
	for (i = 1; i <= q; ++i)
	{
		t = (int)(b * 10);
		if (t >= 2)
		{
			system("cls");
			printf("input error,press any key to quit.....\n");
			exit(0);
		}
		ten = ten + t * pow(2, -i);
		b = b * 10 - t;
	}
	return ten;
}



/*十进制转二进制*/
double ten_two(double p)
{
	double two=0, b;
	int a, i;
	a = (int)p;
	for (i = 0; a / 2 != 0; ++i)
	{
		two = two + (a % 2) * pow(10, i);
		a = a / 2;
	}
	two = two + (a % 2) * pow(10, i);
	b = p - (int)p;
	for (i = 1; i <= 6; ++i)
	{
		two = two + (int)(2 * b) * pow(10, -i);
		b = 2 * b - (int)(2 * b);
	}
	return two;
}


/*八进制转十进制*/
double eight_ten(double p)
{
	int q, i, t;
	int a;
	double b;
	double ten = 0;

	a = (int)p;
	q = printf("%d\n", a);
	q = q - 1;
	system("cls");
	//printf("%d\n", q);
	for (i = 0; i < q; ++i)
	{
		t = a % 10;
		if (t >= 8)
		{
			system("cls");
			printf("input error,press any key to quit.....\n");
			exit(0);
		}
		ten = ten + t * pow(8, i);
		a = a / 10;
	}
	//printf("%lf\n",ten);
	b = p - (int)p;
	q = printf("%lf\n", b);
	q = q - 3;
	system("cls");
	//printf("%d\n", q);
	for (i = 1; i <= q; ++i)
	{
		t = (int)(b * 10);
		if (t >= 8)
		{
			system("cls");
			printf("input error,press any key to quit.....\n");
			exit(0);
		}
		ten = ten + t * pow(8, -i);
		b = b * 10 - t;
	}
	return ten;
}

/*十进制转八进制*/
double ten_eight(double p)
{
	double eight = 0, b;
	int a, i;
	a = (int)p;
	system("cls");
	for (i = 0; a / 8 != 0; ++i)
	{
		eight = eight + (a % 8) * pow(10, i);
		a = a / 8;
	}
	eight = eight  + (a % 8) * pow(10, i);
	b = p - (int)p;
	for (i = 1; i <= 6; ++i)
	{
		eight = eight + (int)(8 * b) * pow(10, -i);
		b = 8 * b - (int)(8 * b);
	}
	return eight;
}


/*十六进制转十进制*/
int sixteen_ten(char a[])
{
	system("cls");
	char* p, * q=NULL;
	int ten = 0, i,j,t;
	p = a;
	//printf("%d", ten);
	for (i = 0; *p != '\0' && *p != '.'; ++i,++p);
	//printf("%d\n", i);
	if (*p == '.')
	{
		system("cls");
		printf("本地仅支持16进制的整数转换，请重新输入......\n");
		printf("input error,press any key to quit.....\n");
		exit(0);
	}
	for (j = 0; i != 0; --i)
	{
		switch (*(--p))
		{
		case'1':t = 1; break;
		case'2':t = 2; break;
		case'3':t = 3; break;
		case'4':t = 4; break;
		case'5':t = 5; break;
		case'6':t = 6; break;
		case'7':t = 7; break;
		case'8':t = 8; break;
		case'9':t = 9; break;
		case'a':t = 10; break;
		case'b':t = 11; break;
		case'c':t = 12; break;
		case'd':t = 13; break;
		case'e':t = 14; break;
		case'f':t = 15; break;
		case'A':t = 10; break;
		case'B':t = 11; break;
		case'C':t = 12; break;
		case'D':t = 13; break;
		case'E':t = 14; break;
		case'F':t = 15; break;
		default:
		{
			system("cls");
			printf("input error,press any key to quit.....\n");
			exit(0);
		}
		}
		//printf("%d\n", j);
		ten = ten + t * pow(16, j);
		//printf("%d\n", ten);
		++j;
	}
	return ten;
}

/*十进制转十六进制*/
char* ten_sixteen(double p,char m[])
{
	char n[100];
	double  b;
	system("cls");
	char v;
	int a, i, j;
	a = (int)p;
	for (i = 0,j=0; a / 16 != 0||j!=1; ++i)
	{
		switch (a%16)
		{
		case 0:v='0'; break;
		case 1:v = '1'; break;
		case 2:v = '2'; break;
		case 3:v = '3'; break;
		case 4:v = '4'; break;
		case 5:v = '5'; break;
		case 6:v = '6'; break;
		case 7:v = '7'; break;
		case 8:v = '8'; break;
		case 9:v = '9'; break;
		case 10:v = 'A'; break;
		case 11:v = 'B'; break;
		case 12:v = 'C'; break;
		case 13:v = 'D'; break;
		case 14:v = 'E'; break;
		case 15:v = 'F'; break;
		}
		n[i] = v;
		a = a / 16;
		if (a == 0)
		{
			j++;
		}
	}
	i--;
	for (j = 0; i != 0; --i, ++j)
	{
		m[j] = n[i];
	}
	m[j] = n[i];
	m[++j] = '.';
	b = p - (int)p;
	for (j = j + 1, i = 0; j < 99; ++j)
	{
		switch ((int)(16 * b))
		{
		case 0:m[j] = '0'; ++i; break;
		case 1:m[j] = '1'; i = 0; break;
		case 2:m[j] = '2'; i = 0; break;
		case 3:m[j] = '3'; i = 0; break;
		case 4:m[j] = '4'; i = 0; break;
		case 5:m[j] = '5'; i = 0; break;
		case 6:m[j] = '6'; i = 0; break;
		case 7:m[j] = '7'; i = 0; break;
		case 8:m[j] = '8'; i = 0; break;
		case 9:m[j] = '9'; i = 0; break;
		case 10:m[j] = 'A'; i = 0; break;
		case 11:m[j] = 'B'; i = 0; break;
		case 12:m[j] = 'C'; i = 0; break;
		case 13:m[j] = 'D'; i = 0; break;
		case 14:m[j] = 'E'; i = 0; break;
		case 15:m[j] = 'F'; i = 0; break;
		}
		if (i > 6)
		{
			break;
		}
		b = 16 * b - (int)(16 * b);
	}
	m[j] = '\0';
	return m;
}

int main(void)
{
	int i, j;
	double p, p1;
	printf("Select the number system for the input number:\n");
	scanf_s("%d", &i);
	printf("Select the number system for the output number:\n");
	scanf_s("%d", &j);
	if (i == 2 && j == 10)
	{
		printf("please input a number:\n");
		scanf_s("%lf", &p);
		p1 = p;
		if (p < 0)
		{
			p = fabs(p);
			p = two_ten(p);
			printf("您输入的数为:\n%lf\n", p1);
			printf("二进制转十进制为:\n");
			printf("%lf\n", -p);
		}
		else
		{
			p = two_ten(p);
			printf("您输入的数为:\n%lf\n", p1);
			printf("二进制转十进制为:\n");
			printf("%lf\n", p);
		}
	}
	else if (i == 2 && j == 8)
	{
		printf("please input a number:\n");
		scanf_s("%lf", &p);
		p1 = p;
		if (p < 0)
		{
			p = fabs(p);
			p = two_ten(p);
			p = ten_eight(p);
			printf("您输入的数为:\n%lf\n", p1);
			printf("二进制转八进制为:\n");
			printf("%lf\n", -p);
		}
		else
		{
			p = two_ten(p);
			p = ten_eight(p);
			printf("您输入的数为:\n%lf\n", p1);
			printf("二进制转八进制为:\n");
			printf("%lf\n", p);
		}
	}
	else if (i == 2 && j == 16)
	{
		char a[100] = { NULL };
		char* q = NULL;
		printf("please input a number:\n");
		scanf_s("%lf", &p);
		p1 = p;
		if (p < 0)
		{
			p = fabs(p);
			p = two_ten(p);
			q = ten_sixteen(p, a);
			printf("您输入的数为:\n%lf\n", p1);
			printf("二进制转十六进制为:\n");
			printf("-%s\n", q);
		}
		else
		{
			p = two_ten(p);
			q = ten_sixteen(p, a);
			printf("您输入的数为:\n%lf\n", p1);
			printf("二进制转十六进制为:\n");
			printf("%s\n", q);
		}
	}
	else if (i == 10 && j == 2)
	{
		printf("please input a number:\n");
		scanf_s("%lf", &p);
		//system("cls");
		p1 = p;
		if (p < 0)
		{
			p = fabs(p);
			p = ten_two(p);
			printf("您输入的数为:\n%lf\n", p1);
			printf("十进制转二进制为:\n");
			printf("%lf\n", -p);
		}
		else
		{
			p = ten_two(p);
			printf("您输入的数为:\n%lf\n", p1);
			printf("十进制转二进制为:\n");
			printf("%lf\n", p);
		}
	}
	else if (i == 10 && j == 8)
	{
		printf("please input a number:\n");
		scanf_s("%lf", &p);
		//system("cls");
		p1 = p;
		if (p < 0)
		{
			p = fabs(p);
			p = ten_eight(p);
			printf("您输入的数为:\n%lf\n", p1);
			printf("十进制转八进制为:\n");
			printf("%lf\n", -p);
		}
		else
		{
			p = ten_eight(p);
			printf("您输入的数为:\n%lf\n", p1);
			printf("十进制转八进制为:\n");
			printf("%lf\n", p);
		}
	}
	else if (i == 10 && j == 16)
	{
		char a[100] = { NULL };
		char* q = NULL;
		printf("please input a number:\n");
		scanf_s("%lf", &p);
		//system("cls");
		p1 = p;
		if (p < 0)
		{
			p = fabs(p);
			q = ten_sixteen(p, a);
			printf("您输入的数为:\n%lf\n", p1);
			printf("十进制转十六进制为:\n");
			printf("-%s\n", q);
		}
		else
		{
			q = ten_sixteen(p, a);
			printf("您输入的数为:\n%lf\n", p1);
			printf("十进制转十六进制为:\n");
			printf("%s\n", q);
		}
	}
	else if (i == 8 && j == 2)
	{
		printf("please input a number:\n");
		scanf_s("%lf", &p);
		p1 = p;
		if (p < 0)
		{
			p = fabs(p);
			p = eight_ten(p);
			p = ten_two(p);
			printf("您输入的数为:\n%lf\n", p1);
			printf("八进制转二进制为:\n");
			printf("%lf\n", -p);
		}
		else
		{
			p = eight_ten(p);
			p = ten_two(p);
			printf("您输入的数为:\n%lf\n", p1);
			printf("八进制转二进制为:\n");
			printf("%lf\n", p);
		}
	}
	else if (i == 8 && j == 10)
	{
		printf("please input a number:\n");
		scanf_s("%lf", &p);
		p1 = p;
		if (p < 0)
		{
			p = fabs(p);
			p = eight_ten(p);
			printf("您输入的数为:\n%lf\n", p1);
			printf("八进制转十进制为:\n");
			printf("%lf\n", -p);
		}
		else
		{
			p = eight_ten(p);
			printf("您输入的数为:\n%lf\n", p1);
			printf("八进制转十进制为:\n");
			printf("%lf\n", p);
		}
	}
	else if (i == 8 && j == 16)
	{
		char a[100] = { NULL };
		char* q = NULL;
		printf("please input a number:\n");
		scanf_s("%lf", &p);
		p1 = p;
		if (p < 0)
		{
			p = fabs(p);
			p = eight_ten(p);
			q = ten_sixteen(p, a);
			printf("您输入的数为:\n%lf\n", p1);
			printf("八进制转十六进制为:\n");
			printf("-%s\n", q);
		}
		else
		{
			p = eight_ten(p);
			q = ten_sixteen(p, a);
			printf("您输入的数为:\n%lf\n", p1);
			printf("八进制转十六进制为:\n");
			printf("%s\n", q);
		}
	}
	else if (i == 16 && j == 2)
	{
	char a[100] = { NULL };
	int t;
	printf("please input a number:\n");
	scanf_s("%s", a, sizeof(a));
	a[sizeof(a) - 1] = '\0';
	t = strlen(a);
	//printf("%d",t);
	a[t] = '\0';
	if (a[0] == '-')
	{
		for (t = 0; a[t] != '\0'; ++t)
		{
			a[t] = a[t + 1];
		}
		p = sixteen_ten(a);
		p = ten_two(p);
		printf("您输入的数为:\n%s\n", a);
		printf("十六进制转二进制为:\n");
		printf("%lf\n", -p);
	}
	else
	{
		p = sixteen_ten(a);
		p = ten_two(p);
		printf("您输入的数为:\n%s\n", a);
		printf("十六进制转二进制为:\n");
		printf("%lf\n", p);
	}
 }
	else if (i == 16 && j == 8)
	{
	char a[100] = { NULL };
	int t;
	printf("please input a number:\n");
	scanf_s("%s", a, sizeof(a));
	a[sizeof(a) - 1] = '\0';
	t = strlen(a);
	//printf("%d",t);
	a[t] = '\0';
	if (a[0] == '-')
	{
		for (t = 0; a[t] != '\0'; ++t)
		{
			a[t] = a[t + 1];
		}
		p = sixteen_ten(a);
		p = ten_eight(p);
		printf("您输入的数为:\n-%s\n", a);
		printf("十六进制转八进制为:\n");
		printf("%lf\n", -p);
	}
	else
	{
		p = sixteen_ten(a);
		p = ten_eight(p);
		printf("您输入的数为:\n%s\n", a);
		printf("十六进制转八进制为:\n");
		printf("%lf\n", p);
	}
 }
	else if (i == 16 && j == 10)
	{
		char a[100] = { NULL };
		int t;
		printf("please input a number:\n");
		scanf_s("%s", a, sizeof(a));
		a[sizeof(a) - 1] = '\0';
		t = strlen(a);
		//printf("%d",t);
		a[t] = '\0';
		if (a[0] == '-')
		{
			for (t = 0; a[t] != '\0'; ++t)
			{
				a[t] = a[t + 1];
			}
			p = sixteen_ten(a);
			printf("您输入的数为:\n-%s\n", a);
			printf("十六进制转十进制为:\n");
			printf("%lf\n", -p);
		}
		else
		{
			p = sixteen_ten(a);
			printf("您输入的数为:\n%s\n", a);
			printf("十六进制转十进制为:\n");
			printf("%lf\n", p);
		}
	}
	else
	{
		printf("本地不支持该数制的转换，请重新输入......\n");
		printf("input error,press any key to quit....\n");
		exit(0);
	}
}