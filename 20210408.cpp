/*
����Ԥ�棺�������ӿƼ���ѧ�ϻ��⣨����
��������ͨ�ŵĵ�����n��4<n<30�����ַ���ɣ��ַ��ڵ����г��ֵ�Ƶ�ȣ�Ȩֵ��Ϊw1��w2���������Ը��ݸ�Ȩֵ���й����������������������Ĵ�Ȩ·�����ȡ�
�����ʽ��

��һ�����ݣ���Ϊ�������룺��1��Ϊn��ֵ����2��Ϊn����������ʾ�ַ��ĳ���Ƶ�ȡ�
�����ʽ��

һ����������ʾ��������������Ĵ�Ȩ·�����ȣ�����������У���
����������

8
7 19 2 6 32 3 21 10

���������

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

void mergeTreeNode(Tree *T, int &length, int i, int j); //�ϲ����Ľڵ�
void findMin(Tree *T, int &length, int &i, int &j);     //Ѱ��Ȩֵ��С�������ڵ�
void traverse(Tree T, int deepth, int &ans);            //�ݹ�������������ۼӼ����Ȩ·������

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
    { //�����нڵ��������1ʱѭ��
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
{ //�ϲ����Ľڵ�
    if (length <= 1)
        return;
    //���ɺϲ���Ľڵ�
    Tree temp;
    temp = (Tree)malloc(sizeof(TreeNode));
    temp->weight = T[i]->weight + T[j]->weight;
    temp->lchild = T[i];
    temp->rchild = T[j];
    //�ڽڵ�������ɾ��ԭ�ڵ�i
    for (int k = i; k < length - 1; k++)
    {
        T[k] = T[k + 1];
    }
    length--;
    //�ڽڵ�������ɾ��ԭ�ڵ�j
    for (int k = j - 1; k < length - 1; k++)
    {
        T[k] = T[k + 1];
    }
    length--;
    //���ϲ���Ľڵ�洢����
    T[length++] = temp;
}

void findMin(Tree *T, int &length, int &i, int &j)
{ //Ѱ��Ȩֵ��С�������ڵ�
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
{ //�ݹ�������������ۼӼ����Ȩ·������
    if (T == NULL)
        return;
    if (T->lchild == NULL && T->rchild == NULL)
    {
        ans += T->weight * deepth;
    }
    traverse(T->lchild, deepth + 1, ans);
    traverse(T->rchild, deepth + 1, ans);
}
