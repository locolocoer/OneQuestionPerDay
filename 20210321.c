/*给出一系列字符串及其对应id，要求找出某个字符串对应的id。
输入n+1行，第一行输入字符串个数，接下来输入n行，每行输入字符串及对应的id。
最后输入其中的一个字符串，输出该字符串对应的id。
输入格式：

数据的条数
输入每条数据的字符串和对应的id
要查询的字符串
输出格式：

对应的id
输入样例：

5
boring 5
interesting 8
hello 4
world 2
test 9
world
输出样例：

word对应的id是2*/
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
