/*
从文件1输入一个文本，统计其数字（文本中有其他字符），并输出到文件2。
输入格式：

输入一串字符串
输出格式：

统计字符串中数字的个数并输出到文件2中
输入样例：

as6d65s6a
输出样例：

4

*/

#include <stdio.h>
#include <string.h>
int main()
{
char x[100];
printf("向文件中输入字符串：");
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
fprintf(fp3,"数字的个数为：%d",k);
return 0;	
}
