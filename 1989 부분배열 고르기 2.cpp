#include<stdio.h>
#include<vector>
using namespace std;
typedef long long int ll;
ll max(ll a, ll b){ return a>b?a:b; }
struct ans{ ll t; int p, q; };
vector<int> mn;
vector<ll> s;
ll d[100100];
int n;

int segm(int c, int a, int b){
	if(a==b) return mn[c]=a;
	int m=(a+b)>>1, x, y;
	x=segm(c<<1, a, m); y=segm(c<<1|1, m+1, b);
	return mn[c]=d[x]<d[y]?x:y;
}

int findm(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return mn[c];
	int m=(a+b)>>1, x, y;
	x=findm(c<<1, a, m, l, r); y=findm(c<<1|1, m+1, b, l, r);
	return d[x]<d[y]?x:y;
}

ll segs(int c, int a, int b){
	if(a==b) return s[c]=d[a];
	int m=(a+b)>>1;
	return s[c]=segs(c<<1, a, m)+segs(c<<1|1, m+1, b);
}

ll finds(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return finds(c<<1, a, m, l, r)+finds(c<<1|1, m+1, b, l, r);
}

ans solve(int a, int b){
	int i=findm(1, 1, n, a, b);
	ans x, u; x.t=finds(1, 1, n, a, b)*d[i]; x.p=a; x.q=b;
	if(a<=i-1){
		u=solve(a, i-1);
		if(u.t>x.t) x=u;
	}
	if(b>=i+1){
		u=solve(i+1, b);
		if(u.t>x.t) x=u;
	}
	return x;
}

int main(){
	scanf("%d", &n); mn.resize(n*4); s.resize(n*4); d[0]=1e6+1;
	for(int i=1; i<=n; i++) scanf("%lld", &d[i]);
	segm(1, 1, n); segs(1, 1, n);
	ans x=solve(1, n);
	printf("%lld\n%d %d", x.t, x.p, x.q);
}
