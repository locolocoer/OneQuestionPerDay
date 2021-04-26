/*
дһ��������ʵ�ִ����˷���
�����ʽ��

�ֹ���������ֵ�ǳ�������֣��м��ÿո������
�����ʽ��

���������������˵Ľ��
����������

111111111111 111111111111111
���������

123456789012333320987654321
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string BigMutiple(string num1, string num2)
{
    string res = "";
    //��������λ��
    int m = num1.size(), n = num2.size();

    //һ��iλ������һ��jλ�������������i+j-1λ��
    vector<long long> tmp(m + n - 1);
    //ÿһλ���еѿ����˷�
    for (int i = 0; i < m; i++)
    {
        int a = num1[i] - '0';
        for (int j = 0; j < n; j++)
        {
            int b = num2[j] - '0';
            tmp[i + j] += a * b;
        }
    }
    //���н�λ����ע������Ǵ��Ҳ���С
    int carry = 0;
    for (int i = tmp.size() - 1; i >= 0; i--)
    {
        int t = tmp[i] + carry;
        tmp[i] = t % 10;
        carry = t / 10;
    }
    //����������Ȼ�н�λ
    while (carry != 0)
    {
        int t = carry % 10;
        carry /= 10;
        tmp.insert(tmp.begin(), t);
    }
    //��������뵽����ֵ��
    for (auto a : tmp)
    {
        res = res + to_string(a);
    }
    if (res.size() > 0 && res[0] == '0')
        return "0";
    return res;
}
//���Ժ���
int main()
{
    string num1, num2;
    while (cin >> num1 >> num2)
    {
        cout << BigMutiple(num1, num2) << endl;
    }
    return 0;
}
