/*
是不是超素数？
如果一个数是素数，并且能被分解为C（C>=2）个连续素数的和，则称这个数为“超素数”，请编程判断一个数是否是超素数。
输入格式：

一个正整数N（1<N<100000）
输出格式：

给定的整数N为超素数，请输入yes，否则请输出no
输入样例：

5
输出样例：

yes

*/
#include <stdio.h>
#include <math.h>
#define MAXLEN 100000
int isPrimer(int n);
int isPrimerPlus(int n);
int sumArr(int *arr,int m,int n);
int main()
{
	int num;
	scanf("%d",&num);
	if(isPrimerPlus(num)){
		printf("yes");
	}else{
		printf("no");
	}
	return 0;
}
int isPrimer(int n)
{
	int i;
	if(n==1)
	return 0;
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0)
		return 0;
	}
	return 1;
 } 
 int isPrimerPlus(int n){
 	if(!isPrimer(n)){
 		return 0;
	 }
	 int result,i;
	 int arr[MAXLEN];
	 int length=0;
	 for(i=0;i<n;i++){
	 	if(isPrimer(i)){
	 		arr[length]=i;
	 		length++;
		 }
	 }
	 int p,q;
	 p=0;
	 q=length-1;
	 while(p<q){
	 	int sum=sumArr(arr,p,q);
	 	if(sum<n){
	 		p++;
		 }else if(sum>n){
		 	q++;
		 }else{
		 	break;
		 }
	 }
	 if(q==p){
	 	result=0;
	 }
	 else{
	 	for(i=p;i<=q;i++){
	 		printf("%d ",arr[i]);
		 }
		 printf("\n");
		 result=1;
	 }
	 return result;
 }
 int sumArr(int arr[],int m,int n)
 {
 	int i;
 	int sum=0;
 	for(i=m;i<=n;i++){
 		sum+=arr[i];
	 }
	 return sum;
 }
