/*
北京航空航天大学上机题（一）


一组无序数，输出有序化后中间的数。

输入格式：

输入一组数字，中间用空格隔开，输入完毕后，按回车键结束。
输出格式：

如果有中间数，输出中间数。
输入样例：

3 2 5 4 1
输出样例：

3
*/
#include <iostream>
using namespace std;
void sort(int a[],int n);
int main()
{
	int a[100];
	int i=0;
	do{
		cin>>a[i++];
	}while(getchar()!='\n');
	sort(a,i);
	if(i%2!=0){
		cout<<a[i/2];
	}else{
		cout<<((a[i/2]+a[i/2-1])/2.0);
	}
	
 } 
 void sort(int a[],int n)
 {
 	int flag=0;
 	int temp;
 	for(int i=n-1;i>=1;i--){
 		flag=0;
 		for(int j=1;j<=i;j++){
 			if(a[j-1]>a[j]){
 				temp=a[j];
 				a[j]=a[j-1];
 				a[j-1]=temp;
 				flag=1;
			 }
			 
		 }
		 if(flag==0)
		 return;
	 }
 }
