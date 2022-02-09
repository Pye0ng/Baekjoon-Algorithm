#include<stdio.h>
#include<math.h>
#include<vector>
typedef long long int ll;
using namespace std;
vector<ll> s, lz;
ll d[100100];

void prop(int c, int a, int b){
	s[c]+=lz[c]*(b-a+1);
	if(a!=b){ lz[c<<1]+=lz[c]; lz[c<<1|1]+=lz[c]; }
	lz[c]=0;
}

void upd(int c, int a, int b, int l, int r, ll t){
	if(lz[c]) prop(c, a, b);
	if(a>r||b<l) return;
	if(l<=a&&b<=r){
		lz[c]+=t;
		prop(c, a, b);
		return;
	}
	int m=(a+b)>>1;
	upd(c<<1, a, m, l, r, t);
	upd(c<<1|1, m+1, b, l, r, t);
	s[c]=s[c<<1]+s[c<<1|1];
}

ll sum(int c, int a, int b, int l, int r){
	if(lz[c]) prop(c, a, b);
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return sum(c<<1, a, m, l, r)+sum(c<<1|1, m+1, b, l, r);
}

int main(){
	int n, m, a, b, c, t, i;
	scanf("%d", &n); s.resize(n*4); lz.resize(n*4);
	for(i=1; i<=n; i++) scanf("%lld", &d[i]);
	t=1<<int(ceil(log2(n))); scanf("%d", &m);
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		if(a&1){
			scanf("%d", &c);
			upd(1, 1, t, b, c, 1);
			upd(1, 1, t, c+1, c+1, -c+b-1);
		}
		else printf("%lld\n", d[b]+sum(1, 1, t, 1, b));
	}
} 
