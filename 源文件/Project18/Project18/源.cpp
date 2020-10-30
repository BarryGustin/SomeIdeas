#include <stdio.h>
#include <stdlib.h>
#define  M  sizeof(struct student)
typedef struct student
{
    int num;
    char name[20];
    struct student* next;
}student;
student* list1()
{
    student* p1, * p2, * head = NULL;
    p1 = p2 = (student*)malloc(M);
    printf("please input the information of the NO.1 student:\n");
    scanf_s("%d", &p1->num);
    scanf_s("%s", p1->name, sizeof(p1->name));
    for (int n = 0; p1->num != 0;)
    {
        n++;
        if (!(n - 1))  head = p1;
        else
        {
            p2->next = p1;
            p2 = p1;
        }
        p1= (student*)malloc(M);
        printf("please input the information of the NO.%d student:\n",n+1);
        scanf_s("%d", &p1->num);
        scanf_s("%s", p1->name, sizeof(p1->name));
    }
    p2->next = NULL;
    return head;
}
student* list2()
{
    student* p1, * p2, * head = NULL;
    p1 = p2 = (student*)malloc(M);
    printf("please input the information of the NO.1 student:\n");
    scanf_s("%d", &p1->num);
    scanf_s("%s", p1->name, sizeof(p1->name));
    for (int n = 0; p1->num != 0;)
    {
        n++;
        if (!(n - 1))  head = p1;
        else
        {
            p2->next = p1;
            p2 = p1;
        }
        p1 = (student*)malloc(M);
        printf("please input the information of the NO.%d student:\n", n + 1);
        scanf_s("%d", &p1->num);
        scanf_s("%s", p1->name, sizeof(p1->name));
    }
    p2->next = NULL;
    return head;
}
int main(void)
{
    student* n1, * n2, *m1 ,*head,*head1;
    m1 = head = n1 = list1();
    head1= list2();
    while (n1 != NULL)
    {
        n2 = head1;
        while((n1->num != n2->num )&&( n2->next!= NULL))  
        {
            n2 = n2->next;
        }
        if (n1->num == n2->num)
        {
            if (n1 == head)
            {
                head = n1->next;
            }
            else
            {
                m1->next = n1->next;
                n1 = n1->next;
            }
        }
        else
        {
            m1 = n1;
            n1 = n1->next;
        }
    }
    student* p;
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = head1;
    int q = 0;
    for (p = head; p != NULL; p = p->next)
    {
        printf("output the information of the NO.%d student:\n",++q);
        printf("%d\t%s\n", p->num, p->name);
    }
    return 0;
}