/*
�ַ�������-2-ͳ��Ԫ��������
ͳ��ÿ��Ԫ����ĸ���ַ����г��ֵĴ�����
�����ʽ��

ÿ������������һ�г��Ȳ�����100���ַ�����
�����ʽ��

����ÿ������ʵ�����5��
��ʽ���£�a:num1 e:num2 i:num3 o:num4 u:num5
����������

my name is ignatius
���������

a:2
e:1
i:3
o:0
u:1
*/
#include <stdio.h>
int main()
{
	char s[101];
	int len=0,a=0,e=0,i=0,o=0,u=0,j=0;
	
	gets(s);
	while(s[j]!='\0'){
		switch (s[j]){
			case 'a':a++;break;
			case 'e':e++;break;
			case 'i':i++;break;
			case 'o':o++;break;
			case 'u':u++;break;
			default:break;
		}
		j++;
	}
	printf("a:%d\n",a);
	printf("e:%d\n",e);
	printf("i:%d\n",i);
	printf("o:%d\n",o);
	printf("u:%d\n",u);
	
	
}
