#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long int ll;
ll d, p[1000100];
vector<ll> s, lz;
vector<int> v;

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

ll sum(int c, int a, int b, int l, int r){
	prop(c, a, b);
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return sum(c<<1, a, m, l, r)+sum(c<<1|1, m+1, b, l, r);
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

int main(){
	int n, m, a, b, c, i;
	scanf("%d %d", &n, &m);
	v.push_back(0); s.resize(m*4); lz.resize(m*4);
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		v.push_back(a); p[i]=c;
	}
	seg(1, 1, m);
	scanf("%d %d %d", &a, &b, &c);
	while(a){
		b=upper_bound(v.begin(), v.end(), b)-v.begin()-1;
		c=upper_bound(v.begin(), v.end(), c)-v.begin()-1;
		if(a&1){
			if(b>c) printf("%lld\n", sum(1, 1, m, b, m)+sum(1, 1, m, 1, c));
			else printf("%lld\n", sum(1, 1, m, b, c));
		}
		else{
			scanf("%lld", &d);
			if(b>c){
				upd(1, 1, m, b, m, d);
				upd(1, 1, m, 1, c, d);
			}
			else upd(1, 1, m, b, c, d);
		}
		scanf("%d %d %d", &a, &b, &c);
	}
}
