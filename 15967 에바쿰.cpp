#include<stdio.h>
#include<vector>
using namespace std;
typedef long long int ll;
ll p[1000100], lz[4000100];
vector<ll> s;

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

void upd(int c, int a, int b, int l, int r, int t){
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
	int n, q1, q2, a, b, c, d, i;
	scanf("%d %d %d", &n, &q1, &q2); s.resize(n*4);
	for(i=1; i<=n; i++) scanf("%lld", &p[i]);
	seg(1, 1, n);
	for(i=0; i<q1+q2; i++){
		scanf("%d %d %d", &a, &b, &c);
		if(a&1) printf("%lld\n", sum(1, 1, n, b, c));
		else{
			scanf("%d", &d);
			upd(1, 1, n, b, c, d);
		}
	}
}
