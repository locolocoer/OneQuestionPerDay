/*
字符串处理-3-合法标识符。
输入一个字符串，判断其是否是C语言的合法标识符，标识符由字母、下划线、数字这三种类型组成，但开头必须是字母或下划线（不用判断是否和保留字相同）。
输入格式：

每组输入数据是一个长度不超过50的字符串。
输出格式：

对于每组输入数据，如果是C的合法标识符，请输出“yes”，否则，输出“no”。
输入样例：

12ajf
输出样例：

no

*/
#include <stdio.h>
int isCharater(char s)
{
	if((s>='a'&&s<='z')||(s>='A'&&s<='Z')){
		return 1;
	}
	return 0;
}
int isNum(char s){
	if(s>='0'&&s<='9'){
		return 1;
	}
	return 0;
}
int isUnderline(char s){
	if('_'==s){
		return 1;
	}
	return 0;
}
int isValidIDentify(char *s){
	int i=0;
	if(s[0]=='\0'||isNum(s[0]))
	return 0;
	while('\0'!=s[i]){
		if(!isCharater(s[i])&&!isNum(s[i])&&!isUnderline(s[i])){
            return 0;
		}
		i++;
	}
	return i;
}
int main()
{
	char s[100];
	gets(s);
	int res=isValidIDentify(s);
	if(res==0||res>49){
		printf("no");
	}else{
		printf("yes");
	}
	
}
