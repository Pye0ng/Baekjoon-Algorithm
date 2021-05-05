#include<stdio.h>
int max(int a, int b){ return a>b?a:b; }
int d[1010], dp[1010];

int main(){
	int n, i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	dp[1]=d[1];
	for(i=2; i<=n; i++)
		for(j=1; j<=i; j++) dp[i]=max(d[i], max(dp[i], dp[i-j]+dp[j]));
	printf("%d", dp[n]);
}
