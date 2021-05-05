#include<stdio.h>
int dp[15][15]; 

int main(){
	int n, p, t, i;
	for(i=1; i<=14; i++) dp[0][i]=i;
	for(i=1; i<=14; i++)
		for(int j=1; j<=14; j++)
			for(int k=1; k<=j; k++) dp[i][j]+=dp[i-1][k];
			
	scanf("%d", &t);
	for(i=1; i<=t; i++){
		scanf("%d %d", &p, &n);
		printf("%d\n", dp[p][n]);
	}
}
