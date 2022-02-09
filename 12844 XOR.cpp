#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
int p[601000], lz[2000100];
vector<int> s;

int seg(int c, int a, int b){
	if(a==b) return s[c]=p[a];
	int m=(a+b)>>1;
	return s[c]=seg(c<<1, a, m)^seg(c<<1|1, m+1, b);
}

void prop(int c, int a, int b){
	if((b-a+1)&1) s[c]^=lz[c];
	if(a!=b){ lz[c<<1]^=lz[c]; lz[c<<1|1]^=lz[c]; }
	lz[c]=0;
}

void upd(int c, int a, int b, int l, int r, int t){
	if(lz[c]) prop(c, a, b);
	if(a>r||b<l) return;
	if(l<=a&&b<=r){ lz[c]^=t; prop(c, a, b); return; }
	int m=(a+b)>>1;
	upd(c<<1, a, m, l, r, t);
	upd(c<<1|1, m+1, b, l, r, t);
	s[c]=s[c<<1]^s[c<<1|1];
}

int sum(int c, int a, int b, int l, int r){
	if(lz[c]) prop(c, a, b);
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return sum(c<<1, a, m, l, r)^sum(c<<1|1, m+1, b, l, r);
}

int main(){
	int n, m, a, b, c, d, t, i;
	scanf("%d", &n); s.resize(n*4);
	for(i=0; i<n; i++) scanf("%d", &p[i]);
	t=1<<int(ceil(log2(n)));
	seg(1, 0, t-1); scanf("%d", &m);
	for(i=0; i<m; i++){
		scanf("%d %d %d", &a, &b, &c);
		if(b>c) swap(b, c);
		if(a&1){
			scanf("%d", &d);
			upd(1, 0, t-1, b, c, d);
		}
		else printf("%d\n", sum(1, 0, t-1, b, c));
	}
}
