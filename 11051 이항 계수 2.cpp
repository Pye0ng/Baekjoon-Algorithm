#include<stdio.h>
int n, k, d[1010][1010];

int main(){
	int i, j;
	scanf("%d %d", &n, &k);
	d[0][0]=1;
	for(i=1; i<=n; i++){
		d[i][0]=1;
		for(j=1; j<=i; j++) d[i][j]=(d[i-1][j-1]+d[i-1][j])%10007;
	}
	printf("%d", d[n][k]);
}
