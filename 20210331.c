/*
字符串处理-2-统计元音个数。
统计每个元音字母在字符串中出现的次数。
输入格式：

每组输入数据是一行长度不超过100的字符串。
输出格式：

对于每个测试实例输出5行
格式如下：a:num1 e:num2 i:num3 o:num4 u:num5
输入样例：

my name is ignatius
输出样例：

a:2
e:1
i:3
o:0
u:1
*/
#include <stdio.h>
int main()
{
	char s[101];
	int len=0,a=0,e=0,i=0,o=0,u=0,j=0;
	
	gets(s);
	while(s[j]!='\0'){
		switch (s[j]){
			case 'a':a++;break;
			case 'e':e++;break;
			case 'i':i++;break;
			case 'o':o++;break;
			case 'u':u++;break;
			default:break;
		}
		j++;
	}
	printf("a:%d\n",a);
	printf("e:%d\n",e);
	printf("i:%d\n",i);
	printf("o:%d\n",o);
	printf("u:%d\n",u);
	
	
}
