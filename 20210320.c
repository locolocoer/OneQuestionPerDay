/*�ɼ�������һ�н���Ӣ����ĸ���ո���ɵ��ַ������ʵ�֣����ڵ���֮����һ���ո�����ո��������
��1�����ÿ�����ʼ��䳤�ȡ�
��2�������ĵ��ʡ�
����������

I am a boy
���������

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
		//��ÿ�����ʵ����±�
		while((isspace(str[i]))&&str[i]!='\0')
		{
			i++;
		}
		first=i;
		//��ÿ�����ʵ�ĩ�±�
		while(!isspace(str[i])&&str[i]!='\0')
		{
			i++;
		}
		//�������
		for(j=first;j<i;j++)
		{
		   printf("%c",str[j]);
		}
		//������ʳ���
		len=i-first;
		printf("\t%d\n",len);
		//�������
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

