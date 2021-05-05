#include<stdio.h>
int n, m, t[20], p[20], dp[20];
bool check[20];

int main(){
	int i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d %d", &t[i], &p[i]);
		if(t[i]+i>n+1) check[i]=1;
	}
	for(i=n; i>=1; i--){
		if(check[i]) continue;
		dp[i]=p[i];
		for(j=i+t[i]; j<=n; j++)
			if(p[i]+dp[j]>dp[i]) dp[i]=p[i]+dp[j];
		if(dp[i]>m) m=dp[i];
	}
	printf("%d", m);
}
