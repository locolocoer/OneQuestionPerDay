/*
解密——加密的算法是26个英文字母，向后移三位为密文（a加密为d…最后x->a;y->b;z->c）有大小写。输入密文，计算明文。
输入格式：

输入密文
输出格式：

输出明文
输入样例：

An asdwa lijxa
输出样例：

Xk xpatx ifgux

*/
#include <stdio.h>
int isCharater(char c){
	if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
		return 1;
	}
	return 0;
} 
int isLower(char c){
	if(c>='a'&&c<='z'){
	return 1;
	}
	return 0; 
}
char decode(char c){
	if(isCharater(c)){
		if(isLower(c)){
			c=(c-'a'-3+26)%26+'a';
		}else{
			c=(c-'A'-3+26)%26+'A';
		} 
	}
	return c;
}
int main()
{
	int i=0;
	char s[101];
	gets(s);
	while(s[i]!='\0'){
		putchar(decode(s[i]));
		i++;
	}
}

