/*
输入一段不超过80个英文字符的字符串，统计其中有多少个a字母    
输出格式：

输出这段英文字符中字母a的个数
输入样例：

fave cad ecd ygaijj
输出样例：

3
*/
#include <stdio.h>
int main()
{
	int i=0,n=0;
	char s[81];
	gets(s);
	while(s[i]!='\0'){
		if(s[i]=='a'){
			n++;
		}
		i++;
	}
	printf("%d",n);
}
