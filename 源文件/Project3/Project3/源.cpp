#include <stdio.h>
int main(void)
{
	int i, humnum1, humnum2, humnum3, humnum4, humnum5;
	double pro,agg,sum;
	sum = 0;
	humnum1 = 0; 
	humnum2 = 0; 
	humnum3 = 0; 
	humnum4 = 0;
	humnum5 = 0;
	for (i = 1; i <= 50; i++)
	{
		printf("请输入第%d个学生的成绩：\n",i);
		scanf_s("%d",&agg);
		sum =sum+ agg;
		if (agg < 60)printf("%d", humnum1++);
		else if (agg < 70)printf("%d", humnum2++);
		else if (agg < 80)printf("%d", humnum3++);
		else if (agg < 90)printf("%d", humnum4++);
		else if (agg <=100)printf("%d", humnum5++);
	}
	pro = sum / 50;
	printf("C语言平均成绩：%lf",pro);
	printf("60分一下：%d\n60-69分：%d\n70-79分：%d\n80-89分：%d\n90-100分：%d\n", humnum1, humnum2, humnum3, humnum4, humnum5);
}