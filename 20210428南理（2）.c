/*************************************************************************
    > File Name: 20210428南理（2）.c
    > Author: FengDaxian
    > Mail: 1457901147@qq.com 
    > Created Time: 2021年04月28日 星期三 21时20分37秒
 ************************************************************************/

#include<stdio.h>
void fun(int n,int k)
{
	if(k>36){

		printf("进制太大，无法转换！！\n");
	}
	if(n==0){
		return ;
	}
	fun(n/k,k);
	int t=n%k;
	int i=0;
	char s;
	if(t>=10){
		for(i=10;i<=t;i++)
		{
			s='A'+i-10;
		}
		printf("%c",s);
	}else{

		printf("%d",t);
	}
}
int main()
{
	int n;
	printf("请输入带转化是数字：\n");
	scanf("%d",&n);
	printf("\n想要转化为几进制,请输入：\n");
	int k;
	scanf("%d",&k);
	printf("\n转化结果为：\n");
	fun(n,k);
	printf("\n");
	return 0;
}
