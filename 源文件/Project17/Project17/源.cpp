#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M  sizeof(struct student)
int main(void)
{
	/*��ʽ������������
	
	.printf
	.  %[flags][width][.prec][hIL]type

	 ָprintf("")�ġ���֮�п��Լ������ֲ���

	 typeָ��i/d(int��),u(unsigned int),o(�˽���),x(ʮ������),X(��ĸ��д��ʮ������),
	 
	 f/F(float.6(С�������λ)),e/E(ָ��),g(float �������������λ)==G(float),^^^a/A(ʮ�����Ƹ���)^^^,
	 
	 c(char),s(�ַ���),p(��ַ��ָ��),n(����/д��ĸ���)*/

	/*����    x   ,    X      */
	printf("%x,%X\n\n",0xAE,0xae);

	/*����float             
	float�ɽ���7λ��Ч����  ��С���������λ��������0��λ��  */
	float a;
	printf("%f\n\n\n\n",a=111.1111111);
	
	/*����  %n   ����;*/
	
	//int num;

	//printf("%d,%n", 12354, &num);
	
	//printf("%d\n\n\n\n", num);     out:12354,6��

	/*�о�[flags]
	
	flags
	
	����  -��+����space��,0
	
	-   ָ�����
	��                 */
	printf("%-9d\n",123);             //out:123
	printf("%9d\n\n\n",123);         //out:      123

	/*+   ָǰ���+��-   
	��               */
	printf("%+-9d\n",123);              //out:+123
	printf("%-+9d\n",123);             //out:+123
	printf("%-+9d\n",-123);           //out:-123   +��-����ǰ������Ϊ���ܸı���ֵ���⡣
	printf("%+-9d\n\n\n", -123);     //out:-123


	/*0    ֻ��0���
	��                 */
	printf("%09d\n\n\n\n",123);      //out:000000123

	/*�о�[width]    ��Ϊ��ȡ�
	
	[width]
	
	���� number(����С��������һ������number���ַ�)  ,*   ,(.number) ��С������������  ,(.*)
	
	��                  */
	printf("number.number type\n");
	printf("%9.2f\n\n\n",123.123);                //out:123.12
	printf("%*d\n",6,123);                       //out:   123
	printf("%9.*f\n\n\n\n",6, 123548.2154915);  //out:123548.215491500  ��.*������С������λ����

	/*�о�[hIL]
	
	[hIL]      ����������,�����ֽڡ� 
	
	���� hh(�����ֽ�),    h(short ��)   ,  l(long ��)    ,   ll(long long ��)   ,
	      L(long double ��)
	
	��                  */
	printf("%hhd\n",12345);                     //hhֻռһ���ֽ�   out:57
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
	
	�о�[flag]
	
	[flag]
	����*  ��������������   ������ַ����� ,hh    ��char�� , h (short)   ,
	l   (long,double) ,ll   (long long) ,L     (long double)

	*****************long�ǳ�*��*�͡�  double  float��*ʵ*�͡�  int*��*�͡�
	  
	��                                  */

	/*�о�  *  ָ��������һ������*/
	
	/*int num1, num2; 
	scanf_s("%*d%ld",&num1,&num2);        //input:123  456
	printf("%ld,%d\n\n\n",num1,num2);    //output:456,-856159155156*/

	
     /*�о�����    �����յ�������������С���㣩   */
	/*�ص�:     �������scanf_s������ָ�����ֵľ��ȣ���:(%8.2f)�Ǵ��     ��%8f����ȷ*/
	float b;
	scanf_s("%8f",&b);
	printf("%8.2f\n\n\n\n\n",b);


	/*�ܽ�   �������������������ʽ�Ķ�Ӧ
	
	��������              ���������ʽ�Ķ�Ӧ
����  int                       %d
	  long int                  %d  /  %ld
	  long                      %d  /  %ld  
	  short                     %d  /  %hd
	  short int                 %d  /  %hd    

ʵ��  double                    %f  /  %lf  /%Lf    (С�������λ  ���Խ���ʮ��λ�ַ�����С����)
      float                     %f  /  %lf  /%Lf        (С�������λ  ���Խ�����λ�ַ�����С����)   

�ַ�  char                      %c  /  %s   / %hh         */


}










