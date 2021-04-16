/*
上海交通大学上机题（二）




 ZIG-ZAG
寻找一个序列的最长之字形的长度。如1 5 3 6 1的长度为5,1 3 5的长度为2，序列长度不超过50，数字不超过1000。

输入格式：

n，表示序列长度
序列
输出格式：

满足之字形性质的最大序列长度
输入样例：

1
44
5
1 5 3 6 1
输出样例：

1
5

*/
#include <iostream>
using namespace std;

bool isZOrder(int *num, int begin, int end); //判断一个序列是否满足之字形规则
int findMaxZOrder(int *num, int length);     //寻找一个序列的最大之字形长度

int main(void)
{
    int num[1000];
    int length;
    cout << "请输入序列长度：" << endl;
    cin >> length;
    cout << "输入序列：" << endl;
    for (int i = 0; i < length; i++)
    {
        cin >> num[i];
    }
    cout << "最大之字形长度为：" << findMaxZOrder(num, length) << endl;
    return 0;
}

bool isZOrder(int *num, int begin, int end)
{ //检查一个序列是否是Z字形序列
    if (begin == end)
        return true;
    if (begin > end || num[begin] == num[begin + 1])
        return false;
    int i = begin, j = begin + 1; //定义两个工作指针
    bool isZOrder = true;
    int last_tag = num[i] > num[j] ? 1 : -1; //last_tag记录前两个元素之间的大小关系，大于为1，小于为-1，等于为0
    i++;
    j++;
    while (j <= end)
    { //逐个检查前后之间的大小关系
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
    int begin, end; //begin,end分别是子Z列的开始和结束

    for (begin = 0; begin < length - 1; begin++)
    {
        for (end = begin + 1; end < length; end++)
        {
            if (isZOrder(num, begin, end) && (end - begin + 1 > result))
            { //若找到的是Z字形序列且长度比之前找到的最大Z字形序列的长度长
                result = end - begin + 1;
            }
        }
        if (length - begin < result)
        { //若当前检查的子串长度比已经找到的最大Z字形字串长度小，则跳出循环。
            break;
        }
    }
    return result;
}
