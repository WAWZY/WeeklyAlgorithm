/*
    思路：
    初始化一个keyboard数组，存储键盘的顺序，
    每当从标准输入读取一个字符，
    则当即输出该字符在keyboard数组的前一个元素。
*/

#include <stdio.h>

char keyboard[] = "1234567890-=\\`QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./";

int main()
{
    char c;
    int i;
    while ((c = getchar()) != EOF)
    {
        for (i = 0; keyboard[i] && keyboard[i] != c; i++);
        if (keyboard[i])
            putchar(keyboard[i - 1]);
        else
            putchar(c);
    }

    return 0;
}