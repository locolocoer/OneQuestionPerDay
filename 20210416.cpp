/*
�Ϻ���ͨ��ѧ�ϻ��⣨����




 ZIG-ZAG
Ѱ��һ�����е��֮���εĳ��ȡ���1 5 3 6 1�ĳ���Ϊ5,1 3 5�ĳ���Ϊ2�����г��Ȳ�����50�����ֲ�����1000��

�����ʽ��

n����ʾ���г���
����
�����ʽ��

����֮�������ʵ�������г���
����������

1
44
5
1 5 3 6 1
���������

1
5

*/
#include <iostream>
using namespace std;

bool isZOrder(int *num, int begin, int end); //�ж�һ�������Ƿ�����֮���ι���
int findMaxZOrder(int *num, int length);     //Ѱ��һ�����е����֮���γ���

int main(void)
{
    int num[1000];
    int length;
    cout << "���������г��ȣ�" << endl;
    cin >> length;
    cout << "�������У�" << endl;
    for (int i = 0; i < length; i++)
    {
        cin >> num[i];
    }
    cout << "���֮���γ���Ϊ��" << findMaxZOrder(num, length) << endl;
    return 0;
}

bool isZOrder(int *num, int begin, int end)
{ //���һ�������Ƿ���Z��������
    if (begin == end)
        return true;
    if (begin > end || num[begin] == num[begin + 1])
        return false;
    int i = begin, j = begin + 1; //������������ָ��
    bool isZOrder = true;
    int last_tag = num[i] > num[j] ? 1 : -1; //last_tag��¼ǰ����Ԫ��֮��Ĵ�С��ϵ������Ϊ1��С��Ϊ-1������Ϊ0
    i++;
    j++;
    while (j <= end)
    { //������ǰ��֮��Ĵ�С��ϵ
        int tag;
        if (num[i] > num[j])
        {
            tag = 1;
        }
        else if (num[i] < num[j])
        {
            tag = -1;
        }
        else
        {
            isZOrder = false;
            break;
        }
        if (tag == last_tag)
        {
            isZOrder = false;
            break;
        }
        else
        {
            last_tag = tag;
        }
        i++;
        j++;
    }
    return isZOrder;
}

int findMaxZOrder(int *num, int length)
{
    int result = 1;
    int begin, end; //begin,end�ֱ�����Z�еĿ�ʼ�ͽ���

    for (begin = 0; begin < length - 1; begin++)
    {
        for (end = begin + 1; end < length; end++)
        {
            if (isZOrder(num, begin, end) && (end - begin + 1 > result))
            { //���ҵ�����Z���������ҳ��ȱ�֮ǰ�ҵ������Z�������еĳ��ȳ�
                result = end - begin + 1;
            }
        }
        if (length - begin < result)
        { //����ǰ�����Ӵ����ȱ��Ѿ��ҵ������Z�����ִ�����С��������ѭ����
            break;
        }
    }
    return result;
}
