/*
�ַ�������-3-�Ϸ���ʶ����
����һ���ַ������ж����Ƿ���C���ԵĺϷ���ʶ������ʶ������ĸ���»��ߡ�����������������ɣ�����ͷ��������ĸ���»��ߣ������ж��Ƿ�ͱ�������ͬ����
�����ʽ��

ÿ������������һ�����Ȳ�����50���ַ�����
�����ʽ��

����ÿ���������ݣ������C�ĺϷ���ʶ�����������yes�������������no����
����������

12ajf
���������

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
