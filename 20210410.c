/*
              华中科技大学上机题（二）
十二进制是数学中一种以12为底数的计数系统，它由0~9，a，b组成，与十进制的队友关系是：
0~9对应0~9，a对应10，b对应11。例如，十二进制的a2，十进制是122。输入一个仅含十二进制数字的字符串（字母一律小写，不超过8个字符），完成下列任务：
    （1）输出该十二进制数每一位对应的十进制数（从高位到低位顺序输出，空格隔开）；
    （2）实现“十二进制”转“十进制”算法，输出该十二进制数对应的十进制数；
    （3）输出转换后的十进制数在内存中的每个二进制位（共4字节，每字节之间空格隔开）。
输入格式：

输入十二进制数：a2
输出格式：

如题
输入样例：

a2
输出样例：

10 2
122
00000000 00000000 00000000 01111010
*/
#include <stdio.h> 
int stringToNum(char c){
	if(c=='a')
	return 10;
	else if(c=='b')
	return 11;
	if(c>='0'&&c<='9'){
		return c-'0';
	}
}
int transform(char *s){
	int i=0,result=0;
	while(s[i]!='\0'){
	int a=stringToNum(s[i]);
	result=result*12+a; 
	i++; 
	} 
	return result;
}
void printBy2(int a,int b[]){
	int i;
	for(i=31;i>=0;i--){
		int c=a%2;
		a/=2;
		b[i]=c;
	}
	for(i=0;i<32;i++){
		printf("%d",b[i]);
		if(i%8==7)
		printf(" ");
	} 
}
int main(){
	char s[8];
	int b[32];
	int i=0,j;
	int a;
	gets(s);
    for(j=0;j<32;j++){
    	b[j]=0;
	} 
	while(s[i]!='\0'){
		printf("%d ",stringToNum(s[i]));
		i++;
	} 
	a=transform(s);
	printf("\n%d\n",a);
	printBy2(a,b);
 
	
}
