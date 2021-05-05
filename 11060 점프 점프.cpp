#include<stdio.h>
int min(int a, int b){ return a<b?a:b; }
int n, k, d[1110], dp[1110];

int main(){
	int i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &d[i]);
		dp[i]=9999;
	}
	dp[1]=0;
	for(i=1; i<n; i++)
		for(j=i+1; j<=i+d[i]&&j<=n; j++) dp[j]=min(dp[j], dp[i]+1);
	if(dp[n]==9999) printf("-1");
	else printf("%d", dp[n]);
}
