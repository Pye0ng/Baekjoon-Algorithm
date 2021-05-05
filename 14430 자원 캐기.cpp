#include<stdio.h>
int max(int a, int b){ return a>b?a:b; }
int n, m, d[310][310], dp[310][310];

int main(){
	int i, j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++){
			scanf("%d", &d[i][j]);
			dp[i][j]=d[i][j];
		}
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
			dp[i][j]=max(dp[i-1][j], dp[i][j-1])+d[i][j];
	printf("%d", dp[n][m]);
}
