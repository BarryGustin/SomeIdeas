#include <stdio.h>               //������ظ��ַ�����Ӵ�����
#include <stdlib.h>              //1.ɨ���ַ���������ظ��ַ����⡣
#include <string.h>              //2.������ڵ��ַ��ظ�������
int main(void)
{
	char a[100];
	char* p, * q, * m, * n;
	int i, j;
	printf("please input a string:\n");
	scanf_s("%s",a,sizeof(a));
	a[sizeof(a)-1] = '\0';
	p = q = m = n = a;
	i = j = 1;
	while (*(++p) != '\0')           //ɨ���ַ���
	{
		if (*p != *q)                //���ڵ��ַ�������ȣ����н������Ĵ���
		{
			i = 1;                   //����
			m = n;
			while (m != p)           //��mɨ����һ�����������ַ�����ͬ���ַ���
			{
				if (*(m++) != *p)    //���½����ַ������ַ���һ��ʱ������
				{
					++i;
				}
				else                 //һ��ʱ���ַ���ͷ������λ��
					n = p;
			}
		}
		else                        //���������ַ�һ��ʱ����
		{
			if (i > j)
				j = i;
			i = 1;
			n = p;
		}
		if (i > j)                  //ÿ��ѭ������ʱ�Ĵ���ȡ����������ζ���
			j = i;
		q = p;
	}
	printf("%d\n",j);
}