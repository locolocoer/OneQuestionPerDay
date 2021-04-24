/*
输入格式：

手工输入一组无序数字
输出格式：

依次输出这组数据中0-9的个数
输入样例：

1 1 2 3 4 5 6 7 8 9 0
输出样例：

1 2 1 1 1 1 1 1 1 1 1
*/
#include <stdio.h>
void fun(int a[],int n,int res[])
{
	int i;
	for(i=0;i<10;i++){
		res[i]=0;
	}
	for(i=0;i<n;i++){
		res[a[i]]++;
	} 

} 
int main()
{
	char s;
	int a[100];
	int i=0;
	int res[10];
	do{
		scanf("%d",&a[i]);
		i++;
	}while((s=getchar())!='\n');
	fun(a,i,res);
	for(i=0;i<10;i++){
		printf(" %d",res[i]);
	}
}
