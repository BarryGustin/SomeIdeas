#include <stdio.h>
float add(float*);
void com(float(* p)[4], int);
void search(float(*p)[4]);
int main(void)
{
	float a[3][4];
	float * p;
	float (*n)[4];
	int i,j;
	for (i = 0; i < 3; i++)
	{
		printf("请输入第%d个学生的成绩：\n",i+1);
		for (j = 0; j < 4; j++)
		{
			scanf_s("%f",&a[i][j]);
		}
	}
	p = a[0];
	n = a;
	printf("输出平均分：\n");
	printf("%f\n",add(p)/12);
	com(n, 1);
	search(n);
}
float add(float* a)
{
	int i,sum=0;
	for (i = 0; i < 12; i++, a++)
	{
		sum += *a;
	}
	return sum;
}
void com(float(*p)[4], int x)
{
	int i;
	printf("第二个学生的成绩为：\n");
	for (i = 0; i < 4; i++)
	{
		printf("%f\t",*(*( p+x)+i));
	}
	printf("\n");
}

/*void search(float(*p)[4])
{
	int i, out, j, loop;
	for (i = 0; i < 3; i++) {
		out = 0;
		for (j = 0; j < 4; j++) {
			if (*(*(p + i) + j) < 60) {
				out++;
			}
		}
		if (out >= 2) {
			printf("第%d个学生的成绩有一门以上不及格，输出成绩：\n", i + 1);
			for (loop = 0; loop < 4; loop++) {
				printf("%f\t", *(*(p + i) + loop));
			}
		}
		printf("\n");
	}
}*/