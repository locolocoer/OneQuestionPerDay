/*
 ����һ��ѧ���ĳɼ����Լ�һ���������䣬��������гɼ���ߵ�ѧ���������ͳɼ���͵�ѧ��������
�����ʽ��

����ɼ�������
����ɼ����Կո������
����Ҫ��ѯ�ɼ������䡾m��n��m��n�Կո����
�����ʽ��

�������������������
����������

10
75 82 67 88 90 56 43 95 70 32
60 90
���������

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
	printf("�������:%d �������:%d ",max+1,min+1);
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
