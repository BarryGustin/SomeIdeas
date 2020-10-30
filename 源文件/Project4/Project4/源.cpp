#include <stdio.h>
int main(void)
{
	int s[10];
	int j, i,t;
	for (i = 0; i < 10; i++)
	{
		printf("请输入%d个数：",i+1);
		scanf_s("%d",&s[i]);
	}
	printf("排序结果：");
	for (j = 0; j < 10; j++)
	{
		for (i = 0; i < 9-j; i++)
		{
			if (s[i] < s[i + 1])
			{
				t = s[i];
				s[i] = s[i+1];
				s[i+1] = t;
			}
		}
		printf("%d      ",s[i]);
	}
}