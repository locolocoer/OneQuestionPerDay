/*����10����������������Ҳ��ż������Ҫ��������е�ÿ���������������������������֮�͡�
�����ʽ��

10��������
�����ʽ��

�������
�����ĸ���
�����ĺ�
����������

11 4 3 2 7 6 8 5 10 9
���������

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

