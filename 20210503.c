/*
��дһ�����򣬴Ӽ�������n�����㳣����0<n<1000��,����n������ÿ�����ĸ�λ����ȡ������ӣ������մ�С����Ĵ��������Щ���ֺ͡�

�����ʽ��

���������֮���Կո�ָ����Ϊ0ʱ����
�����ʽ��

��һ���ϴ�С�������������������֮����һ���ո�ָ�����
����������

56 12 789 521 0
���������

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
    printf("�������������֣��ÿո���������س����������룩:\n");
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
        b[i] = m; //��¼��ÿ�����ֵ�λ��
    }
    int c[k - 1], sum = 0, temp = 1; //��ÿ�����ֵĸ�λ����֮�ʹ�������c��
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
