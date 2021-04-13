/*
明日预告：武汉大学上机题（二）
输入一个整数n（0<n<10），显示n行如下规律图形。
例如输入3 ，显示
          1
       2 3
    4 5 6
例如输入5，显示
                                        1
                                2      3
                        4      5      6
                 7     8      9     10
         11  12   13    14     15
*/
#include <stdio.h>
int main(){
	int n,i,j;
	int k=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=n-i;j>0;j--){
			printf("    ");
		}
		for(j=1;j<=i;j++){
			printf("%4d",k);
			k++;
		}
		printf("\n");
	}
	
}
