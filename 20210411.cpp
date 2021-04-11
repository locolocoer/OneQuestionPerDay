/*
            华中科技大学上机题（三）
编写程序，接受3个以N/D形式输入的分数，其中N（0<=N<=65535）为分子，D（0<=D<=65535）为分母，输出他们的小数形式。
如果小数存在循环节，则用括号括起来，如1/3=.33333...表示为0.(3)。
输入格式：

输入例如：8/5 1/3 11/13
输出格式：

按题意表示的数
输入样例：

8/5 
1/3 
11/13
输出样例：

8/5 = 1.6
1/3 =.(3)
11/13 = .(846153)
*/
#include <iostream>
#define LENGTH 20 //定义小数保留的位数
using namespace std;

void pintResult(int n, int d); //输出以n/d的小数形式结果

int main(void)
{
    int n[3];
    int d[3];
    int i;
    cout << "请输入N/D:" << endl;
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
    char result[LENGTH]; //存放结果的小数部分
    char circle[LENGTH]; //存放循环节
    int circleStart = 0;
    bool isCircle = false;
    int save_n = n; //存放n的初始值
    int i = 0;
    //先计算保留50位小数的结果
    int temp = n / d; //temp存放结果的整数部分
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
    //判断小数部分是否有循环节，并进行处理
    int k, l; //定义两个工作指针
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
    //检查循环节是否是全0
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
