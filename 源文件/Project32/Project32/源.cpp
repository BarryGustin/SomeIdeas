#include <stdio.h>                /*纸牌游戏——小猫钓鱼问题注释*/
#include <stdlib.h>               /*需解决的问题有：1.建立两个人*/    /*4.第一个人放第一张牌*/
#include <string.h>               /*2.建立一个桌子*/     /*5.然后第二人放牌，依次交替*/   
                                  /*3.两个人拿牌*/       /*6.一个人放下牌后，检索桌上的牌遇到相同的，将相同及两牌中间的牌全拿走*/

                                  /*想法：用队列当做人，从head出牌，从tail拿牌接入队列。用栈当桌子，从栈顶放牌拿牌*/

typedef struct queue              /*建立结构体（关于主函数中建立人）*/
{
	int date[100];
	int head;
	int tail;
}line;


typedef struct sta                /*建立结构体（关于主函数中建立桌子）*/
{
	int* top;                     /*栈顶（指向放牌）*/
	int* bottom;                  /*栈底（指向牌底）*/
	int* cil;                     /*转牌（寻找桌上与栈顶牌相同的牌）*/
	int* etop;                    /*定牌（将桌上与栈顶牌相同的牌的位置记下，便于人a,b从桌上拿牌）*/
}desk;



line get_date();                              /*初始化队列*/
desk InitStack();                             /*初始化栈*/
int change_a( );                              /*开始往桌上放牌的开关函数*/
int change_b( );                              /*b出牌  从桌上拿牌*/
int change_a1( );                             /*a出牌  从桌上拿牌*/


line a, b;               /*定义外部变量a,b,c（对应主函数中初始化变量226）*/
desk c;


/*   初始化队列   */
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


/*  初始化栈  */
desk InitStack()
{
	desk p;
	p.bottom = (int*)malloc(10 * sizeof(int));
	if (p.bottom == NULL)
	{
		printf("初始化栈失败\n");
		exit(0);
	}
	p.top = p.cil = p.etop = p.bottom;
	return p;
}


/*  开始往桌上放牌的开关函数    */
int change_a( )
{
	int x=2,i=0;
	
	*c.top = a.date[a.head];            /*将牌放入桌上*/
	a.head++;
	c.cil = c.bottom;                   /*将转牌指针拉到栈底*/
	while (c.top != c.cil)
	{
		if (*c.top == *c.cil)           /*寻找桌上与栈顶牌相同的牌*/
		{
			c.etop = c.cil;             /*将桌上与栈顶牌相同的牌的位置记下，便于人a,b从桌上拿牌*/
			break;
		}
		c.cil++;
	}
	if (c.top != c.cil)                 /*如果有，top向下转到etop处*/
	{
		for (; c.top != c.etop; c.top--)
		{
			a.date[a.tail++] = *c.top;  /*将桌上的牌拿出到人a,b的手中*/
		}
		a.date[a.tail++] = *c.top;
	}
	else
	{
		//printf("%d\n", c.top);
		//printf("%d\n", c.bottom);
		c.top++;                         /*如果无，准备接受下一人的出牌*/
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
	if (x == 0)                      /*如返回值为0，则b手中无牌，a胜*/
	{
		return 1;
	}
	if (x == 1)                      /*如返回值为1，则a手中无牌，a输*/
	{
		return 0;
	}
}


/*  b出牌  从桌上拿牌  */
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
	if (b.head == b.tail)                       /*如果b手中无牌，返回0*/
	{
		return 0;
	}
	//printf("%d %d\n",a.date[a.head],a.date[a.head+1]);
	return 2;
}


/*   a出牌  从桌上拿牌   */
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

	if (a.head == a.tail)                     /*如果a手中无牌，返回1*/
	{
		return 1;
	}
	return 2;
}


int main(void)
{
	int i;
	int m;
	extern line a, b;                     /*把外部变量a,b,c的作用域扩展到从此处开始*/
	a = get_date();
	b = get_date();
	extern desk c;
	c = InitStack();
	m=change_a();
	if (m == 1)
	{
		printf("a获胜\n");
		printf("a手中的数:\n");
		for (i = a.head; i < a.tail; ++i)
		{
			printf("%d\t",a.date[i]);
		}
		printf("\n桌上的数:\n");
		for (; c.bottom != c.top; c.bottom++)
		{
			printf("%d\t",*c.bottom);
		}
	}
	else
	{
		printf("b获胜\n");
		printf("b手中的数:\n");
		for (i = b.head; i < b.tail; ++i)
		{
			printf("%d\t", b.date[i]);
		}
		printf("\n桌上的数:\n");
		for (; c.bottom != c.top ; c.bottom++)
		{
			printf("%d\t", *c.bottom);
		}
	}
}