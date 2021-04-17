/*
C�Ϻ���ͨ��ѧ�ϻ��⣨����

Sum of Fibonacci
��һ��������쳲��������е����ֱ�ʾ�ķ�����������
�涨F(1)=1��F(2)=2;
��13���Ա�ʾΪ
13=13
13=5+8
13=2+3+8
����������13=2+3+3+5 ��Ϊ�����ظ���
������

����������

6
8
���������

8
3
*/ 
#include <iostream>

using namespace std;

int Fib[100];        //����Fibonacci����
int comb = 0;        //��������
int path[100];       //��������·��
int path_length = 0; //������·���ĳ���

int getFibonacciList(int num, int *Fib);           //��ȡ��num��Χ�ڵ�Fibonacci���У��������г���
void dfs(int dif, int *tag, int length, int last); //��Fibonacci���н��������������������last����һ��������·����Ϊ�˱�֤�������ظ������

int main(void)
{
    int n;
    int tag[100]; //���·���Ƿ��߹�
    int length;   //��Χ�ڵ�Fibonacci���г���
    cout << "������n��" << endl;
    cin >> n;
    length = getFibonacciList(n, Fib);
    //��ʼ��tag
    for (int i = 0; i < length; i++)
    {
        tag[i] = 0;
    }
    //�����������
    dfs(n, tag, length, 0);
    cout << endl;
    cout << "��" << comb << "��" << endl;
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
    //�ݹ����
    if (dif < 0)
    {
        return;
    }
    if (dif == 0)
    {
        comb++;
        cout << endl;
        cout << "-----��" << comb << "��-----" << endl;
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
        { //û��ʹ�ù�
            tag[i] = 1;
            //����·��
            path[path_length] = Fib[i];
            path_length++;
            //�ݹ�
            dfs(dif - Fib[i], tag, length, i);
            //��ԭ
            tag[i] = 0;
            path_length--;
        }
    }
}
