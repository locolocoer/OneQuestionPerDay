/*
武汉大学上机题（一）



给定两个正整数a和b，求在[a，b]中的所有整数中，每个数码（digit0~9）各出现了多少次。
输入格式：

给定两个数a和b
输出格式：

每个digit出现了多少次
输入样例：

1 99
输出样例：

9 20 20 20 20 20 20 20 20 20
*/ 
#include <stdio.h>
void count(int a,int c[]){
	int temp;
	while(a!=0){
	temp=a%10;
	a/=10;
	c[temp]++;	
	}

}
int main()
{
	int a,b;
	int c[10];
	int i;
	for(i=0;i<10;i++){
		c[i]=0;
	}
	scanf("%d%d",&a,&b);
	for(a;a<=b;a++){
		count(a,c);
	}
	for(i=0;i<10;i++){
		printf("%d ",c[i]);
	}
}
