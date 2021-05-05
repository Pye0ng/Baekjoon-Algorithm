#include<stdio.h>
int n, m, k, dp[20][20];

int main(){
	int a, b, i, j;
	scanf("%d %d %d", &n, &m, &k);
	dp[1][1]=1;
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++){
			dp[i+1][j]+=dp[i][j];
			dp[i][j+1]+=dp[i][j];
		}
	if(k%m){ a=k/m+1; b=k%m; }
	else{ a=k/m; b=m; }
	if(k!=0) printf("%d", dp[a][b]*dp[n-a+1][m-b+1]);
	else printf("%d", dp[n][m]);
}
