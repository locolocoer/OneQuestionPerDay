/*
���ܡ������ܵ��㷨��26��Ӣ����ĸ���������λΪ���ģ�a����Ϊd�����x->a;y->b;z->c���д�Сд���������ģ��������ġ�
�����ʽ��

��������
�����ʽ��

�������
����������

An asdwa lijxa
���������

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

