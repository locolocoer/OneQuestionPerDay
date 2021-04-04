/*
1-20号牌，输入牌的数目，以及每张牌的编号。只有三张连续的牌可以兑换一张新牌，新牌不能参与兑换。编程实现计算可兑换的牌数。
输入格式：

输入牌的数量
输入牌的编号
输出格式：

能兑换的牌的数量
输入样例：

10
1 1 2 2 3 5 5 6 7 9
输出样例：

2
*/
#include <stdio.h>
int main()
{
	int card[20];
	int i=0,s=0,canChange=0;
	int n;
	for(i=0;i<20;i++){
		card[i]=0;
	}
	printf("输入牌的数量：");
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		card[t]++; 
	}
	while(s<=17){
		if(card[s]>=1&&card[s+1]>=1&&card[s+2]>=1){
			card[s]--;
			card[s+1]--;
			card[s+2]--;
			canChange++;
		}else{
			s++;
		}
	}
	printf("%d",canChange);
 } 
