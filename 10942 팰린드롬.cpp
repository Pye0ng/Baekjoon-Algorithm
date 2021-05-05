#include<stdio.h>
int n, m, a, b, d[2010], dp[2010][2010];

int main(){
	int i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &d[i]);
		dp[i][i]=1;
	}
	for(i=1; i<n; i++)
		if(d[i]==d[i+1]) dp[i][i+1]=1;
	for(i=2; i<n; i++)
		for(j=1; j<=n-i; j++)
			if(d[j]==d[j+i]&&dp[j+1][j+i-1]) dp[j][j+i]=1;
	scanf("%d", &m);
	for(i=1; i<=m; i++){
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[a][b]);
	}
}
