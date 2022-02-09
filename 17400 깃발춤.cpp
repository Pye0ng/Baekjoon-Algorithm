#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
typedef long long int ll;
vector<ll> o, e;
ll od[301000], ev[301000];

ll sego(int c, int a, int b){
	if(a==b) return o[c]=od[a];
	int m=(a+b)>>1;
	return o[c]=sego(c<<1, a, m)+sego(c<<1|1, m+1, b);
}

ll sumo(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return o[c];
	int m=(a+b)>>1;
	return sumo(c<<1, a, m, l, r)+sumo(c<<1|1, m+1, b, l, r);
}

void updo(int c, int a, int b, int i, ll t){
	if(i<a||i>b) return;
	o[c]+=t; if(a==b) return;
	int m=(a+b)>>1;
	updo(c<<1, a, m, i, t);
	updo(c<<1|1, m+1, b, i, t);
}

ll sege(int c, int a, int b){
	if(a==b) return e[c]=ev[a];
	int m=(a+b)>>1;
	return e[c]=sege(c<<1, a, m)+sege(c<<1|1, m+1, b);
}

ll sume(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return e[c];
	int m=(a+b)>>1;
	return sume(c<<1, a, m, l, r)+sume(c<<1|1, m+1, b, l, r);
}

void upde(int c, int a, int b, int i, ll t){
	if(i<a||i>b) return;
	e[c]+=t; if(a==b) return;
	int m=(a+b)>>1;
	upde(c<<1, a, m, i, t);
	upde(c<<1|1, m+1, b, i, t);
}

int main(){
	int n, m, a, b, bo, be, co, ce, t, i; ll s, p, q;
	scanf("%d %d", &n, &m);
	o.resize(n*4); e.resize(n*4);
	t=((1<<int(ceil(log2(n))))+1)/2;
	for(i=1; i<=n; i++){
		scanf("%lld", &s);
		if(i&1) od[(i+1)/2]=s;
		else ev[i/2]=s;
	}
	sego(1, 1, t); sege(1, 1, t);
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		if(a&1){
			int c; scanf("%d", &c);
			if(b&1){ bo=(b+1)/2; be=(b+1)/2; }
			else{ bo=b/2+1; be=b/2; }
			if(c&1){ co=(c+1)/2; ce=c/2; }
			else{ co=c/2; ce=c/2; }
			p=bo<=co?sumo(1, 1, t, bo, co):0;
			q=be<=ce?sume(1, 1, t, be, ce):0;
			printf("%lld\n", abs(p-q));
		}
		else{
			ll c; scanf("%lld", &c);
			if(b&1) updo(1, 1, t, (b+1)/2, c);
			else upde(1, 1, t, b/2, c);
		}
	}
}
