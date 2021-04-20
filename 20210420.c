/*
求众数。众数就是一个序列中出现次数最多的数字。如果不唯一，则输出小的那个值。给定第一个代表有几个数字。
1<=n<=10^5，每个数字在 int 范围内。
输入样例：

8
10 3 8 8 3 2 2 2

输出样例：

2
*/
#include <stdio.h>
int main(){
	int m;
	printf("输入多少个数：");
	scanf("%d",&m);
	printf("输入数字");
	int n[100];
	int i=0;
	while(i<m){
		scanf("%d",&n[i]);
		i++;
	} 
	int j=0;
	int cs=0;
	int k[100]={0};
	for(i=0;i<m;i++){
		cs=1;
		for(j=0;j<i;j++){
			if(n[j]=n[i])
			cs++;
		}
		k[i]=cs;
	}
	int max=0,t=0;
	for(i=0;i<m;i++){
		if(max<=k[i]){
			max=k[i];
			t=i;
		}
	}
	int p[100];
	for(i=0;i<m;i++){
		p[i]=-1;
	}
	j=0;
	for(i=0;i<m;i++){
		if(k[i]==max){
			p[j]=i;
			++j;
		}
	}
	int w[100];
	j=0;
	while(p[j]!=-1){
		w[j]=n[p[j]];
		j++;
	}
	int min=10000;
	for(i=0;i<j;++j){
		if(min>w[i]){
			min=w[i];
		}
	}
	printf("%d",min);
	return 0; 
}
