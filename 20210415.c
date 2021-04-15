/*
上海交通大学上机题（一）

String to int
模仿atoi函数，找出一个字符串第一个int型的数字。
输入样例：

2016
000687CS01
输出样例：

2016
678
*/ 
#include <stdio.h>
int isNum(char c);
int myatoi(char *s);
int main()
{
	char s[100];
	gets(s);
	printf("%d",myatoi(s));
	
}
int isNum(char c){
	if(c>='0'&&c<='9')
	return 1;
	return 0;
}
int myatoi(char *s){
	int begin=0,result=0;
	int end;
	while(!isNum(s[begin])&&s[begin]!='\0'){
		begin++;
	}if(isNum(s[begin]))
    {
		end=begin+1;
		result=s[begin]-'0';
	}
	
	while(isNum(s[end])&&s[end]!='\0'){
		int a=s[end]-'0';
		result=result*10+a;
		end++;
	}
	if(s[begin-1]='-'&&begin>0)
	return -result;
	return result;
	
}
