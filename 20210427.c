/*
��һ���ַ����������ִ���������ĸ��

�����ʽ��

�ֹ�����һ���ַ���
�����ʽ��

����������ִ���������ĸ
����������

abbccc
���������

c
*/
#include <stdio.h>
int main()
{
	char s[100];
	int a[100];
	int i=0,j,temp=0;
	printf("�����ַ���\n");
	gets(s);
	a[0]=1;
	while(s[i]!='\0'){
		if(s[i+1]==s[i]){
		a[i+1]=a[i]+1;	
		}else {
			a[i+1]=1;
		}
		i++;
	}
	printf("��������������ĸΪ��");
//	for(j=0;j<i+1;j++){
//		printf("%d",a[j]);
//	}
	int k=0;
	for(j=0;j<i+1;j++){
		if(temp<a[j]){
			temp=a[j];
			k=j;
		}
	} 
	for(j=0;j<i+1;j++){
		if(temp==a[j]){
			printf("%c",s[j]);
		}
	}
}
