#include <stdio.h>
int main(void)
{
	double profit;
	printf ("请输入总利润：");
	scanf_s("%lf", &profit);
	printf ("所获提成：");
	if (profit <= 100000)printf("bon=%lf", profit * 0.1);
	else if (profit <= 200000)printf("bon=%lf", (profit - 100000) * 0.075 + 10000);
	else if (profit <= 400000)printf("bon=%lf", (profit - 200000) * 0.05 + 17500);
	else if (profit <= 600000)printf("bon=%lf", (profit - 400000) * 0.03 + 27500);
	else if (profit <= 1000000)printf("bon=%lf", (profit - 600000) * 0.015 + 33500);
	else
		printf("bon=%lf", (profit - 1000000) * 0.01 + 39500);
}