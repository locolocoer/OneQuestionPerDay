/*
写一个函数，实现大数乘法。
输入格式：

手工输入两个值非常大的数字，中间用空格隔开。
输出格式：

输出这两个数字相乘的结果
输入样例：

111111111111 111111111111111
输出样例：

123456789012333320987654321
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string BigMutiple(string num1, string num2)
{
    string res = "";
    //两个数的位数
    int m = num1.size(), n = num2.size();

    //一个i位数乘以一个j位数，结果至少是i+j-1位数
    vector<long long> tmp(m + n - 1);
    //每一位进行笛卡尔乘法
    for (int i = 0; i < m; i++)
    {
        int a = num1[i] - '0';
        for (int j = 0; j < n; j++)
        {
            int b = num2[j] - '0';
            tmp[i + j] += a * b;
        }
    }
    //进行进位处理，注意左侧是大右侧是小
    int carry = 0;
    for (int i = tmp.size() - 1; i >= 0; i--)
    {
        int t = tmp[i] + carry;
        tmp[i] = t % 10;
        carry = t / 10;
    }
    //若遍历完仍然有进位
    while (carry != 0)
    {
        int t = carry % 10;
        carry /= 10;
        tmp.insert(tmp.begin(), t);
    }
    //将结果存入到返回值中
    for (auto a : tmp)
    {
        res = res + to_string(a);
    }
    if (res.size() > 0 && res[0] == '0')
        return "0";
    return res;
}
//测试函数
int main()
{
    string num1, num2;
    while (cin >> num1 >> num2)
    {
        cout << BigMutiple(num1, num2) << endl;
    }
    return 0;
}
