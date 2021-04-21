/*
�ⷽ�̡�����һ���ַ���������һ��һԪһ�η��̡�����н���⣬�����ʽ��x=���֡� �������ĸ��������� ��infinite solutions�������û�н������no solution��
�ַ������Ȳ����� 256 ��
�����ʽ��

����һ��һԪһ�η��̣�δ֪����x��ʾ��
�����ʽ��

��� ��x=���֡� ���� ��infinite solutions�����ߡ�no solution��
����������

10x-2x-8=4x+7+x
���������

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
