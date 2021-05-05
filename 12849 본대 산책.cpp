#include<stdio.h>
int m=1e9+7;
long long int dp[100010][10];

int main(){
	int n, i; dp[0][1]=1;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		dp[i][1]=(dp[i-1][2]+dp[i-1][3])%m;
		dp[i][2]=(dp[i-1][1]+dp[i-1][3]+dp[i-1][4])%m;
		dp[i][3]=(dp[i-1][1]+dp[i-1][2]+dp[i-1][4]+dp[i-1][5])%m;
		dp[i][4]=(dp[i-1][2]+dp[i-1][3]+dp[i-1][5]+dp[i-1][6])%m;
		dp[i][5]=(dp[i-1][3]+dp[i-1][4]+dp[i-1][6]+dp[i-1][8])%m;
		dp[i][6]=(dp[i-1][4]+dp[i-1][5]+dp[i-1][7])%m;
		dp[i][7]=(dp[i-1][6]+dp[i-1][8])%m;
		dp[i][8]=(dp[i-1][5]+dp[i-1][7])%m;
	}
	printf("%d", dp[n][1]);
}
