/*
C上海交通大学上机题（三）

Sum of Fibonacci
求一个数字用斐波那契数列的数字表示的方法的数量。
规定F(1)=1，F(2)=2;
如13可以表示为
13=13
13=5+8
13=2+3+8
但不可以是13=2+3+3+5 因为有了重复的
有三种

输入样例：

6
8
输出样例：

8
3
*/ 
#include <iostream>

using namespace std;

int Fib[100];        //保存Fibonacci数列
int comb = 0;        //保存结果数
int path[100];       //保存结果的路径
int path_length = 0; //保存结果路径的长度

int getFibonacciList(int num, int *Fib);           //获取在num范围内的Fibonacci数列，返回数列长度
void dfs(int dif, int *tag, int length, int last); //对Fibonacci数列进行深度优先搜索，其中last是上一步经过的路径，为了保证不出现重复的组合

int main(void)
{
    int n;
    int tag[100]; //标记路径是否走过
    int length;   //范围内的Fibonacci数列长度
    cout << "请输入n：" << endl;
    cin >> n;
    length = getFibonacciList(n, Fib);
    //初始化tag
    for (int i = 0; i < length; i++)
    {
        tag[i] = 0;
    }
    //深度优先搜索
    dfs(n, tag, length, 0);
    cout << endl;
    cout << "共" << comb << "种" << endl;
    return 0;
}

int getFibonacciList(int num, int *Fib)
{
    int length = 3;
    Fib[0] = 1;
    Fib[1] = 2;
    Fib[2] = 3;
    if (num <= 0)
        return -1;
    if (num <= 3)
        return num;
    while (Fib[length - 1] < num)
    {
        Fib[length] = Fib[length - 1] + Fib[length - 2];
        length++;
    }
    return length;
}

void dfs(int dif, int *tag, int length, int last)
{
    //递归出口
    if (dif < 0)
    {
        return;
    }
    if (dif == 0)
    {
        comb++;
        cout << endl;
        cout << "-----第" << comb << "种-----" << endl;
        for (int i = 0; i < path_length; i++)
        {
            cout << path[i] << "\t";
        }
        cout << endl;
        cout << "---------------------" << endl;
    }
    for (int i = last; i < length; i++)
    {
        if (tag[i] == 0)
        { //没有使用过
            tag[i] = 1;
            //保存路径
            path[path_length] = Fib[i];
            path_length++;
            //递归
            dfs(dif - Fib[i], tag, length, i);
            //还原
            tag[i] = 0;
            path_length--;
        }
    }
}
