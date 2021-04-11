/*
            ���пƼ���ѧ�ϻ��⣨����
��д���򣬽���3����N/D��ʽ����ķ���������N��0<=N<=65535��Ϊ���ӣ�D��0<=D<=65535��Ϊ��ĸ��������ǵ�С����ʽ��
���С������ѭ���ڣ�������������������1/3=.33333...��ʾΪ0.(3)��
�����ʽ��

�������磺8/5 1/3 11/13
�����ʽ��

�������ʾ����
����������

8/5 
1/3 
11/13
���������

8/5 = 1.6
1/3 =.(3)
11/13 = .(846153)
*/
#include <iostream>
#define LENGTH 20 //����С��������λ��
using namespace std;

void pintResult(int n, int d); //�����n/d��С����ʽ���

int main(void)
{
    int n[3];
    int d[3];
    int i;
    cout << "������N/D:" << endl;
    scanf("%d/%d %d/%d %d/%d", &n[0], &d[0], &n[1], &d[1], &n[2], &d[2]);
    cout << endl;
    for (i = 0; i < 3; i++)
    {
        pintResult(n[i], d[i]);
    }
    return 0;
}

void pintResult(int n, int d)
{
    char result[LENGTH]; //��Ž����С������
    char circle[LENGTH]; //���ѭ����
    int circleStart = 0;
    bool isCircle = false;
    int save_n = n; //���n�ĳ�ʼֵ
    int i = 0;
    //�ȼ��㱣��50λС���Ľ��
    int temp = n / d; //temp��Ž������������
    n = n % d * 10;
    while (i < LENGTH)
    {
        if (n > d)
        {
            result[i] = n / d + '0';
        }
        else
        {
            result[i] = '0';
        }
        i++;
        n = n % d * 10;
    }
    result[i] = '\0';
    //�ж�С�������Ƿ���ѭ���ڣ������д���
    int k, l; //������������ָ��
    k = 0;
    l = 1;
    while (l <= LENGTH / 2)
    {
        while (result[k] != result[l] && l <= LENGTH / 2)
            l++;
        int flag = l;
        while (result[k] == result[l])
        {
            k++;
            l++;
            if (l >= LENGTH)
                break;
            if (k == flag)
            {
                isCircle = true;
                int m;
                for (m = circleStart; m < k; m++)
                {
                    circle[m - circleStart] = result[m];
                }
                circle[m - circleStart] = '\0';
            }
        }
        if (isCircle == true)
        {
            break;
        }
        else if ((l - k - 1) >= (k - circleStart))
        {
            circleStart++;
            k = circleStart;
            l = k + 1;
        }
        else
        {
            k = 0;
            circleStart = 0;
        }
    }
    //���ѭ�����Ƿ���ȫ0
    i = 0;
    bool tag = false;
    while (circle[i] != '\0')
    {
        if (circle[i] != '0')
        {
            tag = true;
        }
        i++;
    }
    if (isCircle == true && tag == true)
    {
        cout << save_n << "/" << d << "=" << temp << ".";
        for (i = 0; i < circleStart; i++)
        {
            cout << result[i];
        }
        cout << "(" << circle << ")" << endl;
    }
    else
    {
        cout << save_n << "/" << d << "=" << temp << '.' << result << endl;
    }
}
