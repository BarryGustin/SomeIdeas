#include <stdio.h>                         /*ptaÕ£≥µŒ Ã‚*/
#include <string.h>
#include <stdlib.h>
#include <math.h>
 



typedef struct queue
{
    char c[10];
    int num;
    int time;
    int tin;
}date;


typedef struct quue
{
    int time;
    int tin;
}date1;

int main(void)
{
    int Tin_car[100];
    int n;
    int n_car = 1;
    scanf_s("%d",&n);
    int Wai_car[100];
    int head = 0, tail = 0;
    date car[100];
    date1 carr[100];
    int num_car = 1;
    while (1)
    {
        scanf_s("%s%d%d", &car[num_car].c, sizeof(car[num_car].c), &car[num_car].num, &car[num_car].time);
        //printf("\n\n%s%d%d\n", car[num_car].c, car[num_car].num, car[num_car].time);
        if (strcmp(car[num_car].c, "A") == 0)
        {
            carr[car[num_car].num].time = car[num_car].time;
        }
        carr[car[num_car].num].tin = 0;
        if (strcmp(car[num_car].c, "E") == 0)
        {
            break;
        }
        num_car++;
    }
    for (int i = 1; i < num_car; ++i)
    {
        if (strcmp(car[i].c ,"A")==0)
        {
            if (n_car > n)
            {
                Wai_car[tail++] = car[i].num;
                printf("car#%d waiting\n", car[i].num);
            }
            else
            {
                Tin_car[n_car] = car[i].num;
                car[i].tin = n_car;
                carr[car[i].num].tin = 1;
                if (n_car <= n)
                {
                    n_car++;
                }
                printf("car#%d in parking space #%d\n", car[i].num, car[i].tin);
            }
        }
        if (strcmp(car[i].c, "D") == 0)
        {
            if (carr[car[i].num].tin == 0)
            {
                printf("the car not in park\n");
            }
            else
            {
                printf("car#%d out,parking time %d\n", car[i].num, car[i].time - carr[car[i].num].time);
                //printf("%d %d %d\n", car[i].time, carr[car[i].num].time, car[i].num);
                n_car--;
                if (head != tail)
                {
                    Tin_car[n_car] = Wai_car[head];
                    carr[Wai_car[head]].time = car[i].time;
                    carr[Wai_car[head]].tin = 1;
                    printf("car#%d in parking space #%d\n", Wai_car[head], n_car);
                    head++;
                    n_car++;
                }
            }
        }
    }
}