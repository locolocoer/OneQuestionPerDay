/*
�������պ����ѧ�ϻ��⣨һ��


һ����������������򻯺��м������

�����ʽ��

����һ�����֣��м��ÿո������������Ϻ󣬰��س���������
�����ʽ��

������м���������м�����
����������

3 2 5 4 1
���������

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
