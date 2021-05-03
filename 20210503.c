/*
编写一个程序，从键盘输入n个非零常数（0<n<1000）,将这n个数中每个数的各位数字取出来相加，并按照从小到大的次序输出这些数字和。

输入格式：

输入的整数之间以空格分割，输入为0时结束
输出格式：

在一行上从小到大输出计算结果，整数之间用一个空格分割，最后换行
输入样例：

56 12 789 521 0
输出样例：

3 8 11 24
*/
#include <stdio.h>
void sort(int R[], int n)
{
    int i, j, flag;
    int temp;
    for (i = n - 1; i >= 1; --i)
    {
        flag = 0;
        for (j = 1; j <= i; ++j)
            if (R[j - 1] > R[j])
            {
                temp = R[j];
                R[j] = R[j - 1];
                R[j - 1] = temp;
                flag = 1;
            }
        if (flag == 0)
            return;
    }
}
main()
{
    char s;
    int a[100], k = 0;
    printf("请输入无序数字（用空格隔开，按回车键结束输入）:\n");
    do
    {
        scanf("%d", &a[k++]);
    } while (a[k - 1] != 0);
    int i = 0, j = 1, m = 0, b[k - 1];
    for (i = 0; i < k - 1; ++i)
    {
        while (a[i] - j + 1 > 0)
        {
            ++m;
            j = j * 10;
        }
        b[i] = m; //记录下每个数字的位数
    }
    int c[k - 1], sum = 0, temp = 1; //将每个数字的各位数字之和存入数组c中
    for (i = 0; i < k - 1; ++i)
    {
        sum = 0;
        for (j = b[i] - 1; j >= 0; --j)
        {
            temp = 1;
            for (int t = 0; t < j; ++t)
            {
                temp = temp * 10;
            }
            sum = sum + a[i] / temp;
            a[i] = a[i] % temp;
        }
        c[i] = sum;
    }
    sort(c, k - 1);
    for (i = 0; i < k - 1; ++i)
    {
        printf("%d  ", c[i]);
    }
}
