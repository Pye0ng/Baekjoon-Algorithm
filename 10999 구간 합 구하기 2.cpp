#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
typedef long long int ll;
ll p[1000100], lz[4000100];
vector<ll> s;

ll seg(int c, int a, int b){
	if(a==b) return s[c]=p[a];
	int m=(a+b)>>1;
	return s[c]=seg(c<<1, a, m)+seg(c<<1|1, m+1, b);
}

void prop(int c, int a, int b){
	if(lz[c]==0) return;
	s[c]+=(b-a+1)*lz[c];
	if(a!=b){ lz[c<<1]+=lz[c]; lz[c<<1|1]+=lz[c]; }
	lz[c]=0;
}

void upd(int c, int a, int b, int l, int r, ll t){
	prop(c, a, b);
	if(a>r||b<l) return;
	if(l<=a&&b<=r){ lz[c]+=t; prop(c, a, b); return; }
	int m=(a+b)>>1;
	upd(c<<1, a, m, l, r, t);
	upd(c<<1|1, m+1, b, l, r, t);
	s[c]=s[c<<1]+s[c<<1|1];
}

ll sum(int c, int a, int b, int l, int r){
	prop(c, a, b);
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return sum(c<<1, a, m, l, r)+sum(c<<1|1, m+1, b, l, r);
}

int main(){
	int n, m, k, a, b, c, i; ll d;
	scanf("%d %d %d", &n, &m, &k); s.resize(n*4);
	for(i=1; i<=n; i++) scanf("%lld", &p[i]);
	seg(1, 1, n);
	for(i=0; i<m+k; i++){
		scanf("%d %d %d", &a, &b, &c);
		if(a&1){
			scanf("%lld", &d);
			upd(1, 1, n, b, c, d);
		}
		else printf("%lld\n", sum(1, 1, n, b, c));
	}
}
