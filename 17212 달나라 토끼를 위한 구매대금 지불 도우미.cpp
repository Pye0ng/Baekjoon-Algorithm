#include<stdio.h>
int min(int a, int b){ return a<b?a:b; }
int n, k, dp[100010];

int main(){
	int i;
	scanf("%d", &n);
	dp[1]=dp[2]=dp[5]=dp[7]=1;
	dp[3]=dp[4]=dp[6]=2;
	for(i=8; i<=n; i++){
		k=999999;
		k=min(k, min(min(dp[i-1], dp[i-2]), min(dp[i-5], dp[i-7])));
		dp[i]=k+1;
	}
	printf("%d", dp[n]);
}
