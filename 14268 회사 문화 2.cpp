#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
vector<int> g[100100], s, lz;
int cnt, p[100100], q[100100], v[100100];

void dfs(int t){
	v[t]=1; p[t]=++cnt;
	for(int i=0; i<g[t].size(); i++)
		if(!v[g[t][i]]) dfs(g[t][i]);
	q[t]=cnt;
}

void prop(int c, int a, int b){
	if(lz[c]==0) return;
	s[c]+=(b-a+1)*lz[c];
	if(a!=b){ lz[c<<1]+=lz[c]; lz[c<<1|1]+=lz[c]; }
	lz[c]=0;
}

void upd(int c, int a, int b, int l, int r, int t){
	prop(c, a, b);
	if(a>r||b<l) return;
	if(l<=a&&b<=r){
		lz[c]+=t;
		prop(c, a, b);
		return;
	}
	if(a==b) return;
	int m=(a+b)>>1;
	upd(c<<1, a, m, l, r, t);
	upd(c<<1|1, m+1, b, l, r, t);
	s[c]=s[c<<1]+s[c<<1|1];
}

int find(int c, int a, int b, int l, int r){
	prop(c, a, b);
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return find(c<<1, a, m, l, r)+find(c<<1|1, m+1, b, l, r);
}

int main(){
	int n, m, a, b, c, t, i;
	scanf("%d %d %d", &n, &m, &c);
	s.resize(n*4); lz.resize(n*4);
	for(i=2; i<=n; i++){
		scanf("%d", &c);
		g[c].push_back(i);
	}
	dfs(1); t=1<<int(ceil(log2(n)));
	while(m--){
		scanf("%d %d", &a, &b);
		if(a&1){
			scanf("%d", &c);
			upd(1, 1, t, p[b], q[b], c);
		}
		else printf("%d\n", find(1, 1, t, p[b], p[b]));
	}
}
