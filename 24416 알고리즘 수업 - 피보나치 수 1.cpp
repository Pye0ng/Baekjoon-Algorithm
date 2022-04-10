#include<stdio.h>
int dp[42];

int main(){
	int n, i;
	dp[1]=dp[2]=1;
	scanf("%d", &n);
	for(i=3; i<=n; i++) dp[i]=dp[i-1]+dp[i-2];
	printf("%d %d", dp[n], n-2);
}
