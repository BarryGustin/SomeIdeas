#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int * p;
    int	num, i, j;
	printf("����ռ��С��");
	scanf_s("%d",&num);
	p = (int*)malloc(num * sizeof(int));
	if (p == NULL)
	{
		printf("���ٿռ������");
		exit(0);
	}
	
	for (i = 0; i < num; i++)
	{
          printf("�����%d�����֣�",i+1);
		  scanf_s("%d",&p[i]);
	}
	
	printf("������֣�\n");
	for(i=num-1;i>=0;i--)
	printf("%d   ",p[i]);
	free(p);
}
