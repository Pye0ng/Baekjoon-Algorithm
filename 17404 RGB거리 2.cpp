#include<stdio.h>
int min(int a, int b){ return a<b?a:b; }
int rgb[1010][4], dp[1010][4]; //0 red, 1 green, 2 blue, dp[i][j]=i번집을 j색으로 칠할 때 1~i까지 최솟값 

int main(){
	int n, i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++)
		for(j=0; j<3; j++)
			scanf("%d", &rgb[i][j]);
	int ans=1e6+1;
	for(i=0; i<3; i++){	//한 색을 1번에 고정하고 계산
		for(j=0; j<3; j++){
			if(i==j) dp[1][j]=rgb[1][j];
			else dp[1][j]=1e6+1;
		}
		for(j=2; j<=n; j++){
			dp[j][0] = min(dp[j-1][1], dp[j-1][2]) + rgb[j][0];
			dp[j][1] = min(dp[j-1][0], dp[j-1][2]) + rgb[j][1];
			dp[j][2] = min(dp[j-1][0], dp[j-1][1]) + rgb[j][2];
		}
		for(j=0; j<3; j++){
			if(i==j) continue;
			ans=min(ans, dp[n][j]);
		}
	}
	printf("%d", ans);
} 
