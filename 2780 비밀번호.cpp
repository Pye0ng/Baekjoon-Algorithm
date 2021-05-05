#include<stdio.h>
int M=1234567, dp[1010][12];

int main(){
	int t, n, i;
	for(i=0; i<=9; i++) dp[1][i]=1;
	for(i=2; i<=1000; i++){
		dp[i][0]=dp[i-1][7];
		dp[i][1]=(dp[i-1][2]+dp[i-1][4])%M;
		dp[i][2]=(dp[i-1][1]+dp[i-1][5]+dp[i-1][3])%M;
		dp[i][3]=(dp[i-1][2]+dp[i-1][6])%M;
		dp[i][4]=(dp[i-1][1]+dp[i-1][5]+dp[i-1][7])%M;
		dp[i][5]=(dp[i-1][2]+dp[i-1][4]+dp[i-1][6]+dp[i-1][8])%M;
		dp[i][6]=(dp[i-1][3]+dp[i-1][5]+dp[i-1][9])%M;
		dp[i][7]=(dp[i-1][0]+dp[i-1][4]+dp[i-1][8])%M;
		dp[i][8]=(dp[i-1][5]+dp[i-1][7]+dp[i-1][9])%M;
		dp[i][9]=(dp[i-1][6]+dp[i-1][8])%M;
	}
	scanf("%d", &t);
	while(t--){
		int k=0;
		scanf("%d", &n);
		for(i=0; i<=9; i++) k+=dp[n][i];
		printf("%d\n", k%M);
	}
}
