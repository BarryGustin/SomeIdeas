#include <stdio.h>                                //总体上采用调用函数的思路。
#include <string.h>                               // 首先总结需要处理的问题：
#include <stdlib.h>                               //1、解决用户乱输的问题，如超位问题，
#include <ctype.h>                                //2、用户输入不满足罗马数字语法问题：如MMMM的4M问题，大数如M出现在小数D或X等其他数后面的问题。
int enterm(int sum,char* p)                       //3、字母小写问题。
{                                                 //以上每个问题都会引发众多并行小问题，会在后面的注释中依次解答。
	int i;
	for (i=0;i<5; ++i,++p)                       //首先解释M函数     
	{                                            //为防止在出现M后的后面连续3个M同时出现的情况，故在该位后遍历后3位，
		if (*p == 'M');
		else break;                         
	}
	if (!(i - 4))
	{
		printf("input error,press any key to quit.....\n");
		exit(0);                         //查看是否与前数M一致，若一致，直接报错终止程序。
	}
	else sum += 1000;                    //如果没有连续4位，则累加器加上该字母对应的数。
	return sum;                          //提供一个返回值。
}

int enterd(int sum, char* p)             //解释D函数    
{
	char* q;                             //首先保留初始位置，
	q = p;
	for (;*p!='\0'; ++p)                 //遍历其后的字母，不能使得比D大的M出现。
	{
		if (*p == 'M')
		{
			printf("input error,press any key to quit.....\n");
			exit(0);
		}
	}
	p = q;                               //将指针拉回
	int i;
	for (i = 0; i < 5; ++i, ++p)         //遍历其后的字母
	{
		if (*p == 'D');                  //为防止在出现D后的后面连续3个D同时出现的情况，故在该位后遍历后3位，
		else break;
	}
	if (!(i - 4))                        //查看是否与前数M一致，若一致，直接报错终止程序。
	{
		printf("input error,press any key to quit.....\n");
		exit(0);
	}
	else sum += 500;                     //如果没有连续4位，则累加器加上该字母对应的数。
	return sum;                          //提供一个返回值。
}

int enterc(int sum, char* p)             //解释C函数  因为C函数有特殊点，要与其后的D或M，如果有，则涉及到两个字母合起来表达一个数的问题
{                                        //故要使得作如下处理。
	int i;
	char* q;                             //首先保留初始位置，
	q = p;
	switch (*(++p))                      //在初始位置的基础上，指向下一个字母，分类讨论。
	{
	case 'D':sum += 400; 
		for (; *p != '\0'; ++p)          
		{
			*p = *(p + 1);               //如下一字母为D，将D消除，防止在主函数中继续累加D的值。
		}
		break;

	case 'M':sum += 900;
		for (; *p != '\0'; ++p)
		{
			*p = *(p + 1);               //如下一字母为M，将M消除，防止在主函数中继续累加M的值。
		}
		break;

	case'C':                            //如下一字母为C,为防止在出现C后的后面连续3个C同时出现的情况，故在该位后遍历后3位，
		
		for (i = 0; i < 4; ++i, ++p)
		{
			if (*p == 'C');
			else break;
		}
		if (!(i - 3))                  //查看是否与前数C一致，若一致，直接报错终止程序。
		{
			printf("input error,press any key to quit.....\n");
			exit(0);
		}
		else sum += 100;               //如果没有连续4位，则累加器加上该字母对应的数。
		break;                         
	
	default:sum += 100; break;         ////如果下一位并不是以上3种情况，则因为该位出现了C，则也应该在累加器上加C对应的数字。//
	}
	for (p=q; *p != '\0'; ++p)
	{
		if (*p == 'M'||*p=='D')        //遍历其后的字母，不能使得比C大的M和D出现。
		{
			printf("input error,press any key to quit.....\n");
			exit(0);
		}
	}
	return sum;                       //提供一个返回值。
}

int enterl(int sum, char* p)         ////同理于D函数
{
	char* q;
	q = p;
	for (; *p != '\0'; ++p)
	{
		if (*p == 'M'||*p=='D'||*p=='C')
		{
			printf("input error,press any key to quit.....\n");
			exit(0);
		}
	}
	p = q;
	int i;
	for (i = 0; i < 5; ++i, ++p)
	{
		if (*p == 'L');
		else break;
	}
	if (!(i - 4))
	{
		printf("input error,press any key to quit.....\n");
		exit(0);
	}
	else sum += 50;
	return sum;
}

