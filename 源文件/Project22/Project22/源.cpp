#include <stdio.h>                                //�����ϲ��õ��ú�����˼·��
#include <string.h>                               // �����ܽ���Ҫ��������⣺
#include <stdlib.h>                               //1������û���������⣬�糬λ���⣬
#include <ctype.h>                                //2���û����벻�������������﷨���⣺��MMMM��4M���⣬������M������С��D��X����������������⡣
int enterm(int sum,char* p)                       //3����ĸСд���⡣
{                                                 //����ÿ�����ⶼ�������ڶಢ��С���⣬���ں����ע�������ν��
	int i;
	for (i=0;i<5; ++i,++p)                       //���Ƚ���M����     
	{                                            //Ϊ��ֹ�ڳ���M��ĺ�������3��Mͬʱ���ֵ���������ڸ�λ�������3λ��
		if (*p == 'M');
		else break;                         
	}
	if (!(i - 4))
	{
		printf("input error,press any key to quit.....\n");
		exit(0);                         //�鿴�Ƿ���ǰ��Mһ�£���һ�£�ֱ�ӱ�����ֹ����
	}
	else sum += 1000;                    //���û������4λ�����ۼ������ϸ���ĸ��Ӧ������
	return sum;                          //�ṩһ������ֵ��
}

int enterd(int sum, char* p)             //����D����    
{
	char* q;                             //���ȱ�����ʼλ�ã�
	q = p;
	for (;*p!='\0'; ++p)                 //����������ĸ������ʹ�ñ�D���M���֡�
	{
		if (*p == 'M')
		{
			printf("input error,press any key to quit.....\n");
			exit(0);
		}
	}
	p = q;                               //��ָ������
	int i;
	for (i = 0; i < 5; ++i, ++p)         //����������ĸ
	{
		if (*p == 'D');                  //Ϊ��ֹ�ڳ���D��ĺ�������3��Dͬʱ���ֵ���������ڸ�λ�������3λ��
		else break;
	}
	if (!(i - 4))                        //�鿴�Ƿ���ǰ��Mһ�£���һ�£�ֱ�ӱ�����ֹ����
	{
		printf("input error,press any key to quit.....\n");
		exit(0);
	}
	else sum += 500;                     //���û������4λ�����ۼ������ϸ���ĸ��Ӧ������
	return sum;                          //�ṩһ������ֵ��
}

int enterc(int sum, char* p)             //����C����  ��ΪC����������㣬Ҫ������D��M������У����漰��������ĸ���������һ����������
{                                        //��Ҫʹ�������´���
	int i;
	char* q;                             //���ȱ�����ʼλ�ã�
	q = p;
	switch (*(++p))                      //�ڳ�ʼλ�õĻ����ϣ�ָ����һ����ĸ���������ۡ�
	{
	case 'D':sum += 400; 
		for (; *p != '\0'; ++p)          
		{
			*p = *(p + 1);               //����һ��ĸΪD����D��������ֹ���������м����ۼ�D��ֵ��
		}
		break;

	case 'M':sum += 900;
		for (; *p != '\0'; ++p)
		{
			*p = *(p + 1);               //����һ��ĸΪM����M��������ֹ���������м����ۼ�M��ֵ��
		}
		break;

	case'C':                            //����һ��ĸΪC,Ϊ��ֹ�ڳ���C��ĺ�������3��Cͬʱ���ֵ���������ڸ�λ�������3λ��
		
		for (i = 0; i < 4; ++i, ++p)
		{
			if (*p == 'C');
			else break;
		}
		if (!(i - 3))                  //�鿴�Ƿ���ǰ��Cһ�£���һ�£�ֱ�ӱ�����ֹ����
		{
			printf("input error,press any key to quit.....\n");
			exit(0);
		}
		else sum += 100;               //���û������4λ�����ۼ������ϸ���ĸ��Ӧ������
		break;                         
	
	default:sum += 100; break;         ////�����һλ����������3�����������Ϊ��λ������C����ҲӦ�����ۼ����ϼ�C��Ӧ�����֡�//
	}
	for (p=q; *p != '\0'; ++p)
	{
		if (*p == 'M'||*p=='D')        //����������ĸ������ʹ�ñ�C���M��D���֡�
		{
			printf("input error,press any key to quit.....\n");
			exit(0);
		}
	}
	return sum;                       //�ṩһ������ֵ��
}

int enterl(int sum, char* p)         ////ͬ����D����
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

int enterx(int sum, char* p)                            ////ͬ����C����
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

int enterv(int sum, char* p)                                ////ͬ����D����
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

int enteri(int sum, char* p)                             ////ͬ����C����
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
	char a[15];                                             //����a�������������
	char* p=a;                                              //ָ��
	int i, sum = 0,j=0;                                     //�����ۼ���sum
	printf("please input a Arabic number:\n");
	scanf_s("%s",a,sizeof(a));
	system("cls");
	a[14] = 0;
	j = strlen(a);                                          //��������ĸ����

	if (!(j - 0))                                           //�糬�������䣩����û���룬��ᱨ��
	{
		printf("input error,press any key to quit.....\n");
		exit(0);
	}

	for (i = 0; i < j; ++i, ++p);                           //��ס�ַ���
	(++p) = '\0';
	for (i=0,p=a; *p != '\0';++i,++p)                       //��������Сд���ת����д����
	{
		a[i] = toupper(*p);      
	}
	for (p = a; *p != '\0'; ++p)                            //����ÿһ���ַ�����������Ϊ��Ӧ���֣������ۼ�����
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
	if (sum > 3999)                                //��Ϊ�ú������ֵΪM���ʵ���ʾ4000ʱ�����������ĸ���
	{                                             //�����������е���ĸ��ϣ�����ϣ��򲻿��ܷ����﷨����
		printf("input error,press any key to quit.....\n");                    //�ʶ��涨ֵ��
		exit(0);
	}
	printf("output a number:\n");
	printf("%d\n", sum);
}