#include <stdio.h>
int main(void)
{
	int str[] = { 1,2,3,4 };
	int* nstr=str;
	printf("%d\n", *nstr);    //��������ִ���ʲô����ַ��
}
	
//#include <stdio.h>
//int main(void)
//{
	//char str[] = { "nice to meet you!!!" };
	//char* nstr;
	//nstr = str;
	//printf("%s\n", nstr);         //Ϊʲô����*ȴ���������������ȴ�����������    nstr��ָ���������ǵ�ַΪ��ôȴ�����������
//}