#include<stdio.h>
typedef long long int ll;
ll s, a[200100], b[200100], dp[200100][3];
ll mn(ll p, ll q){ return p<q?p:q; }

int main(){
	ll n, k, i;
	scanf("%lld %lld", &n, &k);
	for(i=0; i<n; i++) scanf("%lld", &a[i]);
	for(i=0; i<n; i++) scanf("%lld", &b[i]);
	dp[0][0]=a[0]; dp[0][1]=b[0];
	for(i=1; i<n; i++){
		dp[i][0]=mn(dp[i-1][0]+a[i], dp[i-1][1]+a[i]+k);
		dp[i][1]=mn(dp[i-1][0]+b[i]+k, dp[i-1][1]+b[i]);
	}
	printf("%lld", mn(dp[n-1][0], dp[n-1][1]));
} 
