#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5    /* ջ������� */
#define Empty 0        /* �� */
#define Full 1        /* �� */
#define Avail -1    /* ���� */

typedef struct sta
{
    int* top;              /* ջ��ָ�� */
    int* bottom;           /* ջ��ָ�� */
    int stack_size;        /* ջ��������� */
}stack;
stack Push(stack p);          /* ��ջ */
void DisplyStack(stack p);    /* ����ջ��Ԫ�� */
stack Pop(stack p);           /* ��ջ */
stack InitStack(stack p);     /* ��ʼ��ջ */
int StackEmpty(stack p);      /* �ж�ջ�Ƿ�Ϊ�� */
int StackFull(stack p);       /* �ж�ջ�Ƿ�Ϊ�� */

int main()
{
    stack p;
    char ch;

    p.stack_size = MAX_SIZE;
    p = InitStack(p);    /* ��ʼ��ջ */
    printf("Do you want to push to stack?(Y/N)");
    scanf_s(" %c", &ch);
    while (ch == 'Y' || ch == 'y')
    {
        p = Push(p);    /* ��ջ */
        DisplyStack(p);/* ��ӡջ��Ԫ�� */
        printf("Do you want to push to stack?(Y/N)");
        scanf_s(" %c", &ch);
    }
    printf("Do you want to pop (Y/N)");
    scanf_s(" %c", &ch);
    while (ch == 'Y' || ch == 'y')
    {
        p = Pop(p);
        DisplyStack(p);
        printf("Do you want to pop (Y/N)");
        scanf_s(" %c", &ch);
    }

    return 0;
}
/* Function���ж�ջ�Ƿ�Ϊ�� */
int StackEmpty(stack p)
{
    if (p.top == p.bottom)
    {
        return Empty;
    }
    else
    {
        return Avail;
    }
}
/* Function���ж�ջ�Ƿ�Ϊ�� */
int StackFull(stack p)
{
    if (p.top - p.bottom == p.stack_size)
    {
        return Full;
    }
    else
    {
        return Avail;
    }
}
/* Function����ջ */
stack Push(stack p)
{
    int data;
    if (StackFull(p) == Full)
    {
        printf("ջ�ռ��������޷���ջ");
        return p;
    }
    printf("Please input data");
    scanf_s("%d", &data);
    *p.top = data;
    p.top++;

    return p;
}
/* Function����ջ */
stack Pop(stack p)
{
    if (StackEmpty(p) == Empty)
    {
        printf("ջΪ��ջ���޷���ջ ");
        return p;
    }
    p.top--;
    printf("��ջԪ��Ϊ��%d\n", *p.top);

    return p;
}
/* Function��ջ�ĳ�ʼ�� */
stack InitStack(stack p)
{
    p.bottom = (int*)malloc(p.stack_size * sizeof(int));
    if (p.bottom == NULL)
    {
        printf("��ʼ��ջʧ��\n");
        exit(0);
    }
    p.top = p.bottom;
    p.stack_size = MAX_SIZE;

    return p;
}
/* Function������ջ��Ԫ�أ���ջ����ջ��*/
void DisplyStack(stack p)
{
    if (StackEmpty(p) == Empty)
    {
        printf("ջΪ��ջ���޷�����\n");
        return;
    }
    printf("ջ��Ԫ��Ϊ��");
    printf("����[");
    while (p.top != p.bottom)
    {
        p.top--;
        printf("%d-", *p.top);
    }
    printf("]�׶�\n");
}