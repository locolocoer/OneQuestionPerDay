/*����һϵ���ַ��������Ӧid��Ҫ���ҳ�ĳ���ַ�����Ӧ��id��
����n+1�У���һ�������ַ�������������������n�У�ÿ�������ַ�������Ӧ��id��
����������е�һ���ַ�����������ַ�����Ӧ��id��
�����ʽ��

���ݵ�����
����ÿ�����ݵ��ַ����Ͷ�Ӧ��id
Ҫ��ѯ���ַ���
�����ʽ��

��Ӧ��id
����������

5
boring 5
interesting 8
hello 4
world 2
test 9
world
���������

word��Ӧ��id��2*/
#include <stdio.h>
#include <string.h>
#define LIM 20
#define MAXSIZE 100
int findKey(char *str[],int n,const char s[]){
	int i=0;
	while(strcmp(str[i],s))
	i++;
	return i;
}
int main()
{
	int m,n,a[LIM],key;
	int i=0,j=0;
	char ch;
	char *temp[LIM];
	char s[MAXSIZE];
	char str[LIM][MAXSIZE];
	scanf("%d",&n);
	getchar();
	while(i<n){
		while((ch=getchar())!=' '){
			str[i][j]=ch;
			j++;
		}
		str[i][j]='\0';
		temp[i]=str[i];
		j=0;
		scanf("%d",&a[i]);
		getchar();
		i++;
	} 
//	printf("%d,%d",n,a[0]);
//	puts(str[0]); 
//	printf("%s",str[0]);
//	scanf("%d",&key);
    gets(s);
	key=findKey(temp,n,s);
	printf("%d",a[key]);
	
}
