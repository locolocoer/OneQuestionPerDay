/*
给定若干个正整数，请判断素数的个数。

输入格式：

数据的个数N
N个大于1小于10000的整数
输出格式：

N个数中素数的个数
输入样例：

5 3 4 8 9 11
输出样例：

2
*/
#include <stdio.h>
#include <math.h>
int isPrime(int n)
{
	int i;
    if(n==1|n==2)
    	return 0;
    for(i=2;i<=sqrt(n);i++){
    	if(n%i==0)
    		return 0;
	}
	return 1;
}
int main()
{
	int i,n,num,count=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num);
		if(isPrime(num))
		count++;
	}
	printf("\n%d",count);
}
