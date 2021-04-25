/*
写一个函数，判断一个字符串是否是对称字符串，比如abcddcba，要求函数返回值是布尔类型。

输入格式：

手工输入一串字符串
输出格式：

输出布尔型数据1或者0
输入样例：

abcba
输出样例：

1
*/
#include <stdio.h>
#include <string.h>
int isSync(char *s);
int main()
{
	char s[100];
	gets(s);
	printf("%s: %d\n",s,isSync(s));
	
 } 
 int isSync(char *s)
 {
 	int front=0,rear=strlen(s)-1;
 	while(front<=rear){
 		if(s[front]!=s[rear])
 			return 0;
 		front++;
 		rear--;
	 }
	return 1;
 }
