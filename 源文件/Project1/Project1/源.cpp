#include  <stdio.h>
int main(void)
{
	char cha,chb;
	printf("������һ����ĸ��");
	scanf_s("%c", &cha);
	getchar();
	switch (cha)
	{
	case 'm':printf("monday\n\n\n\n\n\n"); break;
	case 'w':printf("wednesday\n\n\n\n\n\n"); break;
	case 'f':printf("friday\n\n\n\n\n\n"); break;
	case 't': {
		{printf("��������һ����ĸ��");
		if (cha == 't')
		scanf_s("%c", &chb);
		switch (chb)
		{
		case'u':printf("tuesday\n\n\n\n\n\n"); break;
		case'h':printf("thureday\n\n\n\n\n\n"); break;
		}break;
		}
	}break;
	case 's': {
		{if (cha == 's')
			printf("��������һ����ĸ��");
		scanf_s("%c", &chb);
		switch (chb)
		{
		case'a':printf("saturday\n\n\n\n\n\n"); break;
		case'u':printf("sunday\n\n\n\n\n\n"); break;
		}break;
		}
	}break;
	default:printf("error!!!\n\n\n\n"); break;
	}
}