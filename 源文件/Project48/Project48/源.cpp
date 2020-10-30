#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>



int destNum=0;

void findDestNum(int in, int dir,int add,int num);                          /*深搜查找*/




/*深搜查找*/
void findDestNum(int in,int dir,int add,int num) {
	if (add == in)
	{
		destNum = num;
		return;
	}
	if (dir >= 10)
	{
		return;
	}
	int i = 0;
	findDestNum(in, dir + 1, add, num);
	i = 1;
	add += pow(2, dir);
	findDestNum(in, dir + 1, add, num + 1);
	return;
}





int main(void)
{
	int  inTo;
	scanf_s("%d",&inTo);
	inTo = fabs(inTo);
	findDestNum(inTo,0,0,0);
	printf("%d",destNum);
}

