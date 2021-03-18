/*输入10个正整数（有奇数也有偶数），要求输出其中的每个奇数，并输出奇数个数与奇数之和。
输入格式：

10个正整数
输出格式：

输出奇数
奇数的个数
奇数的和
输入样例：

11 4 3 2 7 6 8 5 10 9
输出样例：

11 3 7 5 9
NUM=5
SUM=35*/
#include <stdio.h>
int main()
{
	int sum=0,count=0;
	int a,i;
	for(i=0;i<10;i++){
		scanf("%d",&a);
		if(a%2!=0){
			printf("%d ",a);
			sum+=a;
			count++;
		}
		
	}
	printf("\n");
	printf("NUM=%d\n",count);
	printf("SUM=%d\n",sum);
}

