#include<stdio.h>
#include<math.h>
#include<vector>
typedef long long int ll;
std::vector<ll> s;
ll n, k, hg, sz, d[100100];

ll sgmnt(int nw, int a, int b){
	if(a==b) return s[nw]=d[a];
	ll m=(a+b)/2;
	s[nw]=sgmnt(2*nw, a, m)+sgmnt(2*nw+1, m+1, b);
	return s[nw];
}

ll sgsm(int nw, int a, int b, int p, int q){
	if(b<p||a>q) return 0;
	if(b<=q&&a>=p) return s[nw];
	ll m=(a+b)/2;
	return sgsm(2*nw, a, m, p, q)+sgsm(2*nw+1, m+1, b, p, q);
}

void udt(int nw, int a, int b, int index, ll df){
	if(index<a||index>b) return;
	s[nw]+=df;
	if(a!=b){
		ll m=(a+b)/2;
		udt(2*nw, a, m, index, df);
		udt(2*nw+1, m+1, b, index, df);
	}
}

int main(){
	ll x, y, a, b;
	scanf("%lld %lld", &n, &k);
	hg=ceil(log2(n));
	sz=2<<(hg+1);
	s.resize(sz);
	for(int i=1; i<=n; i++) scanf("%lld", &d[i]);
	sgmnt(1, 1, n);
	while(k--){
		scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
		if(x<y) printf("%lld\n", sgsm(1, 1, n, x, y));
		else printf("%lld\n", sgsm(1, 1, n, y, x));
		ll df=b-d[a];
		d[a]=b;
		udt(1, 1, n, a, df);
	}
}
