/*
武汉大学上机题（三）


两个数字字符串相加。
有定义：char s1[200]，s2[200]，s3[200]
若输入s1和s2非全数字字符串，显示输入错误；
否则计算s1与s2相加后的结果，存放于s3并显示。
输入样例：

999999999999999999999
999999999999999999999
123456789012345678
876543211
输出样例：

1999999999999999999998
1234567891000000000
*/
#include <stdio.h>
#include <string.h>
int isAllNum(char *s){
	int i=0;
	while(s[i]!='\0'){
		if(s[i]<'0'&&s[i]>'9')
		return 0;
		i++; 
	}
	return 1;
}
void add(char *s1,char *s2,char *s3)
{
	int i, j;     //两个工作指针，分别指示s1、s2中当前运算数字
    int flag = 0; //s3中的工作指针，指示当前运算结果应存放的位置
    int cf = 0;   //进位标志
    //将i移到最后一位数字
    i = strlen(s1) - 1;
    //将j移到最后一位数字
    j = strlen(s2) - 1;
    //开始进行相加运算
    while (i >= 0 && j >= 0)
    {
        //运算当前位，cf为进位标志
        //首先要把字符转换成数字，单个数字的字符c转换成数字的方法：c - '0'
        int a, b;
        int res;
        a = s1[i] - '0';
        b = s2[j] - '0';
        res = a + b + cf;
        //判断是否进位
        if (res >= 10)
        {
            s3[flag] = res - 10 + '0';
            cf = 1;
        }
        else
        {
            s3[flag] = res + '0';
            cf = 0;
        }
        flag++;
        //工作指针前移，计算下一位
        i--;
        j--;
    }
    //注意处理剩余数字的时候不要忘了处理进位
    if (i >= 0)
    { //s1中还有剩余数字
        while (i >= 0)
        {
            int temp = s1[i] - '0' + cf;
            if (temp >= 10)
            {
                s3[flag] = temp - 10 + '0';
                cf = 1;
            }
            else
            {
                s3[flag] = temp + '0';
                cf = 0;
            }
            i--;
            flag++;
        }
    }
    else
    {
        while (j >= 0)
        {
            int temp = s2[j] - '0' + cf;
            if (temp >= 10)
            {
                s3[flag] = temp - 10 + '0';
                cf = 1;
            }
            else
            {
                s3[flag] = temp + '0';
                cf = 0;
            }
            j--;
            flag++;
        }
    }
    //最后进位的处理
    if (cf == 1)
    {
        s3[flag] = '1';
        flag++;
    }
    //flag++;
    s3[flag] = '\0';
    //现在需要将s3中结果逆置，就是运算结果了，s3中数字起始是0到flag-1
    i = 0;
    j = flag - 1;
    while (i < j)
    {
        //交换
        char c = s3[i];
        s3[i] = s3[j];
        s3[j] = c;
        i++;
        j--;
    }
}

int main()
{
	char s1[100],s2[100],s3[100];
	gets(s1);
	gets(s2);
	if(isAllNum(s1)&&isAllNum(s2)){
		add(s1,s2,s3);
		printf("%s",s3);
	}else{
		printf("输入错误");
	}
	
}
