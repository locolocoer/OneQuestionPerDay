/*
     ���пƼ���ѧ�ϻ��⣨һ��
�Ӽ�������һ��Ӣ�ľ��ӣ�������ֻ��Ӣ�ĵ��ʺͿո�ÿ������֮�������ɸ��ո������Ӣ�ĵ����ɴ�Сд��ĸ��ɣ���������������
    ��1��ͳ�Ʋ�����˾�����Ӣ����ĸ�ĸ�������10�֣�
    ��2��ͳ�Ʋ�����˾����е��ʵĸ�����     ��10�֣�
    ��3�����Ҵ˾����г��ִ���������ĸ�������ִ�Сд����Сд��ĸ����ͬ�ģ��ʹ����������������ַ���ֹһ��ʱ�������ҵ���������ҵ���������ĸ���������������ĸʱ��Сд���ɣ���20�֣�
�����ʽ��

������ӣ�This is An Pencil Case
�����ʽ��

��ĸ�ĸ���
���ʵĸ���
������ĸ
���ֵĴ���
����������

This is An Pencil Case
���������

18
5
i,s
3

*/
#include <stdio.h>
#include <string.h>
int isCharater(char c){
	if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
		return 1;
	}
	return 0;
}
int wordOfString(char *s){
	int i,result=0;
	int tag=0;
	for(i=0;i<=strlen(s);i++){
		if(s[i]!=' '&&s[i]!='\0'){
			tag=1;
		}else if(tag==1){
			result++;
			tag=0;
		}
	}
	return result;
}
int charOfString(char *s){
	int result=0,i=0;
	while(s[i]!='\0'){
		if(isCharater(s[i])){
			result++;
		}
		i++;
	}
	return result;
}
void numOfEveryChar(char *s,int *num){
	int i=0;
	while(s[i]!='\0'){
		if(s[i]>='a'&&s[i]<='z'){
			int a=s[i]-'a';
			num[a]++;
		}
		if(s[i]>='A'&&s[i]<='Z'){
			int a=s[i]-'A';
			num[a]++;
		}
		i++;
	}
}
int main()
{
	char s[300];
	int num[26];
	int max=0;
	int i;
	for(i=0;i<26;i++){
		num[i]=0;
	}
	gets(s);
	printf("%d\n",charOfString(s));
	printf("%d\n",wordOfString(s));
	numOfEveryChar(s,num);
	for(i=0;i<26;i++){
		if(num[i]>max){
			max=num[i];
		}
	}
	for(i=0;i<26;i++){
		if(num[i]==max){
			printf("%c ",'a'+i);
		}
	
	}
	printf("\n");
	printf("%d",max);
}

