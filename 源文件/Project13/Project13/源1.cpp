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
			printf("��%d��ѧ���ĳɼ���һ�����ϲ���������ɼ���\n",i+1);
			for (loop = 0; loop < 4; loop++) {
				printf("%f\t", *(*(p + i) + loop));
			}
		}
		printf("\n");
	}
                  //������һ�����Ͽγ̲������ѧ������������ǵ�ȫ���γ̵ĳɼ�������д�ĺ�����
}