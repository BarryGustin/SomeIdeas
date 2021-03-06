#include <stdio.h>
static int f(int, int);
int main(void)

{
	extern int max;
	int a=1, b=2, c=3;
	max = f(c, f(a, b));
	printf("%d\n",max);
}
 int max = 0;
int f (int a, int b)
{
	max = a > b ? a : b;
	return max;
}
/*讨论变量与函数的存储类别，
从空间角度讲，变量从定义到被释放的过程中发挥的行数，
即变量发挥作用的空间（代码行），我们叫变量的作用域。

作用域将变量分为  局部变量 和 全局变量。

局部变量包括   函数内的变量，即（auto）、（静态局部变量）、（寄存器变量）、（形参）

全局变量包括   函数外的变量，即（静态全局变量）、（非静态全局变量）

非静态全局变量可以被其他文件调用，静态全局变量只能在本文件内使用，
与非静态全局变量的区别是有static 做静态处理。

静态全局变量只在定义后这一行之后的代码中使用才有意义，
在这一行代码之前机器并不认为该静态全局变量被定义。

且静态全局变量不能用extern 扩展使用范围，即既不能在本文件中扩展，
也不能在其他文件中扩展。

而非静态全局变量可以用extern 扩展使用范围，即不但在本文件中扩展，也可以在其他文件中扩展。

（auto）、（寄存器变量）、（形参）这三类变量在函数内有意义，
其定义他们的函数名在一个函数中只能用一次，但在别的函数中可以再次使用该函数名，
因为这三种变量在函数开始时分配空间，在函数结束时释放空间，与整个文件不ran。

静态局部变量在函数中被定义，在函数中被使用，在函数结束时
（auto）、（寄存器变量）、（形参）这三类变量被释放空间，
而静态局部变量不释放空间，此空间存着此值将一直到程序结束。

静态局部变量从被定义一行起，到程序结束一直有空间，故值会随着运算而不断改变。

变量存在的时间域，即生存期，被称为存储类型，
即他的开辟的空间是一直存在到函数结束，还是存在到程序结束，
对应分为动态存储、静态存储。

动态存储分为存（auto）、（寄存器变量）、（形参），即在函数内有空间。
静态存储分为存  静态局部变量、静态全局变量、非静态全局变量，即在程序中一直有空间。

静态局部变量（在函数内参与计算，程序过程中一直有值）、
静态全局变量（在从定义一行起，到程序结束的所有函数中都可参与计算，程序过程中一直有值）、
非静态全局变量（在从定义一行起，到程序结束的所有函数中都可参与计算，程序过程中一直有值
且可以扩展使用，即可参与计算的范围）

函数的存储类别
分为 局部函数、外部函数。
区别为局部函数 有static 做静态处理，
即局部函数只能在该文件中使用不能被调用，
外部函数可以被调用。

最后辨析程序结束，和文件结束的概念，
程序可能有多个文件，程序结束指程序中所有文件执行完毕。
文件结束指某一文件执行完毕。

*/