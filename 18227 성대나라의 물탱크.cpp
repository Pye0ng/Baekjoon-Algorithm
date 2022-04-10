#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
typedef long long int ll;
vector<int> g[200200];
vector<ll> s;
int cnt, p[200200], q[200200];
ll h[200200];

void dfs(int n, ll t){
	h[n]=t; p[n]=++cnt;
	for(int i=0; i<g[n].size(); i++)
		if(h[g[n][i]]==0) dfs(g[n][i], t+1);
	q[n]=cnt;
}

void upd(int c, int a, int b, int i){
	if(i<a||i>b) return;
	s[c]++; int m=(a+b)>>1;
	if(a==b) return;
	upd(c<<1, a, m, i);
	upd(c<<1|1, m+1, b, i);
}

ll sum(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return sum(c<<1, a, m, l, r)+sum(c<<1|1, m+1, b, l, r);
}

int main(){
	int n, m, c, a, b, t, i;
	scanf("%d %d", &n, &c);
	t=1<<int(ceil(log2(n)));
	for(i=1; i<n; i++){
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	s.resize(n*4); dfs(c, 1);
	scanf("%d", &m);
	while(m--){
		scanf("%d %d", &a, &b);
		if(a&1) upd(1, 1, t, p[b]);
		else printf("%lld\n", h[b]*sum(1, 1, t, p[b], q[b])); 
	}
}
