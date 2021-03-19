/*找出1000之内的所有完数，并输出完数和它的所有因子（一个数恰好等于他的因子之和，称为完数，例如：6=1+2+3）。
输出样例：

6 28 496
*/
#include<stdio.h>
int main()
{
	int i;
	int k=1,sum=0;
	for(i=2;i<=1000;i++){
		for(k=1;k<=(i/2);k++){
			if(i%k==0){
				sum+=k;
			}

		}

		if(sum==i)
		printf("%d ",i);
		sum=0;
	}
}
