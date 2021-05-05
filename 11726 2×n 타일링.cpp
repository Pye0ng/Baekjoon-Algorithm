#include<stdio.h>
#define M 10007
int n, dp[1010];

int main(){
	int i;
	scanf("%d", &n);
	dp[1]=1, dp[2]=2;
	for(i=3; i<=n; i++) dp[i]=(dp[i-1]%M+dp[i-2]%M)%M;
	printf("%d", dp[n]);
}
