/*
�人��ѧ�ϻ��⣨����


���������ַ�����ӡ�
�ж��壺char s1[200]��s2[200]��s3[200]
������s1��s2��ȫ�����ַ�������ʾ�������
�������s1��s2��Ӻ�Ľ���������s3����ʾ��
����������

999999999999999999999
999999999999999999999
123456789012345678
876543211
���������

1999999999999999999998
1234567891000000000
*/
#include <stdio.h>
#include <string.h>
int isAllNum(char *s){
	int i=0;
	while(s[i]!='\0'){
		if(s[i]<'0'&&s[i]>'9')
		return 0;
		i++; 
	}
	return 1;
}
void add(char *s1,char *s2,char *s3)
{
	int i, j;     //��������ָ�룬�ֱ�ָʾs1��s2�е�ǰ��������
    int flag = 0; //s3�еĹ���ָ�룬ָʾ��ǰ������Ӧ��ŵ�λ��
    int cf = 0;   //��λ��־
    //��i�Ƶ����һλ����
    i = strlen(s1) - 1;
    //��j�Ƶ����һλ����
    j = strlen(s2) - 1;
    //��ʼ�����������
    while (i >= 0 && j >= 0)
    {
        //���㵱ǰλ��cfΪ��λ��־
        //����Ҫ���ַ�ת�������֣��������ֵ��ַ�cת�������ֵķ�����c - '0'
        int a, b;
        int res;
        a = s1[i] - '0';
        b = s2[j] - '0';
        res = a + b + cf;
        //�ж��Ƿ��λ
        if (res >= 10)
        {
            s3[flag] = res - 10 + '0';
            cf = 1;
        }
        else
        {
            s3[flag] = res + '0';
            cf = 0;
        }
        flag++;
        //����ָ��ǰ�ƣ�������һλ
        i--;
        j--;
    }
    //ע�⴦��ʣ�����ֵ�ʱ��Ҫ���˴����λ
    if (i >= 0)
    { //s1�л���ʣ������
        while (i >= 0)
        {
            int temp = s1[i] - '0' + cf;
            if (temp >= 10)
            {
                s3[flag] = temp - 10 + '0';
                cf = 1;
            }
            else
            {
                s3[flag] = temp + '0';
                cf = 0;
            }
            i--;
            flag++;
        }
    }
    else
    {
        while (j >= 0)
        {
            int temp = s2[j] - '0' + cf;
            if (temp >= 10)
            {
                s3[flag] = temp - 10 + '0';
                cf = 1;
            }
            else
            {
                s3[flag] = temp + '0';
                cf = 0;
            }
            j--;
            flag++;
        }
    }
    //����λ�Ĵ���
    if (cf == 1)
    {
        s3[flag] = '1';
        flag++;
    }
    //flag++;
    s3[flag] = '\0';
    //������Ҫ��s3�н�����ã������������ˣ�s3��������ʼ��0��flag-1
    i = 0;
    j = flag - 1;
    while (i < j)
    {
        //����
        char c = s3[i];
        s3[i] = s3[j];
        s3[j] = c;
        i++;
        j--;
    }
}

int main()
{
	char s1[100],s2[100],s3[100];
	gets(s1);
	gets(s2);
	if(isAllNum(s1)&&isAllNum(s2)){
		add(s1,s2,s3);
		printf("%s",s3);
	}else{
		printf("�������");
	}
	
}
