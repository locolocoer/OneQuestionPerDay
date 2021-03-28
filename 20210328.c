/*
是不是素数？
绝对素数是指本身是素数，其逆序也是素数的数，例如：107与701是绝对素数。求[m,n]范围之内的所有绝对素数。
输入格式：

输入两个正整数m和n，其中m<n
输出格式：

输出[m,n]之间的绝对素数
输入样例：

105 110
输出样例：

107
113
*/
#include <stdio.h>
#include <math.h>
int reverse(int n)
{
	int i=1,result=0;
	while(i!=0){
		i=n%10;
		n/=10;
		result=10*result+i; 
	}
	return result/10;
}
int isPrimer(int n){
	int i;
	if(n==1)
	return 0;
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0)
		return 0;
	}
	return 1;
} 
int main()
{
	int m,n,i;
	scanf("%d%d",&m,&n);
	for(i=m;i<=n;i++){
		if(isPrimer(i)&&isPrimer(reverse(i))){
			printf("%d\n",i);
		}
	}
}
