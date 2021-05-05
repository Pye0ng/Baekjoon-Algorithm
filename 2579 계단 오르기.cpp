#include<stdio.h>
int max(int a, int b){ return a>b?a:b; }
int d[310], dp[310];

int main(){
	int n, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	dp[1]=d[1]; dp[2]=max(d[1]+d[2], d[2]); 
	for(i=3; i<=n; i++) dp[i]=max(dp[i-3]+d[i-1]+d[i], dp[i-2]+d[i]);
	printf("%d", dp[n]);
}
