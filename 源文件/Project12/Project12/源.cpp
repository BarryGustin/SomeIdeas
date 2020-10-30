#include <stdio.h>
void put(int n[][5]);
void out(int p[][5]);
void stu_ave(int p[10][5]);
void class_ave(int p[10][5]);
int max_stu_cla(int p[10][5]);
void put_sty_cla(int n[10][5], int y);
void ave_spr(int p[10]);
int av[10];
int main(void)
{
	int a[10][5];
	put(a);
	out(a);
	stu_ave(a);
	class_ave(a);
	put_sty_cla(a, max_stu_cla(a));
    ave_spr(av);
}
void put(int n[][5])
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		printf("请输入第%d个学生的成绩：\n",i+1);
		for (j = 0; j < 5; j++)
		{
			scanf_s("%d", &n[i][j]);
			
		}
		printf("\n");
	}
}

void out(int p[][5])
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		printf("请输出第%d个学生的成绩：\n", i + 1);
		for (j = 0; j < 5; j++)
		{
			printf("%d\t",p[i][j]);

		}
		printf("\n");
	}
}
void stu_ave(int p[10][5])
{
	int i, j,aver;
	for (i = 0; i < 10; i++)
	{
		aver = 0;
		for (j = 0; j < 5; j++)
		{
			aver=aver+p[i][j];
		}
		aver = aver / 5;
		av[i] = aver;
		printf("第%d个学生的平均成绩：",i + 1);
		printf("%d\n",aver);
	}
}



void class_ave(int p[10][5])
{
	int i, j, aver;
	for (i = 0; i < 5; i++)
	{
		aver = 0;
		for (j = 0; j < 10; j++)
		{
			aver =aver+ p[j][i];
		}
		aver = aver /10;
		printf("第%d门课的平均成绩：", i + 1);
		printf("%d\n", aver);
	}
}

     
	

	void put_sty_cla(int n[10][5],int y)
	{

		int i, j;
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 5; j++)
			{
				if (y == n[i][j])
				{
					printf("最好成绩为第%d个学生的第%d门的成绩\n", i + 1, j + 1);
				}
				
			}
		}
	}
	
	void ave_spr(int p[10])
	{
		int i,sum1=0,sum2=0;
		for (i = 0; i < 10; i++)
		{
			sum1 += p[i] * p[i];
			sum2 += p[i];
		}
		printf("平均分方差：\n");
		printf("%d\n",sum1/10+sum2/100);
	}