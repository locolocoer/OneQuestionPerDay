/*����1��+2��+3��+����+n�������6λ����֪n>=25ʱ���6λȫ0��
�����ʽ��

����n
�����ʽ��

���������
����������

32
���������

940313
*/
#include <stdio.h>
int last6Bit(int n){
	int a=n/1000000;
	return n-a*1000000;
}
int  fac6(int n){
	int  sum=1;
	int i;
	for(i=1;i<=n;i++){
		sum=last6Bit(sum); 
		sum*=i;
	}
	return sum;
} 
int main()
{
	int i,n,result=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		result=last6Bit(result);
		result+=fac6(i);
	}
	printf("%d",result);
}
