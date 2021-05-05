#include<stdio.h>
int max(int a, int b){ return a>b?a:b; }
int w[110], v[110], dp[100010];

int main(){
	int n, k, i, j;
	scanf("%d %d", &n, &k);
	for(i=1; i<=n; i++) scanf("%d %d", &w[i], &v[i]);
	for(i=1; i<=n; i++)
		for(j=k; j>0; j--)
			if(j>=w[i]) dp[j]=max(dp[j], dp[j-w[i]]+v[i]);
	printf("%d", dp[k]);
}
