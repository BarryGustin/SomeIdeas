#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
int main(void)
{
    int sum = 0,i;
    FILE* fp, * fp1;
    char ch, filename[10];
    printf("请输入所用的文件名：");
    scanf_s("%s", filename, sizeof(filename));
    filename[9] = '\0';
    i=getchar();
    if ((fp = fopen(filename, "w")) == NULL)
    {
        printf("cannot open file:\n");
        exit(0);
    }
    printf("请输入一个准备存储到磁盘的字符串（以#结束）：");
    ch = getchar();
    while (ch != '#')
    {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            fputc(ch, fp);
            //putchar(ch);
            ch = getchar();
            if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')))
                ++sum;
        }
        else
        {
            fputc(ch, fp);
            //putchar(ch);
            ch = getchar();
        }
    }

    fclose(fp);
    system("cls");
    if ((fp1 = fopen(filename, "r")) == NULL)
    {
        printf("cannot open file:\n");
        exit(0);
    }
    ch = fgetc(fp1);
    while (!feof(fp1))
    {
        putchar(ch);
        ch = fgetc(fp1);
    }
    fclose(fp1);
    printf("\n");
    printf("单词数为：\n");
    printf("%d\n", sum);
    return 0;
}