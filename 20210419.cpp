/*北京航空航天大学上机题（二）


每日编程中遇到任何疑问、意见、建议请公众号留言或加入每日编程群聊739635399


两个c程序语句，第一句定义变量，第二句变量做运算，找出第二句中所使用地未定义变量，其中数组和指针仅输出变量符号。

输入格式：

输入两句语句（输完第一句按回车键再输第二句）
输出格式：

输出第二句中所使用地未定义变量
输入样例：

int i,j,k;
i=1,j=2,m=3;
输出样例：

m
Image

解决方法：

（1）代码实现：
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 200
#define WORDSIZE 20
int GetKeyWord(char *variable_arr, int len1, char keyword[MAXSIZE][WORDSIZE]);                                        //存储第一行中的变量名
bool IsValidWord(char c);                                                                                             //字符C是否能作为变量
int GetCalculateWord(char *calculate_arr, int len2, char calculateword[MAXSIZE][WORDSIZE]);                           //存储第二行中的计算变量
void FindUndefinedWord(char keyword[MAXSIZE][WORDSIZE], int size1, char calculateword[MAXSIZE][WORDSIZE], int size2); //输出未定义变量
int HaveFrame(char calculateword[WORDSIZE]);                                                                          //变量中含有[]的，即为数组变量，返回数组变量的下标值，如a[5]返回5
bool JudgeArr(char calculateword[WORDSIZE], char keyword[WORDSIZE]);                                                  //判读两个数组变量[]前的数组变量名自否相同,如 a[5]与arr[6]比较a与arr
bool IsSameStr(char calculateword[WORDSIZE], char keyword[WORDSIZE]);                                                 //判断两个字符串是否相同

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

    char keyword[MAXSIZE][WORDSIZE];                                  //存储第一行中的变量名
    char calculateword[MAXSIZE][WORDSIZE];                            //存储第二行中的变量名
    int size1 = GetKeyWord(variable_arr, len1, keyword);              //返回值为第一行字符串数组的大小
    int size2 = GetCalculateWord(calculate_arr, len2, calculateword); //返回值为第二行字符串数组的大小

    FindUndefinedWord(keyword, size1, calculateword, size2);

    return 0;
}

int GetKeyWord(char *variable_arr, int len1, char keyword[MAXSIZE][WORDSIZE])
{
    //跳过变量类型 如int，float, struct Node....struct Node
    int i = 0;
    int size = 0; //变量名的个数keyword[size]
    int tag = 0;  //变量名字符串的下标keyword[size][tag]
    while (variable_arr[i] != ' ')
    { //类型后接一个或者多个空格，后面才是变量名
        ++i;
    }
    for (; i < len1;)
    { //开始分割存储变量名
        while (!IsValidWord(variable_arr[i]) && (i < len1))
        { //跳过多个空格或者逗号
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
        keyword[size][tag] = '\0'; //结尾加上'\0'
        tag = 0;
        ++size;
    }

    return size - 1; //此处减1 是因为最后写入一个空字符串，不减对之后的匹配操作没有影响
}

bool IsValidWord(char c)
{   //变量名的规则：字母，数组，下划线；
    //再加上一些特殊的，数组包含[]，(指针以地址存储，*p只存储p)
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
    //存储第二行，计算行中的计算变量  同理GetKeyWord()
    int i;
    int size = 0; //计算变量的个数calculateword[size]
    int tag = 0;  //计算变量字符串的下标calculateword[size][tag]
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
        if (calculateword[i][0] >= '0' && calculateword[i][0] <= '9') //此时变量为常数，直接跳过
            continue;
        for (j = 0; j < size1; j++)
        {
            int arrsize_calculate = HaveFrame(calculateword[i]);
            if (arrsize_calculate != -1)
            { //计算变量有[]，即为数组变量 arrsize_calculate为数组的下标
                int arrsize_keyword = HaveFrame(keyword[j]);
                if (arrsize_keyword != -1)
                { //变量名也有[]，即为数组变量 arrsize_keyword为数组大小
                    //先判断[]前面数组变量名是否相同，再判断数组下标是否越界
                    if (JudgeArr(calculateword[i], keyword[j]) && arrsize_keyword > arrsize_calculate)
                    { //数组未越界  继续判断
                        break;
                    }
                }
            }
            else
            { //非数组计算变量，直接比较字符串是否有一样的
                if (IsSameStr(calculateword[i], keyword[j]))
                { //有相同的，属于已定义
                    break;
                }
            }
        }
        if (j == size1) //没有找到匹配 属于未定义变量 输出
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
