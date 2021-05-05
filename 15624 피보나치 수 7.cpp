#include<stdio.h>
int n, i, d[1000010];

int main(){
	scanf("%d", &n);
	d[1]=1;
	for(i=2; i<=n; i++) d[i]=(d[i-1]+d[i-2])%1000000007;
	printf("%d", d[n]);
}
