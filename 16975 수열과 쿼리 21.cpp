#include<stdio.h>
#include<vector>
using namespace std;
typedef long long int ll;
vector<ll> s;
int p[100100];
ll lz[400100];

ll seg(int c, int a, int b){
	if(a==b) return s[c]=p[a];
	int m=(a+b)>>1;
	return s[c]=seg(c*2, a, m)+seg(c*2+1, m+1, b);
}

void prop(int c, int a, int b){
	if(lz[c]==0) return;
	s[c]+=lz[c]*(b-a+1);
	if(a!=b){ lz[c*2]+=lz[c]; lz[c*2+1]+=lz[c]; }
	lz[c]=0;
}

void upd(int c, int a, int b, int l, int r, ll t){
	prop(c, a, b);
	if(a>r||b<l) return;
	if(l<=a&&b<=r){
		s[c]+=t*(b-a+1);
		if(a!=b){ lz[c*2]+=t; lz[c*2+1]+=t; }
		return;
	}
	int m=(a+b)>>1;
	upd(c*2, a, m, l, r, t);
	upd(c*2+1, m+1, b, l, r, t);
	s[c]=s[c*2]+s[c*2+1];
}

ll sum(int c, int a, int b, int l, int r){
	prop(c, a, b);
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return sum(c*2, a, m, l, r)+sum(c*2+1, m+1, b, l, r);
}

int main(){
	int n, m, a, b, c, d, i;
	scanf("%d", &n); s.resize(n*4);
	for(i=1; i<=n; i++) scanf("%d", &p[i]);
	seg(1, 1, n);
	scanf("%d", &m);
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		if(a&1){
			scanf("%d %d", &c, &d);
			upd(1, 1, n, b, c, d);
		}
		else printf("%lld\n", sum(1, 1, n, b, b));
	}
}
