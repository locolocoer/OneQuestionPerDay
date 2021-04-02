/*
字符串处理-4-单词统计。
给定一个字符串，请计算其中一共包含多少个单词（假设连续的非空格字母即为一个单词）。
输入格式：

输入数据是一个长度为S（0<s<1000）的字符串，其中只包含字母和空格。< p=""></s<1000）的字符串，其中只包含字母和空格。<>
输出格式：

请输出给定字符串一共包含的单词数。
输入样例：

Welcome to NWU
输出样例：

3

*/ 
#include <stdio.h>
int numOfString(char *s)
{
	int i=0;
	int num=0;
	while(s[i]!='\0'){
		if(s[i]==' '){
			num++;
		}
		i++;
	}
	return num+1;
}
int main()
{
	char s[1001];
	int count =0; 
	gets(s);
	count=numOfString(s);
	printf("%d",count);
}
