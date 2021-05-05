#include<stdio.h>

int main(){
	int n, i, d[52];
	scanf("%d", &n);
	d[0]=1; d[1]=1;
	for(i=2; i<=n; i++) d[i]=(d[i-1]+d[i-2]+1)%1000000007;
	printf("%d", d[n]);
}
