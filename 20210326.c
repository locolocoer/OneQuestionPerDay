/*
����һ�������������ж����Ƿ�Ϊ����������1�ͱ���û������Լ��������Ϊ������
�����ʽ��

��������ֻ����һ������N��1<n<10000��
�����ʽ��

�����������yes���������no
����������

23
���������

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
