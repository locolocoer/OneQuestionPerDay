/*
дһ���������ж�һ���ַ����Ƿ��ǶԳ��ַ���������abcddcba��Ҫ��������ֵ�ǲ������͡�

�����ʽ��

�ֹ�����һ���ַ���
�����ʽ��

�������������1����0
����������

abcba
���������

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
