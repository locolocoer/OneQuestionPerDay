/*
���ļ�1����һ���ı���ͳ�������֣��ı����������ַ�������������ļ�2��
�����ʽ��

����һ���ַ���
�����ʽ��

ͳ���ַ��������ֵĸ�����������ļ�2��
����������

as6d65s6a
���������

4

*/

#include <stdio.h>
#include <string.h>
int main()
{
char x[100];
printf("���ļ��������ַ�����");
scanf("%s",x);
FILE *fp1=fopen("data.txt","w");
fputs(x,fp1);
fclose(fp1);
FILE *fp2=fopen("data.txt","r");
char v[100];
char *a;
int k=0;
int i;
a=fgets(v,strlen(x),fp2);
fclose(fp2);
for(i=0;i<strlen(x);i++){
	if(v[i]>='0'&&v[i]<='9')
	k++;
}
FILE *fp3=fopen("data2.txt","w");
fprintf(fp3,"���ֵĸ���Ϊ��%d",k);
return 0;	
}
