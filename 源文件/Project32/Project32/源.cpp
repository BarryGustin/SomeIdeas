#include <stdio.h>                /*ֽ����Ϸ����Сè��������ע��*/
#include <stdlib.h>               /*�����������У�1.����������*/    /*4.��һ���˷ŵ�һ����*/
#include <string.h>               /*2.����һ������*/     /*5.Ȼ��ڶ��˷��ƣ����ν���*/   
                                  /*3.����������*/       /*6.һ���˷����ƺ󣬼������ϵ���������ͬ�ģ�����ͬ�������м����ȫ����*/

                                  /*�뷨���ö��е����ˣ���head���ƣ���tail���ƽ�����С���ջ�����ӣ���ջ����������*/

typedef struct queue              /*�����ṹ�壨�����������н����ˣ�*/
{
	int date[100];
	int head;
	int tail;
}line;


typedef struct sta                /*�����ṹ�壨�����������н������ӣ�*/
{
	int* top;                     /*ջ����ָ����ƣ�*/
	int* bottom;                  /*ջ�ף�ָ���Ƶף�*/
	int* cil;                     /*ת�ƣ�Ѱ��������ջ������ͬ���ƣ�*/
	int* etop;                    /*���ƣ���������ջ������ͬ���Ƶ�λ�ü��£�������a,b���������ƣ�*/
}desk;



line get_date();                              /*��ʼ������*/
desk InitStack();                             /*��ʼ��ջ*/
int change_a( );                              /*��ʼ�����Ϸ��ƵĿ��غ���*/
int change_b( );                              /*b����  ����������*/
int change_a1( );                             /*a����  ����������*/


line a, b;               /*�����ⲿ����a,b,c����Ӧ�������г�ʼ������226��*/
desk c;


/*   ��ʼ������   */
line get_date()
{
	line a;
	int n, i;
	printf("How many number do you want to enter:\n");
	scanf_s("%d",&n);
	for (i = 0; i < n; ++i)
	{
		printf("please input a number:\n");
		scanf_s("%d",&a.date[i]);
	}
	a.head = 0;
	a.tail = n ;
	return a;
}


/*  ��ʼ��ջ  */
desk InitStack()
{
	desk p;
	p.bottom = (int*)malloc(10 * sizeof(int));
	if (p.bottom == NULL)
	{
		printf("��ʼ��ջʧ��\n");
		exit(0);
	}
	p.top = p.cil = p.etop = p.bottom;
	return p;
}


/*  ��ʼ�����Ϸ��ƵĿ��غ���    */
int change_a( )
{
	int x=2,i=0;
	
	*c.top = a.date[a.head];            /*���Ʒ�������*/
	a.head++;
	c.cil = c.bottom;                   /*��ת��ָ������ջ��*/
	while (c.top != c.cil)
	{
		if (*c.top == *c.cil)           /*Ѱ��������ջ������ͬ����*/
		{
			c.etop = c.cil;             /*��������ջ������ͬ���Ƶ�λ�ü��£�������a,b����������*/
			break;
		}
		c.cil++;
	}
	if (c.top != c.cil)                 /*����У�top����ת��etop��*/
	{
		for (; c.top != c.etop; c.top--)
		{
			a.date[a.tail++] = *c.top;  /*�����ϵ����ó�����a,b������*/
		}
		a.date[a.tail++] = *c.top;
	}
	else
	{
		//printf("%d\n", c.top);
		//printf("%d\n", c.bottom);
		c.top++;                         /*����ޣ�׼��������һ�˵ĳ���*/
		//printf("%d\n", c.top);
		//printf("%d\n", c.bottom);
	}
	if (a.head == a.tail)
	{
		return 0;
	}
	++i;
	for (; x != 1 && x != 0; ++i)
	{
		//printf("%d\n",x);
		if ((i % 2)==1)
		{
			x = change_b( );          
		}
		else
		{
			x = change_a1( );
		}
	}
	if (x == 0)                      /*�緵��ֵΪ0����b�������ƣ�aʤ*/
	{
		return 1;
	}
	if (x == 1)                      /*�緵��ֵΪ1����a�������ƣ�a��*/
	{
		return 0;
	}
}


/*  b����  ����������  */
int change_b( )
{
	
	*c.top = b.date[b.head];
	b.head++;
	c.cil = c.bottom;
	while (c.top != c.cil)
	{
		if (*c.top == *c.cil)
		{
			c.etop = c.cil;
			break;
		}
		c.cil++;
	}
	if (c.top != c.cil)
	{
		for (; c.top != c.etop; c.top--)
		{
			b.date[b.tail++] = *c.top;
			//printf("%d\n",c.top);
		}
		b.date[b.tail++] = *c.top;
		//printf("%d\n", c.top);
		//printf("%d\n", c.bottom);
	}
	else
	{
		///printf("%d\n", c.top);
		//printf("%d\n", *c.bottom);
		c.top++;
		//printf("%d\n", c.top);
		//printf("%d\n", *c.bottom);
	}
	if (b.head == b.tail)                       /*���b�������ƣ�����0*/
	{
		return 0;
	}
	//printf("%d %d\n",a.date[a.head],a.date[a.head+1]);
	return 2;
}


/*   a����  ����������   */
int change_a1( )
{
	//c.top;
	//printf("%d %d\n", a.date[a.head]);
	//printf("%d\n", c.top);
	//printf("%d\n", c.bottom);
	*c.top = a.date[a.head];
	//printf("%d\n", c.top);
	//printf("%d\n", c.bottom);
	//printf("%d\n", *c.bottom);
	a.head++;
	c.cil = c.bottom;
	while (c.top != c.cil)
	{
		if (*c.top == *c.cil)
		{
			c.etop = c.cil;
			break;
		}
		c.cil++;
	}
	//printf("%d\n", c.top);
	//printf("%d\n", c.bottom);
	if (c.top != c.cil)
	{
		for (; c.top != c.etop; c.top--)
		{
			a.date[a.tail++] = *c.top;
		}
		a.date[a.tail++] = *c.top;
	}
	
	else
	{
		c.top++;
	}
	//printf("%d\n", c.top);
	//printf("%d\n", c.bottom);

	if (a.head == a.tail)                     /*���a�������ƣ�����1*/
	{
		return 1;
	}
	return 2;
}


int main(void)
{
	int i;
	int m;
	extern line a, b;                     /*���ⲿ����a,b,c����������չ���Ӵ˴���ʼ*/
	a = get_date();
	b = get_date();
	extern desk c;
	c = InitStack();
	m=change_a();
	if (m == 1)
	{
		printf("a��ʤ\n");
		printf("a���е���:\n");
		for (i = a.head; i < a.tail; ++i)
		{
			printf("%d\t",a.date[i]);
		}
		printf("\n���ϵ���:\n");
		for (; c.bottom != c.top; c.bottom++)
		{
			printf("%d\t",*c.bottom);
		}
	}
	else
	{
		printf("b��ʤ\n");
		printf("b���е���:\n");
		for (i = b.head; i < b.tail; ++i)
		{
			printf("%d\t", b.date[i]);
		}
		printf("\n���ϵ���:\n");
		for (; c.bottom != c.top ; c.bottom++)
		{
			printf("%d\t", *c.bottom);
		}
	}
}