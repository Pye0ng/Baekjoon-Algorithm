#include<stdio.h>
int max(int a, int b){ return a>b?a:b; }
int w[25], dp[101];

int main(){
	int n, k, i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", &w[i]);
	for(i=1; i<=n; i++){
		scanf("%d", &k); 
		for(j=100; j>0; j--)
			if(w[i]<=j) dp[j]=max(dp[j], dp[j-w[i]]+k);
	}
	printf("%d", dp[99]);
} 
