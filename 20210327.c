/*
�������ɸ������������ж������ĸ�����

�����ʽ��

���ݵĸ���N
N������1С��10000������
�����ʽ��

N�����������ĸ���
����������

5 3 4 8 9 11
���������

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
