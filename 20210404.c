/*
1-20���ƣ������Ƶ���Ŀ���Լ�ÿ���Ƶı�š�ֻ�������������ƿ��Զһ�һ�����ƣ����Ʋ��ܲ���һ������ʵ�ּ���ɶһ���������
�����ʽ��

�����Ƶ�����
�����Ƶı��
�����ʽ��

�ܶһ����Ƶ�����
����������

10
1 1 2 2 3 5 5 6 7 9
���������

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
	printf("�����Ƶ�������");
	
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
