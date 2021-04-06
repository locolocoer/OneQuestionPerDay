/*
明日预告：西安电子科技大学上机题（一）
编写一个程序，从键盘输入n个非零整数（0<n<1000），将这n个数中各位数字取出来相加，
并按照从小到大的次序依次输出这些数字和。例如，497的各位数字和为20（4+7+9），
1069的各位数字和为16（1+0+6+9）。< span=""></n<1000），
将这n个数中各位数字取出来相加，并按照从小到大的次序依次输出这些数字和。
例如，497的各位数字和为20（4+7+9），1069的各位数字和为16（1+0+6+9）。<>
输入格式：

输入的整数之间以空格分隔，输入为0时结束。
输出格式：

在一行上从小到大输出计算结果，整数之间用1个空格分隔，最后换行。
输入样例：

497 1069 68 71 137 0
输出样例：

8 11 14 16 20

*/
#include <stdio.h>
int sum(int a){
	int res=0;
	while(a>0){
		int m=a/10;
		res=res+(a-m*10);
		a/=10;
	} 
	return res;
}
int* sumAndSort(int a[],int len){
	int i,j;
	int b[1000];
	for(i=0;i<len;i++){
		b[i]=sum(a[i]);
	}
	for(i=0;i<len;i++){
		for(j=1;j<len;j++){
			if(b[i]>b[j]){
				int temp;
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
		}
	}
	for(i=0;i<len;i++){
		printf("%d ",b[i]);
	}
}
int main()
{
	int a[1000];
	int i=0;
	int len;
	scanf("%d",&a[i]);
	while(a[i]!=0){
		i++;
		scanf("%d",&a[i]);
	}
	len=i+1;
	sumAndSort(a,len-1);
}

