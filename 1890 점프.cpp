#include<stdio.h>
long long int dp[1050][1050];
int n, d[1010][1010];

int main(){
	int i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++) scanf("%d", &d[i][j]);
	dp[1][1]=1;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++){
			if(i==n&&j==n) break;
			dp[i+d[i][j]][j]+=dp[i][j];
			dp[i][j+d[i][j]]+=dp[i][j];
		}
	printf("%lld", dp[n][n]);
}
