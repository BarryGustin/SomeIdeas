#include <stdio.h>
void search(float(*p)[4])
{
	int i,out,j,loop;
	for (i = 0; i < 3; i++) {
		out = 0;
		for (j = 0; j < 4; j++) {
			if (*(*(p + i) + j) < 60) {
				out++;
			}
		}
		if (out>=2) {
			printf("第%d个学生的成绩有一门以上不及格，输出成绩：\n",i+1);
			for (loop = 0; loop < 4; loop++) {
				printf("%f\t", *(*(p + i) + loop));
			}
		}
		printf("\n");
	}
                  //查找有一门以上课程不及格的学生，并输出他们的全部课程的成绩。（编写的函数）
}