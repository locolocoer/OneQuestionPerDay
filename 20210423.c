/*
写一个函数，计算e，给了e的计算公式，要求精度10-5次幂，e的计算公式：e=1/1!+1/2!+1/3！+ ……
输出格式：

直接输出e
输出样例：

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
