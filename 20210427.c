/*
求一组字符串连续出现次数最多的字母。

输入格式：

手工输入一个字符串
输出格式：

输出连续出现次数最多的字母
输入样例：

abbccc
输出样例：

c
*/
#include <stdio.h>
int main()
{
	char s[100];
	int a[100];
	int i=0,j,temp=0;
	printf("输入字符串\n");
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
	printf("连续出现最多的字母为：");
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
