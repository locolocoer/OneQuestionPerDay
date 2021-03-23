/*
输入一堆要完成的任务，每个任务有开始时间和要完成的时间，求把这些任务做完最快要多久。（原题是回忆版题目，题意表述不是很明确，这里简单认为个任务可以在相同时间段内进行不会冲突，时间的格式采用的是整数）
输入格式：

输入任务的总数
各个任务开始的时间和所需要的时间
输出格式：

所需时间
输入样例：

5
2 10
5 3
4 9
6 3
7 7
输出样例：

12


*/
#define Max 20
typedef struct task{
	int start;
	int need_time;
} Task;
#include <stdio.h>
int main()
{
	
	int i,n,min,max=0;
	Task t[Max];
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d%d",&t[i].start,&t[i].need_time);
	} 
//	for(i=0;i<n;i++){
//		printf("%d %d\n",t[i].start,t[i].need_time);
//	}
    for(i=0;i<n;i++){
    	if(i==0){
    		min=t[i].start;
    		max=t[i].need_time+t[i].start; 
		}else{
		min=min<t[i].start?min:t[i].start;
    	max=max>(t[i].start+t[i].need_time)?max:(t[i].start+t[i].need_time);	
		}

	}
	printf("%d",max-min);
 } 
