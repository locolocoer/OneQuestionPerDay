/*
明日预告：西安电子科技大学上机题（二）
请写一个程序，找出给定矩阵的马鞍点。若一个矩阵中的元素在其所在行最小而在其所在列最大，则该元素为矩阵的一个马鞍点。
输入格式：

输入数据由m+1行构成，第一行只有两个整数m和n（0<m<100,0<n<100），分别表示矩阵的行数和列数，接下来m行，每行n个整数表示矩阵元素（矩阵中的元素互不相同），
整数之间以空格分隔。分别表示矩阵的行数和列数，接下来m行，每行n个整数表示矩阵元素（矩阵中的元素互不相同），整数之间以空格分隔。<>
输出格式：

在一行上输出马鞍点的行号、列号（行号和列号从0开始计数）及元素的值（用一个空格分隔），之后换行；若不存在马鞍点，则输出一个字符串“no”后换行。
输入样例：

4 3
11 13 121
407 72 88
23 58 1
134 30 62

输出样例：

1 1 72

*/
#include <stdio.h>
int isRowMinAndColMax(int a[100][100],int m,int n,int x,int y){
	int k;
	for(k=0;k<n;k++){
		if(a[x][k]<a[x][y])
			return 0;
	} 
	for(k=0;k<m;k++){
		if(a[k][y]>a[x][y])
			return 0;
	}
	return 1;
}
void findAndDisp(int a[100][100],int m,int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(isRowMinAndColMax(a,m,n,i,j))
			{
				printf("%d %d %d",i,j,a[i][j]);
				return;
			}
		}
	}
    printf("no");	
}
int main()
{
	int m,n,i,j;
	int a[100][100];
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	findAndDisp(a,m,n);
 } 
	
