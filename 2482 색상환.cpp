#include<stdio.h>
int n, k, d[1010][1010], m=1e9+3;

int main(){
	int i, j;
	scanf("%d %d", &n, &k);
	for(i=1; i<=n; i++){ d[i][0]=1; d[i][1]=i; }
	for(i=3; i<=n; i++)
		for(j=2; j<=i; j++) d[i][j]=(d[i-2][j-1]+d[i-1][j])%m;
	printf("%d", (d[n-1][k]+d[n-3][k-1])%m);
}
