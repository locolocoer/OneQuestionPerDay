/*
�ǲ���������
����������ָ������������������Ҳ���������������磺107��701�Ǿ�����������[m,n]��Χ֮�ڵ����о���������
�����ʽ��

��������������m��n������m<n
�����ʽ��

���[m,n]֮��ľ�������
����������

105 110
���������

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
	int m,n,i;
	scanf("%d%d",&m,&n);
	for(i=m;i<=n;i++){
		if(isPrimer(i)&&isPrimer(reverse(i))){
			printf("%d\n",i);
		}
	}
}
