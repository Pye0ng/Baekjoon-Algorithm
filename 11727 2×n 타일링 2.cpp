#include<stdio.h>
#define M 10007
int n, dp[1010];

int main(){
	int i;
	scanf("%d", &n);
	dp[0]=1, dp[1]=1;
	for(i=2; i<=n; i++) dp[i]=(dp[i-1]%M+dp[i-2]*2%M)%M;
	printf("%d", dp[n]);
}
