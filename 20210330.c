/*
����һ�β�����80��Ӣ���ַ����ַ�����ͳ�������ж��ٸ�a��ĸ    
�����ʽ��

������Ӣ���ַ�����ĸa�ĸ���
����������

fave cad ecd ygaijj
���������

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
