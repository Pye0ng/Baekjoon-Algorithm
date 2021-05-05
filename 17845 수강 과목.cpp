#include<stdio.h>
int max(int a, int b){ return a>b?a:b; }
int w[1010], v[1010], dp[10010];

int main(){
	int n, k, i, j;
	scanf("%d %d", &n, &k);
	for(i=1; i<=k; i++) scanf("%d %d", &v[i], &w[i]);
	for(i=1; i<=k; i++)
		for(j=n; j>0; j--)
			if(w[i]<=j) dp[j]=max(dp[j], dp[j-w[i]]+v[i]);
	printf("%d", dp[n]);
}
