/*
     华中科技大学上机题（一）
从键盘输入一行英文句子，句子中只有英文单词和空格，每个单词之间由若干个空格隔开，英文单词由大小写字母组成，编程完成下列任务：
    （1）统计并输出此句子中英文字母的个数；（10分）
    （2）统计并输出此句子中单词的个数；     （10分）
    （3）查找此句子中出现次数最多的字母（不区分大小写，大小写字母是相同的）和次数。当出现最多的字符不止一个时，都能找到，并输出找到的所有字母及次数。（输出字母时大小写均可）（20分）
输入格式：

输入句子：This is An Pencil Case
输出格式：

字母的个数
单词的个数
最多的字母
出现的次数
输入样例：

This is An Pencil Case
输出样例：

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