int enterx(int sum, char* p)                            ////同理于C函数
{
	char* q;
	q = p;
	switch (*(++p))
	{
	case 'L':sum += 40;
		for (; *p != '\0'; ++p)
		{
			*p = *(p + 1);
		}
		break;

	case 'C':sum += 90; 
		for (; *p != '\0'; ++p)
		{
			*p = *(p + 1);
		}
		break;

	case'X':
		int i;
		for (i = 0; i < 4; ++i, ++p)
		{
			if (*p == 'X');
			else break;
		}
		if (!(i - 3))
		{
			printf("input error,press any key to quit.....\n");
			exit(0);
		}
		else sum += 10;
		break;

	default: sum += 10; break;
	}
	for (p=q; *p != '\0'; ++p)
	{
		if (*p == 'M' || *p == 'D'||*p=='C'||*p=='L')
		{
			printf("input error,press any key to quit.....\n");
			exit(0);
		}
	}
	return sum;
}

int enterv(int sum, char* p)                                ////同理于D函数
{
	char* q;
	q = p;
	for (; *p != '\0'; ++p)
	{
		if (*p == 'M'||*p=='D'||*p=='C'||*p=='L'||*p=='X')
		{
			printf("input error,press any key to quit.....\n");
			exit(0);
		}
	}
	p = q;
	int i;
	for (i = 0; i < 5; ++i, ++p)
	{
		if (*p == 'D');
		else break;
	}
	if (!(i - 4))
	{
		printf("input error,press any key to quit.....\n");
		exit(0);
	}
	else sum += 5;
	return sum;
}

int enteri(int sum, char* p)                             ////同理于C函数
{
	char* q;
	q = p;
	switch (*(++p))
	{
	case 'V':sum += 4;
		for (; *p != '\0'; ++p)
		{
			*p = *(p + 1);
		}
		break;

	case 'X':sum += 9;
		for (; *p != '\0'; ++p)
		{
			*p = *(p + 1);
		}
		 break;

	case'I':
		int i;
		for (i = 0; i < 4; ++i, ++p)
		{
			if (*p == 'I');
			else break;
		}
		if (!(i - 3))
		{
			printf("input error,press any key to quit.....\n");
			exit(0);
		}
		else sum += 1;
		break;

	default: sum += 1; break;
	}
	for (p=q; *p != '\0'; ++p)
	{
		if ((*p == 'M') ||( *p == 'D')|| (* p == 'C') || (*p == 'L') ||( *p == 'X')||(*p=='V'))
		{
			printf("input error,press any key to quit.....\n");
			exit(0);
		}
	}
	return sum;
}
int main(void)
{
	char a[15];                                             //定义a数组存罗马数字
	char* p=a;                                              //指它
	int i, sum = 0,j=0;                                     //定义累加器sum
	printf("please input a Arabic number:\n");
	scanf_s("%s",a,sizeof(a));
	system("cls");
	a[14] = 0;
	j = strlen(a);                                          //测输入字母个数

	if (!(j - 0))                                           //如超过（胡输），或没输入，则会报错
	{
		printf("input error,press any key to quit.....\n");
		exit(0);
	}

	for (i = 0; i < j; ++i, ++p);                           //封住字符串
	(++p) = '\0';
	for (i=0,p=a; *p != '\0';++i,++p)                       //加入输入小写后的转换大写功能
	{
		a[i] = toupper(*p);      
	}
	for (p = a; *p != '\0'; ++p)                            //遍历每一个字符，并处理，变为对应数字，加入累加器。
	{
		switch (*p)
		{
		case 'M': sum=enterm( sum, p); break;
		
		case 'D':sum=enterd(sum, p); break;
		
		case 'C':sum = enterc(sum, p);break;
			
		case 'L':sum = enterl(sum, p); break;
		
		case 'X':sum = enterx(sum, p); break;
		
		case 'V':sum = enterv(sum, p); break;

		case 'I':sum = enteri(sum, p); break;
		
		default:printf("input error,press any key to quit.....\n"); exit(0);
		}
	}
	if (sum > 3999)                                //因为该函数最大值为M，故当表示4000时会有另外的字母组合
	{                                             //而不能用现有的字母组合，如组合，则不可能符合语法规则，
		printf("input error,press any key to quit.....\n");                    //故而规定值域。
		exit(0);
	}
	printf("output a number:\n");
	printf("%d\n", sum);
}