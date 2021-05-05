#include<stdio.h>
int n, k, d[50][2];

int main(){
	scanf("%d", &n);
	d[1][1]=1; d[2][0]=d[2][1]=1;
	for(int i=3; i<=n; i++){
		d[i][0]=d[i-1][1];
		d[i][1]=d[i-1][0]+d[i-1][1];
	} 
	printf("%d %d", d[n][0], d[n][1]);
}
