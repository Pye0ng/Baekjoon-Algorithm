#include<stdio.h>
int d[1010][1010], dp[1010][1010];
int max(int a, int b){ return a>b?a:b; }

int main(){
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++) scanf("%d", &d[i][j]);
	dp[1][1]=d[1][1];
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++){
			dp[i+1][j]=max(dp[i+1][j], dp[i][j]+d[i+1][j]);
			dp[i][j+1]=max(dp[i][j+1], dp[i][j]+d[i][j+1]);
			dp[i+1][j+1]=max(dp[i+1][j+1], dp[i][j]+d[i+1][j+1]);
		}
	printf("%d", dp[n][m]);
}
