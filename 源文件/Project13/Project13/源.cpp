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
		printf("�������%d��ѧ���ĳɼ���\n",i+1);
		for (j = 0; j < 4; j++)
		{
			scanf_s("%f",&a[i][j]);
		}
	}
	p = a[0];
	n = a;
	printf("���ƽ���֣�\n");
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
	printf("�ڶ���ѧ���ĳɼ�Ϊ��\n");
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
			printf("��%d��ѧ���ĳɼ���һ�����ϲ���������ɼ���\n", i + 1);
			for (loop = 0; loop < 4; loop++) {
				printf("%f\t", *(*(p + i) + loop));
			}
		}
		printf("\n");
	}
}*/