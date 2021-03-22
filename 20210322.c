/*
 输入一组学生的成绩，以及一个给定区间，输出区间中成绩最高的学生的排名和成绩最低的学生排名。
输入格式：

输入成绩的条数
输入成绩（以空格隔开）
输入要查询成绩的区间【m，n】m，n以空格隔开
输出格式：

输出最高排名和最低排名
输入样例：

10
75 82 67 88 90 56 43 95 70 32
60 90
输出样例：

2 7
*/
#include<stdio.h>
void sort(int a[],int length);
int main()
{
	int grade[100];
	int length,i,m,n,min,max;
	scanf("%d",&length);
	for(i=0;i<length;i++){
		scanf("%d",&grade[i]);
	}
	scanf("%d%d",&m,&n);
	sort(grade,length);
	min=length-1;
	max=0;
	while(min>=0&&grade[min]<m) min--;
	while(max<length&&grade[max]>n) max++;
	printf("最高排名:%d 最低排名:%d ",max+1,min+1);
}
void sort(int grade[],int length)
{
	int i,j;
	for(i=0;i<length-1;i++){
		for(j=length-1;j>i;j--){
			if(grade[j]>grade[j-1]){
				int temp=grade[j-1];
				grade[j-1]=grade[j];
				grade[j]=temp;
			}
		}
	}
}
