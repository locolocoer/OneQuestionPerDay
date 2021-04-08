/*
明日预告：西安电子科技大学上机题（三）
假设用于通信的电文由n（4<n<30）个字符组成，字符在电文中出现的频度（权值）为w1，w2，……，试根据该权值序列构造哈夫曼树，并计算该树的带权路径长度。
输入格式：

仅一组数据，分为两行输入：第1行为n的值，第2行为n个整数，表示字符的出现频度。
输出格式：

一个整数，表示所构造哈夫曼树的带权路径长度（输出整数后换行）。
输入样例：

8
7 19 2 6 32 3 21 10

输出样例：

261
*/
#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct BinTreeNode
{
    int weight;
    BinTreeNode *lchild;
    BinTreeNode *rchild;
} TreeNode, *Tree;

void mergeTreeNode(Tree *T, int &length, int i, int j); //合并树的节点
void findMin(Tree *T, int &length, int &i, int &j);     //寻找权值最小的两个节点
void traverse(Tree T, int deepth, int &ans);            //递归遍历二叉树，累加计算带权路径长度

int main(void)
{
    int n;
    cin >> n;
    Tree t[n];
    int length = n;
    for (int i = 0; i < n; i++)
    {
        t[i] = (Tree)malloc(sizeof(TreeNode));
        cin >> t[i]->weight;
        t[i]->lchild = NULL;
        t[i]->rchild = NULL;
    }

    while (length > 1)
    { //数组中节点个数大于1时循环
        int i, j;
        findMin(t, length, i, j);
        mergeTreeNode(t, length, i, j);
    }
    int ans = 0;
    traverse(t[0], 0, ans);
    cout << endl;
    cout << "ans=" << ans << endl;
    return 0;
}

void mergeTreeNode(Tree *T, int &length, int i, int j)
{ //合并树的节点
    if (length <= 1)
        return;
    //生成合并后的节点
    Tree temp;
    temp = (Tree)malloc(sizeof(TreeNode));
    temp->weight = T[i]->weight + T[j]->weight;
    temp->lchild = T[i];
    temp->rchild = T[j];
    //在节点数组中删除原节点i
    for (int k = i; k < length - 1; k++)
    {
        T[k] = T[k + 1];
    }
    length--;
    //在节点数组中删除原节点j
    for (int k = j - 1; k < length - 1; k++)
    {
        T[k] = T[k + 1];
    }
    length--;
    //将合并后的节点存储起来
    T[length++] = temp;
}

void findMin(Tree *T, int &length, int &i, int &j)
{ //寻找权值最小的两个节点
    int min, second_min;
    min = 0;
    for (int k = 0; k < length; k++)
    {
        if (T[k]->weight < T[min]->weight)
        {
            min = k;
        }
    }
    if (min == 0)
    {
        second_min = 1;
    }
    else
    {
        second_min = 0;
    }
    for (int k = 0; k < length; k++)
    {
        if (k != min && T[k]->weight < T[second_min]->weight)
        {
            second_min = k;
        }
    }
    i = min > second_min ? second_min : min;
    j = min > second_min ? min : second_min;
}

void traverse(Tree T, int deepth, int &ans)
{ //递归遍历二叉树，累加计算带权路径长度
    if (T == NULL)
        return;
    if (T->lchild == NULL && T->rchild == NULL)
    {
        ans += T->weight * deepth;
    }
    traverse(T->lchild, deepth + 1, ans);
    traverse(T->rchild, deepth + 1, ans);
}
