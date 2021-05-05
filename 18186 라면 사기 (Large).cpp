#include<stdio.h>
typedef long long int ll;
ll ans, n, m, k, d[1000010];
ll min(ll a, ll b){ return a<b?a:b; }

int main(){
	ll t, i;
	scanf("%lld %lld %lld", &n, &m, &k);
	if(m<k) k=m;
	for(i=0; i<n; i++) scanf("%lld", &d[i]);
	for(i=0; i<n; i++){
		if(d[i+1]>d[i+2]){
			t=min(d[i], d[i+1]-d[i+2]);
			ans+=t*(m+k); d[i]-=t; d[i+1]-=t;
			t=min(d[i], min(d[i+1], d[i+2]));
			ans+=t*(m+2*k); d[i]-=t; d[i+1]-=t; d[i+2]-=t;
		}
		else{
			t=min(d[i], d[i+1]);
			ans+=t*(m+2*k); d[i]-=t; d[i+1]-=t; d[i+2]-=t;
			t=min(d[i], d[i+1]);
			ans+=t*(m+k); d[i]-=t; d[i+1]-=t; d[i+2]-=t;
		}
		ans+=d[i]*m;
		d[i]=0;
	}
	printf("%lld", ans);
}
