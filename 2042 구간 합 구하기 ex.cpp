#include<stdio.h>
typedef long long int ll;
ll s[2002000];
int n;

void seg(){ for(int i=n-1; i; i--) s[i]=s[i<<1]+s[i<<1|1]; }

void upd(int t, int v){ for(s[t+=n]=v; t>1; t>>=1) s[t>>1]=s[t]+s[t^1]; }

ll sum(int l, int r){
	ll ans=0;
	for(l+=n, r+=n; l<r; l>>=1, r>>=1){
		printf("%d %d\n", l, r);
		if(l&1) ans+=s[l++];
		if(r&1) ans+=s[--r];
	}
	return ans;
}


int main(){
	int m, k, a, b, i;
	scanf("%d %d %d", &n, &m, &k);
	for(i=0; i<n; i++) scanf("%lld", &s[n+i]);
	seg(); ll c;
	for(i=0; i<m+k; i++){
		scanf("%d %d %lld", &a, &b, &c);
		if(a&1) upd(b-1, c);
		else printf("%lld", sum(b-1, c));
	}
}
