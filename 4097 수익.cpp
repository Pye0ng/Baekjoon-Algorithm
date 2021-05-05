#include<stdio.h>
typedef long long int ll;
ll n, d[250010];
ll max(ll a, ll b){ return a>b?a:b; }

int main(){
	int i;
	scanf("%lld", &n);
	while(n){
		ll m=-10001, dp[250010]={};
		for(i=1; i<=n; i++) scanf("%lld", &d[i]);
		for(i=1; i<=n; i++){
			if(d[i]+dp[i-1]>=0) dp[i]=max(d[i], dp[i-1]+d[i]);
			else dp[i]=d[i];
			m=max(m, dp[i]); 
		}
		printf("%lld\n", m);
		scanf("%lld", &n); 
	}
}
