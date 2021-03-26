/*
给定一个正整数，请判断其是否为素数（除了1和本身，没有其它约数的数称为素数）
输入格式：

输入数据只包含一个整数N（1<n<10000）
输出格式：

是素数则输出yes，否则输出no
输入样例：

23
输出样例：

yes

*/
#include <stdio.h>
#include <math.h>
int isPrime(int n)
{
	int i;
	if(n==1|n==2)
	return 0;
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
 } 
int main()
{
	int n,result;
	scanf("%d",&n);
	result=isPrime(n);
	if(result){
		printf("yes");
	}else{
		printf("no");
	}
}
