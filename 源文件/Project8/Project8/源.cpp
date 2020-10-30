#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int * p;
    int	num, i, j;
	printf("输入空间大小：");
	scanf_s("%d",&num);
	p = (int*)malloc(num * sizeof(int));
	if (p == NULL)
	{
		printf("开辟空间出错！！");
		exit(0);
	}
	
	for (i = 0; i < num; i++)
	{
          printf("输入第%d个数字：",i+1);
		  scanf_s("%d",&p[i]);
	}
	
	printf("输出数字：\n");
	for(i=num-1;i>=0;i--)
	printf("%d   ",p[i]);
	free(p);
}
