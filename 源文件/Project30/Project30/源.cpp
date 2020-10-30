#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5    /* 栈最大容量 */
#define Empty 0        /* 空 */
#define Full 1        /* 满 */
#define Avail -1    /* 可用 */

typedef struct sta
{
    int* top;              /* 栈顶指针 */
    int* bottom;           /* 栈底指针 */
    int stack_size;        /* 栈的最大容量 */
}stack;
stack Push(stack p);          /* 入栈 */
void DisplyStack(stack p);    /* 遍历栈中元素 */
stack Pop(stack p);           /* 出栈 */
stack InitStack(stack p);     /* 初始化栈 */
int StackEmpty(stack p);      /* 判断栈是否为空 */
int StackFull(stack p);       /* 判断栈是否为满 */

int main()
{
    stack p;
    char ch;

    p.stack_size = MAX_SIZE;
    p = InitStack(p);    /* 初始化栈 */
    printf("Do you want to push to stack?(Y/N)");
    scanf_s(" %c", &ch);
    while (ch == 'Y' || ch == 'y')
    {
        p = Push(p);    /* 入栈 */
        DisplyStack(p);/* 打印栈中元素 */
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
/* Function：判断栈是否为空 */
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
/* Function：判断栈是否为满 */
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
/* Function：入栈 */
stack Push(stack p)
{
    int data;
    if (StackFull(p) == Full)
    {
        printf("栈空间已满，无法入栈");
        return p;
    }
    printf("Please input data");
    scanf_s("%d", &data);
    *p.top = data;
    p.top++;

    return p;
}
/* Function：出栈 */
stack Pop(stack p)
{
    if (StackEmpty(p) == Empty)
    {
        printf("栈为空栈，无法出栈 ");
        return p;
    }
    p.top--;
    printf("出栈元素为：%d\n", *p.top);

    return p;
}
/* Function：栈的初始化 */
stack InitStack(stack p)
{
    p.bottom = (int*)malloc(p.stack_size * sizeof(int));
    if (p.bottom == NULL)
    {
        printf("初始化栈失败\n");
        exit(0);
    }
    p.top = p.bottom;
    p.stack_size = MAX_SIZE;

    return p;
}
/* Function：遍历栈中元素，从栈顶到栈底*/
void DisplyStack(stack p)
{
    if (StackEmpty(p) == Empty)
    {
        printf("栈为空栈，无法遍历\n");
        return;
    }
    printf("栈中元素为：");
    printf("顶端[");
    while (p.top != p.bottom)
    {
        p.top--;
        printf("%d-", *p.top);
    }
    printf("]底端\n");
}