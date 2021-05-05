#include<stdio.h>
int min(int a, int b){ return a<b?a:b; }
int n, m=1e5, d[1010], dp[1010];

int main(){
	int i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	dp[1]=d[1]; dp[2]=min(2*d[1], d[2]); dp[3]=min(dp[2]+d[1], d[3]);
	for(i=4; i<n; i++){
		dp[i]=d[i];
		for(j=1; j<i; j++) dp[i]=min(dp[i], d[j]+dp[i-j]);
	}
	for(i=1; i<=n; i++) m=min(m, d[i]+dp[n-i]);
	printf("%d", m);
}
