/*
解方程。给定一个字符串，代表一个一元一次方程。如果有解求解，输出格式“x=数字” ，如果解的个数无穷，输出 “infinite solutions”。如果没有解输出“no solution”
字符串长度不超过 256 。
输入格式：

输入一个一元一次方程，未知数用x表示。
输出格式：

输出 “x=数字” 或者 “infinite solutions”或者“no solution”
输入样例：

10x-2x-8=4x+7+x
输出样例：

x=5

*/
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    int nFactor = 0;
    int nConstant = 0;
    int nFlags = 1;
    int nScanf;
    int nScanfRet;
    int nNextChar;
    char chChar = 0;
    while ((nNextChar = getchar()) != EOF && ungetc(nNextChar, stdin) != '\n')
    {
        if ((nScanfRet = scanf("%d", &nScanf)) != 1)
        {
            if (nNextChar == '-')
            {
                nScanf = -1;
            }
            else
            {
                nScanf = 1;
            }
            nScanfRet = 0;
        }
        nNextChar = getchar();
        if (isalpha(nNextChar))
        {
            chChar = (char)nNextChar;
            nFactor += nFlags * nScanf;
        }

        else if (nNextChar == '=')
        {
            nConstant += nScanfRet * nFlags * nScanf;
            nFlags = -nFlags;
        }
        else if (nNextChar == '\n')
        {
            nConstant += nScanfRet * nFlags * nScanf;
            break;
        }
        else
        {
            nConstant += nFlags * nScanf;
            ungetc(nNextChar, stdin);
        }
    }
    if ((double)nFactor == 0.0)
        if ((double)nConstant == 0.0)
            printf("infinite solutions");
        else
            printf("no solution");
    else
        printf("%c=%f\n", chChar, -(double)nConstant / nFactor);
    return 0;
}
