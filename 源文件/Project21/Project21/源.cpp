#include<stdio.h>                                                  /*课程表2问题*/
#include<stdlib.h>                                                 /*思路想法，建立图的方法，遍历图，再放到队列中去，从第一级开始连接第二级的课程，每一级的课程 */
#include <string.h>                                                /*之间可以随意上，依次类推第三，四级，用book数组记录是否进入队列，以及记录级数*/


int Class[100][100];                                                /*存图*/
int n;                                                              /*n门课*/
int num;
typedef struct queue                                                /*定义队列内容为课程和级数*/
{
	int point;
	int num;
}date;


/*寻找一个数组中按数组值最大的元素*/
int Max(int a[])
{
	int Max = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > Max)
		{
			Max = a[i];
		}
	}
	return Max;
}



/*寻找一个数组中按数组值排序，输出排序后的下标*/
int  print(int a[])
{
	int max = Max(a);
	printf("Case #%d:\n",num);
	for (int i = 1; i <= max; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (a[j] == i)
			{
				printf("%c\n", j+97);
			}
		}
	}
	return 1;
}


/*核心算法*/
int  Array(int a)
{
	date p[100];                                                          /*定义队列*/
	int head = 0; int tail = 0;
	p[tail].point = a;
	p[tail].num = 1;                                                       /*从第一级开始*/
	tail++;
	int book[100];
	for (int i = 0; i <= n; ++i)
	{
		book[i] = 0;
	}
	book[a] = 1;
	while (head != tail)
	{
		for (int i = 0; i < n; ++i)
		{
			if (Class[p[head].point][i] == 1 && p[head].num + 1 > book[i])    /*当两课程之间有衔接关系时，并且下一级级数应有的级数大于预先的级数时，计入队列，更新预先的book级数*/
			{
				p[tail].point = i;
				p[tail].num = p[head].num + 1;
				tail++;
				book[i] = p[head].num + 1;
			}
		}
		head++;
	}
	for (int i = 0; i < n; ++i)                                        /*检查能否完成所有课程*/
	{
		if (book[i] == 0)
		{
			return 0;
		}
	}
	return print(book);                                                 /*能完成输出*/
}


int main(void)
{
	extern int n;
	int T;
	int m;
	scanf_s("%d", &T);
	extern int num;
	for ( num= 0; num < T; ++num)
	{
		scanf_s("%d%d", &n, &m);
		for (int i = 0; i <= n; ++i)
		{
			for (int j = 0; j <= n; ++j)
			{
				Class[i][j] = 0;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			char a;
			scanf_s("\n");
			if (i == n - 1)
			{
				scanf_s("%c", &a,1);
			}
			else {
				scanf_s("%c ", &a,1);
			}
		}
		for (int i = 0; i < m; ++i)
		{
			char l, k;
			scanf_s("\n%c %c", &l, 1, &k, 1);
			int p, q;
			p = (int)l - 97;
			q = (int)k - 97;
			Class[p][q] = 1;
		}


		int zhen = 0;
		for (int i = 0; i < n; ++i)                                       /*每一个课程都作为首点（第一级）去测试*/
		{
			if (Array(i) == 1)
			{
				zhen = 1;
				break;
			}
		}
		if (zhen == 0)                                                    /*不能完成的操作*/
		{
			printf("Case #%d:\n", num);
			printf("Impossible\n");
		}
	}
}


/*
链接：https://ac.nowcoder.com/acm/contest/5678/B
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 262144K，其他语言524288K
64bit IO Format: %lld
题目描述
Ubuntu20.04 正式发布了，ZLS 是一个作死小能手，于是他决定尝试一下这个船新版本。好不容易装完系统，ZLS 想要给他的系统装一些常用的软件。众所周知，在 Linux 装软件会遇到各种奇奇怪怪的依赖问题（所谓依赖问题就是若A依赖B，则B要先与A安装）。ZLS 对此不厌其烦，因此他想知道他要用什么顺序安装软件，可以一次安装成功呢?
Tips: ZLS 还有一个癖好，他喜欢先安装字典序小的软件。
输入描述:
第一行包含一个正整数 T 表示数据组数。
每组数据的第一行包 n 和 m， 表示有 n 个软件，m 个依赖关系。
接下来的一行包含 n 个软件名(软件名仅包含小写字母 a-z )
接下来的 m 行每行有两个软件名 s 和 t，表示 t 依赖 s ，即 s 要在 t 之前安装。
数据保证： 1 \le T \le 51≤T≤5
1 \le n \le 3 \times 10^{4}, 1 \le m \le 10^{5}1≤n≤3×10
4
 ,1≤m≤10
5

1 \le |s|,|t| \le 101≤∣s∣,∣t∣≤10
输出描述:
共 T 组输出，每组输出先输出一行 Case #%d: ，%d 替换为当前输出的组数。
接下来是 n 行，按照安装的顺序输出。
如果无法进行安装，输出 Impossible (注意大小写)。
示例1
输入
复制
2
4 2
a b c d
a b
b c
3 3
a b c
a b
b c
c a
输出
复制
Case #1:
a
b
c
d
Case #2:
Impossible
*/