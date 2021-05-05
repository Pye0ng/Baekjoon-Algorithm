#include<stdio.h>
int max(int a, int b){ return a>b?a:b; }
int n, m, d[10010], dp[10010];

int main(){
	int i;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	dp[1]=d[1]; dp[2]=d[1]+d[2]; dp[3]=max(d[1]+d[2], d[3]+max(d[1], d[2]));
	for(i=4; i<=n; i++) dp[i]=max(max(d[i]+dp[i-3]+d[i-1], dp[i-2]+d[i]), dp[i-1]);
	for(i=1; i<=n; i++) m=max(m, dp[i]);
	printf("%d", m);
}
