/*
�人��ѧ�ϻ��⣨һ��



��������������a��b������[a��b]�е����������У�ÿ�����루digit0~9���������˶��ٴΡ�
�����ʽ��

����������a��b
�����ʽ��

ÿ��digit�����˶��ٴ�
����������

1 99
���������

9 20 20 20 20 20 20 20 20 20
*/ 
#include <stdio.h>
void count(int a,int c[]){
	int temp;
	while(a!=0){
	temp=a%10;
	a/=10;
	c[temp]++;	
	}

}
int main()
{
	int a,b;
	int c[10];
	int i;
	for(i=0;i<10;i++){
		c[i]=0;
	}
	scanf("%d%d",&a,&b);
	for(a;a<=b;a++){
		count(a,c);
	}
	for(i=0;i<10;i++){
		printf("%d ",c[i]);
	}
}
