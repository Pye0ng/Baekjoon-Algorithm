#include<stdio.h>
int n, m, t[1500010], p[1500010], dp[1500010];
int max(int a, int b){ return a>b?a:b; }

int main(){
	int i;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d %d", &t[i], &p[i]);
	for(i=1; i<=n+1; i++){
		m=max(m, dp[i]);
		if(i+t[i]>n+1) continue;
		dp[i+t[i]]=max(m+p[i], dp[i+t[i]]);
	}
	printf("%d", m);
}
