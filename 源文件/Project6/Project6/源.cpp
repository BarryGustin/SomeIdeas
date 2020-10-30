#include <stdio.h>
int main(void)
{
	int str[] = { 1,2,3,4 };
	int* nstr=str;
	printf("%d\n", *nstr);    //输出的数字代表什么（地址吗）
}
	
//#include <stdio.h>
//int main(void)
//{
	//char str[] = { "nice to meet you!!!" };
	//char* nstr;
	//nstr = str;
	//printf("%s\n", nstr);         //为什么加上*却不能输出，而不加却可以输出内容    nstr是指针变量存的是地址为甚么却可以输出内容
//}