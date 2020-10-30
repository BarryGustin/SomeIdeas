#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M  sizeof(struct student)
int main(void)
{
	/*格式化的输入和输出
	
	.printf
	.  %[flags][width][.prec][hIL]type

	 指printf("")的“”之中可以加入四种参数

	 type指，i/d(int型),u(unsigned int),o(八进制),x(十六进制),X(字母大写的十六进制),
	 
	 f/F(float.6(小数点后六位)),e/E(指数),g(float 共有数字最多六位)==G(float),^^^a/A(十六进制浮点)^^^,
	 
	 c(char),s(字符串),p(地址，指针),n(读入/写入的个数)*/

	/*解释    x   ,    X      */
	printf("%x,%X\n\n",0xAE,0xae);

	/*解释float             
	float可接收7位有效数字  而小数点后有六位，不足拿0补位。  */
	float a;
	printf("%f\n\n\n\n",a=111.1111111);
	
	/*解释  %n   的用途*/
	
	//int num;

	//printf("%d,%n", 12354, &num);
	
	//printf("%d\n\n\n\n", num);     out:12354,6。

	/*研究[flags]
	
	flags
	
	包括  -，+，（space）,0
	
	-   指左对齐
	例                 */
	printf("%-9d\n",123);             //out:123
	printf("%9d\n\n\n",123);         //out:      123

	/*+   指前面放+或-   
	例               */
	printf("%+-9d\n",123);              //out:+123
	printf("%-+9d\n",123);             //out:+123
	printf("%-+9d\n",-123);           //out:-123   +在-号面前无用因为不能改变数值本意。
	printf("%+-9d\n\n\n", -123);     //out:-123


	/*0    只用0填充
	例                 */
	printf("%09d\n\n\n\n",123);      //out:000000123

	/*研究[width]    【为宽度】
	
	[width]
	
	包括 number(包括小数点在内一共接受number个字符)  ,*   ,(.number) （小数点后得字数）  ,(.*)
	
	例                  */
	printf("number.number type\n");
	printf("%9.2f\n\n\n",123.123);                //out:123.12
	printf("%*d\n",6,123);                       //out:   123
	printf("%9.*f\n\n\n\n",6, 123548.2154915);  //out:123548.215491500  （.*）控制小数点后的位数。

	/*研究[hIL]
	
	[hIL]      【修饰类型,定义字节】 
	
	包括 hh(单个字节),    h(short 型)   ,  l(long 型)    ,   ll(long long 型)   ,
	      L(long double 型)
	
	例                  */
	printf("%hhd\n",12345);                     //hh只占一个字节   out:57
	printf("%d\n", sizeof(short));             //short==short int  out:2
	printf("%d\n",sizeof(long));              //out:4
	printf("%d\n", sizeof(int));             //out:4      
	printf("%d\n", sizeof(double));         //out:8  
	printf("%d\n", sizeof(long long));     //out:8
	printf("%d\n",sizeof( long double));  //long double==double out:8
	printf("%Lf\n\n\n\n",49815948.484514);     // out:49815948.484514

	/*
	.scanf
	.     %[flag]type
	
	研究[flag]
	
	[flag]
	包括*  （跳过），数字   （最大字符数） ,hh    （char） , h (short)   ,
	l   (long,double) ,ll   (long long) ,L     (long double)

	*****************long是长*整*型。  double  float是*实*型。  int*整*型。
	  
	例                                  */

	/*研究  *  指跳过输入一个整数*/
	
	/*int num1, num2; 
	scanf_s("%*d%ld",&num1,&num2);        //input:123  456
	printf("%ld,%d\n\n\n",num1,num2);    //output:456,-856159155156*/

	
     /*研究数字    （接收的最多的字数包括小数点）   */
	/*重点:     输入语句scanf_s不允许指定数字的精度，意:(%8.2f)是错的     （%8f）正确*/
	float b;
	scanf_s("%8f",&b);
	printf("%8.2f\n\n\n\n\n",b);


	/*总结   数据类型与输入输出格式的对应
	
	数据类型              输入输出格式的对应
整型  int                       %d
	  long int                  %d  /  %ld
	  long                      %d  /  %ld  
	  short                     %d  /  %hd
	  short int                 %d  /  %hd    

实型  double                    %f  /  %lf  /%Lf    (小数点后六位  可以接受十七位字符包括小数点)
      float                     %f  /  %lf  /%Lf        (小数点后六位  可以接受七位字符包括小数点)   

字符  char                      %c  /  %s   / %hh         */


}










