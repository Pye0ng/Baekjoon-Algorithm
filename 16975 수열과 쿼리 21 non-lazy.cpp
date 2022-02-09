#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
typedef long long int ll;
ll d, p[200100];
vector<ll> f;

void upd(int c, int a, int b, int i, ll t){
	if(a>i||b<i) return;
	f[c]+=t; 
	if(a==b) return;
	int m=(a+b)>>1;
	upd(c<<1, a, m, i, t);
	upd(c<<1|1, m+1, b, i, t);
}

ll sum(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return f[c];
	int m=(a+b)>>1;
	return sum(c<<1, a, m, l, r)+sum(c<<1|1, m+1, b, l, r);
}

int main(){
	int n, m, a, b, c, t, i;
	scanf("%d", &n); f.resize(n*4);
	t=1<<int(ceil(log2(n)));
	for(i=1; i<=n; i++) scanf("%lld", &p[i]);
	scanf("%d", &m);
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		if(a&1){
			scanf("%d %lld", &c, &d);
			upd(1, 1, t, b, d);
			upd(1, 1, t, c+1, -d);
		}
		else printf("%lld\n", p[b]+sum(1, 1, t, 1, b)); 
	}
}
