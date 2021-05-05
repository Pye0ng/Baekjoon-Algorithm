#include<stdio.h>
int n, m, k, dp[1000010];
int mx(int a, int b){ return a>b?a:b; }

int main(){
	int i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &k);
		dp[k]=dp[k-1]+1;
		m=mx(m, dp[k]);
	}
	printf("%d", n-m);
}
