/*由键盘输入一行仅由英文字母及空格组成的字符，编程实现（相邻单词之间用一个空格或多个空格隔开）。
（1）输出每个单词及其长度。
（2）输出最长的单词。
输入样例：

I am a boy
输出样例：

I    1
am   2
a    1
boy  3
*/
#include<stdio.h>
#include<ctype.h>

int main()
{
	char str[50];
	char max_word[50];
	gets(str);
	int i=0,first=0,len,max_len=0,j,k;
	while(str[i]!='\0')
	{
		//找每个单词的首下标
		while((isspace(str[i]))&&str[i]!='\0')
		{
			i++;
		}
		first=i;
		//找每个单词的末下标
		while(!isspace(str[i])&&str[i]!='\0')
		{
			i++;
		}
		//输出单词
		for(j=first;j<i;j++)
		{
		   printf("%c",str[j]);
		}
		//输出单词长度
		len=i-first;
		printf("\t%d\n",len);
		//求最长单词
		if(len>max_len)
		{
			max_len=len;
			for(k=0;k<len;k++)
			{
				max_word[k]=str[first+k];
			}
			max_word[k]='\0';
		}
	}
printf("%s",max_word);
return 0;
}

