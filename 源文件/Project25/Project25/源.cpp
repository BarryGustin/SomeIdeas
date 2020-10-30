#include <stdio.h>                           //螺旋矩阵问题分析如下：      
#include <math.h>                            //1.核心算法的建立，数字的矩阵式排列。         
#include<stdlib.h>                           //2.输出数字的间隔算法，保证用户的视觉效果。
int test_digit(int n)                        //3.测数字位数函数的建立。
{                                            //4.调用函数sqrt 测矩阵阶数。
	int i = 0, j = n;
	for (i = 0; j != 0; i++)                 //测数字位数函数的建立。
	{
		j = j / 10;                 
	}
	return i;
}
int main(void)
{
	int x, y, i, j, num = 0,q;
	double n, m;
	int* p[100] = { NULL };                                 //思路：开辟空间，建立二维数组，放入数字。
	printf("please input a number:\n");                     //因为空间为动态变化，故不能直接定义b[][]这样的二维数组。
	scanf_s("%lf", &n);                                     //故定义指针数组。并赋NULL
	m = sqrt(n);
	x = (int)n;
	y = (int)m;
	system("cls");                                          //清屏
	if (!x)                                                 //如n为0，报错
	{
		printf("input error,press any key to quit.....\n");
		exit(0);
	}
	if (m - y)                                              //用户乱输，报错
	{
		printf("input error,press any key to quit.....\n");
		exit(0);
	}
	for (i = 0; i < y; ++i)
	{
		p[i] = (int*)malloc(sizeof(int) * y);               //给指针开辟空间指向首地址
		if(p[i]==NULL)
		{ 
		printf("out of memory,press any key to quit.....\n");
		exit(0);
		}
	}
	//                    核心算法解释
	/*5阶螺旋矩阵可判断层数 k - N / 2 = 2, 用循环控制产

		生的层数, C语句为for(k = 0; k <= N / 2; k++); 。
		                                                                         将函数按照顺时针分为4个部分，如5阶 1.为上半部分
		步骤1 : 寻找矩阵上半边行的规律(-方向), 行下标.                            2.右部分 3.下部分  4.左部分

		正好是层数k的值0.1.2), 列下标在第 - 列从0变到4,

		第二行从1变到3, 在第三行从2变到2, 故得出N阶螺旋

		矩阵上半边从左到右的列循环结构为 : for (j = k; j <= N

			- k - 1; j++)a[kJj] = num++; 该循环执行 - 次将产

		生 - -行元素, 而循环执行的次数由外层循环来予以控制,

		当N = 5时, 层数h从0自增至2, 循环执行共3次, 将产

		生螺旋矩阵的上半边3行元素。

		步骤2 : 寻找矩阵右半边列的规律(↓方向), 列下标

		从4变到3, 行下标由外到内第 - 列从1变到3, 第二列从

		2变到2, 由此得出N阶螺旋方阵右半边列从上到下的循

环结构为 : for (i = k + 1; i < N - k - 1; i++)a[i][N - k -1] = num++; 当N = 5时, 层数k从0自增至2, 该循环;

	    执行2次, 产生矩阵右半边两列元素。

		步骤3 : 寻找矩阵下半边行的规律(方向), 列下标

		第 - 行从4变化到1，第二行从3变到2, 因此可知行标和

		列标的初值均为N - -k - -1, ，行标没有变化, 两行的行标分

		别为4和3 ,故得出矩阵下半边的行从右到左的循环结构

        为:for(j=N-k-1;j>k;j--)a[N-k-1][j]= num

        ++ ;当N=5时,层数h从0自增至2 ,该循环执行2次,

        产生矩阵下半边两行元素。

         步骤4:寻找矩阵左半边行规律(↑方向):经观察发

         现,列下标刚好可用层次k来表示,，列下标从0变到1 ,行

         下标由外到内第一列从4变到1,第二列从3变到2,因此

        可得出左半边的列从下至上的循环结构为:for(i=N-k

       - 1;i>k;i--)a[i]Dk]= num++;当N=5时,层数k

         从0自增至2 ,循环执行2次,产生矩阵左半边两列元素。

         当用户输入螺旋矩阵的阶数N的值时,层数k确定,

         当kh取-一个值时,以上4个循环依序产生一行或者- -列矩

        阵元素,当h值在0至N/2范围内依次取值时,4个循环

          轮流执行,k值取完后,螺旋矩阵构造完成。
		  
		  for(k=0;k≤= N/2 ;n十十)
         { 
		 for(j=k;j<=N-k-1:j++)
            (1)a[k][0]= num++ ;
         for(i=k+1;i<N-k-1;i++ )
            (2)a[i][N-k-1]= num++ ;
         for(j-N-k-1j>k;j-- )
            (3)a[N-k-1][j]=num++ ;
         for(i=N-k-1;j>k;i- - )
            (4)a[i][k]= num++ ;}*/



	for (i = 0; i <= y / 2; ++i)                                 //核心算法//
	{
		for (j = i; j <= y - i - 1; ++j)
		{
			p[i][j] = ++num;
		}
		for (j = i + 1; j < y - i - 1; ++j)
		{
			p[j][y - i - 1] = ++num;
		}
		for (j = y - i - 1; j > i; --j)
		{
			p[y - i - 1][j] = ++num;
		}
		for (j = y - i - 1; j > i; --j)
		{
			p[j][i] = ++num;
		}
	}
	printf("output the end of matrix:\n\n");                     //输出算法
	for (i = 0; i < y; ++i)
	{
		num = test_digit((int)n);                              //由于输出数字位数可能会不同，故
		num += 3;                                              //输出最大位数加三，保证最大位数也能间隔
		for (j = 0; j < y; ++j)
		{
			x = test_digit(p[i][j]);                          
			printf("%d", p[i][j]);
			for (q = 0; q < num - x; ++q)                      //该数比最大位数少几位，就多输出几个空格。
			{
				printf(" ");
			}
		}
		num = test_digit((int)n);                              //为保证列数的视觉效果，故最大位数是3的x倍。
		num = num / 3;                                         //行与行间隔x个行数。
		for (j = 0; j <= num; ++j)
		{
			printf("\n");                                      //每输出阶数个数就换行。
		}
	}
}
