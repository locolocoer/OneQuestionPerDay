/*
дһ������������e������e�ļ��㹫ʽ��Ҫ�󾫶�10-5���ݣ�e�ļ��㹫ʽ��e=1/1!+1/2!+1/3��+ ����
�����ʽ��

ֱ�����e
���������

2.718282


*/
#include <stdio.h>
#include <math.h>
int main()
{
	double x=1,i=1;
	
	double res=1;
	while(x>pow(10,-6)){
		res+=x;
		i++;
		x/=i;
	}
	printf("e=%lf",res);
}
