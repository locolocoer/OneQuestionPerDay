/*
����һ��Ҫ��ɵ�����ÿ�������п�ʼʱ���Ҫ��ɵ�ʱ�䣬�����Щ�����������Ҫ��á���ԭ���ǻ������Ŀ������������Ǻ���ȷ���������Ϊ�������������ͬʱ����ڽ��в����ͻ��ʱ��ĸ�ʽ���õ���������
�����ʽ��

�������������
��������ʼ��ʱ�������Ҫ��ʱ��
�����ʽ��

����ʱ��
����������

5
2 10
5 3
4 9
6 3
7 7
���������

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
