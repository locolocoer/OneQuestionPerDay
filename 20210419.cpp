/*�������պ����ѧ�ϻ��⣨����


ÿ�ձ���������κ����ʡ�����������빫�ں����Ի����ÿ�ձ��Ⱥ��739635399


����c������䣬��һ�䶨��������ڶ�����������㣬�ҳ��ڶ�������ʹ�õ�δ������������������ָ�������������š�

�����ʽ��

����������䣨�����һ�䰴�س�������ڶ��䣩
�����ʽ��

����ڶ�������ʹ�õ�δ�������
����������

int i,j,k;
i=1,j=2,m=3;
���������

m
Image

���������

��1������ʵ�֣�
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 200
#define WORDSIZE 20
int GetKeyWord(char *variable_arr, int len1, char keyword[MAXSIZE][WORDSIZE]);                                        //�洢��һ���еı�����
bool IsValidWord(char c);                                                                                             //�ַ�C�Ƿ�����Ϊ����
int GetCalculateWord(char *calculate_arr, int len2, char calculateword[MAXSIZE][WORDSIZE]);                           //�洢�ڶ����еļ������
void FindUndefinedWord(char keyword[MAXSIZE][WORDSIZE], int size1, char calculateword[MAXSIZE][WORDSIZE], int size2); //���δ�������
int HaveFrame(char calculateword[WORDSIZE]);                                                                          //�����к���[]�ģ���Ϊ�����������������������±�ֵ����a[5]����5
bool JudgeArr(char calculateword[WORDSIZE], char keyword[WORDSIZE]);                                                  //�ж������������[]ǰ������������Է���ͬ,�� a[5]��arr[6]�Ƚ�a��arr
bool IsSameStr(char calculateword[WORDSIZE], char keyword[WORDSIZE]);                                                 //�ж������ַ����Ƿ���ͬ

int main()
{

    char variable_arr[MAXSIZE];
    char calculate_arr[MAXSIZE];
    int len1 = 0, len2 = 0;
    char ch;
    ch = getchar();
    while (ch != '\n')
    {
        variable_arr[len1++] = ch;
        ch = getchar();
    }
    variable_arr[len1] = '\0';
    ch = getchar();
    while (ch != ';')
    {
        calculate_arr[len2++] = ch;
        ch = getchar();
    }
    calculate_arr[len2] = '\0';

    //printf("%s\n%s\n",variable_arr,calculate_arr);

    char keyword[MAXSIZE][WORDSIZE];                                  //�洢��һ���еı�����
    char calculateword[MAXSIZE][WORDSIZE];                            //�洢�ڶ����еı�����
    int size1 = GetKeyWord(variable_arr, len1, keyword);              //����ֵΪ��һ���ַ�������Ĵ�С
    int size2 = GetCalculateWord(calculate_arr, len2, calculateword); //����ֵΪ�ڶ����ַ�������Ĵ�С

    FindUndefinedWord(keyword, size1, calculateword, size2);

    return 0;
}

int GetKeyWord(char *variable_arr, int len1, char keyword[MAXSIZE][WORDSIZE])
{
    //������������ ��int��float, struct Node....struct Node
    int i = 0;
    int size = 0; //�������ĸ���keyword[size]
    int tag = 0;  //�������ַ������±�keyword[size][tag]
    while (variable_arr[i] != ' ')
    { //���ͺ��һ�����߶���ո񣬺�����Ǳ�����
        ++i;
    }
    for (; i < len1;)
    { //��ʼ�ָ�洢������
        while (!IsValidWord(variable_arr[i]) && (i < len1))
        { //��������ո���߶���
            if (variable_arr[i] == '=')
            {
                while (variable_arr[i] != ',')
                    ++i;
            }
            else
            {
                ++i;
            }
        }
        while (IsValidWord(variable_arr[i]))
        {
            keyword[size][tag++] = variable_arr[i];
            ++i;
        }
        keyword[size][tag] = '\0'; //��β����'\0'
        tag = 0;
        ++size;
    }

    return size - 1; //�˴���1 ����Ϊ���д��һ�����ַ�����������֮���ƥ�����û��Ӱ��
}

bool IsValidWord(char c)
{   //�������Ĺ�����ĸ�����飬�»��ߣ�
    //�ټ���һЩ����ģ��������[]��(ָ���Ե�ַ�洢��*pֻ�洢p)
    if (c >= 'a' && c <= 'z')
        return true;
    if (c >= 'A' && c <= 'Z')
        return true;
    if (c >= '0' && c <= '9')
        return true;
    if (c == '[' || c == ']' || c == '_')
        return true;

    return false;
}

int GetCalculateWord(char *calculate_arr, int len2, char calculateword[MAXSIZE][WORDSIZE])
{
    //�洢�ڶ��У��������еļ������  ͬ��GetKeyWord()
    int i;
    int size = 0; //��������ĸ���calculateword[size]
    int tag = 0;  //��������ַ������±�calculateword[size][tag]
    for (i = 0; i < len2;)
    {
        while (!IsValidWord(calculate_arr[i]) && i < len2)
        {
            ++i;
        }
        while (IsValidWord(calculate_arr[i]))
        {
            calculateword[size][tag++] = calculate_arr[i];
            ++i;
        }
        calculateword[size][tag] = '\0';
        tag = 0;
        ++size;
    }
    return size;
}

void FindUndefinedWord(char keyword[MAXSIZE][WORDSIZE], int size1, char calculateword[MAXSIZE][WORDSIZE], int size2)
{
    int i, j;
    for (i = 0; i < size2; i++)
    {
        if (calculateword[i][0] >= '0' && calculateword[i][0] <= '9') //��ʱ����Ϊ������ֱ������
            continue;
        for (j = 0; j < size1; j++)
        {
            int arrsize_calculate = HaveFrame(calculateword[i]);
            if (arrsize_calculate != -1)
            { //���������[]����Ϊ������� arrsize_calculateΪ������±�
                int arrsize_keyword = HaveFrame(keyword[j]);
                if (arrsize_keyword != -1)
                { //������Ҳ��[]����Ϊ������� arrsize_keywordΪ�����С
                    //���ж�[]ǰ������������Ƿ���ͬ�����ж������±��Ƿ�Խ��
                    if (JudgeArr(calculateword[i], keyword[j]) && arrsize_keyword > arrsize_calculate)
                    { //����δԽ��  �����ж�
                        break;
                    }
                }
            }
            else
            { //��������������ֱ�ӱȽ��ַ����Ƿ���һ����
                if (IsSameStr(calculateword[i], keyword[j]))
                { //����ͬ�ģ������Ѷ���
                    break;
                }
            }
        }
        if (j == size1) //û���ҵ�ƥ�� ����δ������� ���
            printf("%s ", calculateword[i]);
    }
    printf("\n");
}

int HaveFrame(char calculateword[WORDSIZE])
{

    int i;
    int begin, end;
    begin = end = -1;
    for (i = 0; calculateword[i] != '\0'; i++)
    {
        if (calculateword[i] == '[')
            begin = i;
        if (calculateword[i] == ']')
        {
            end = i;
            break;
        }
    }
    int sizeOfArr = 0;
    if (begin > 0 && end > 0)
    {
        for (i = begin + 1; i < end; i++)
            sizeOfArr = sizeOfArr * 10 + int(calculateword[i] - '0');
        //printf("***%d***\n", sizeOfArr);
        return sizeOfArr;
    }
    return -1;
}

bool JudgeArr(char calculateword[WORDSIZE], char keyword[WORDSIZE])
{
    int i;
    for (i = 0; calculateword[i] != '['; i++)
    {
        if (keyword[i] != calculateword[i])
            return false;
    }
    if (keyword[i] != '[')
        return false;
    return true;
}

bool IsSameStr(char calculateword[WORDSIZE], char keyword[WORDSIZE])
{
    int len1 = strlen(calculateword);
    int len2 = strlen(keyword);
    if (len1 != len2)
        return false;
    int i;
    for (i = 0; i < len1; i++)
    {
        if (keyword[i] != calculateword[i])
            return false;
    }
    return true;
}
