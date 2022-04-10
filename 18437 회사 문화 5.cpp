#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
vector<int> g[100100], s, lz;
int e, p[100100], q[100100], v[100100];

void dfs(int t){
	v[t]=1; p[t]=++e;
	for(int i=0; i<g[t].size(); i++)
		if(!v[g[t][i]]) dfs(g[t][i]);
	q[t]=e;
}

int seg(int c, int a, int b){
	lz[c]=-1; int m=(a+b)>>1;
	if(a==b) return s[c]=1;
	return s[c]=seg(c<<1, a, m)+seg(c<<1|1, m+1, b);
}

void prop(int c, int a, int b){
	if(lz[c]==-1) return;
	s[c]=lz[c]*(b-a+1);
	if(a!=b) lz[c<<1]=lz[c<<1|1]=lz[c];
	lz[c]=-1;
}

void upd(int c, int a, int b, int l, int r, int t){
	prop(c, a, b);
	if(a>r||b<l) return;
	if(l<=a&&b<=r){
		lz[c]=t;
		prop(c, a, b);
		return;
	}
	int m=(a+b)>>1;
	upd(c<<1, a, m, l, r, t);
	upd(c<<1|1, m+1, b, l, r, t);
	s[c]=s[c<<1]+s[c<<1|1];
}

int sum(int c, int a, int b, int l, int r){
	prop(c, a, b);
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return sum(c<<1, a, m, l, r)+sum(c<<1|1, m+1, b, l, r);
}

int main(){
	int n, m, a, b, t, i;
	scanf("%d %d", &n, &m);
	for(i=2; i<=n; i++){
		scanf("%d", &m);
		g[m].push_back(i);
	}
	dfs(1); t=1<<int(ceil(log2(n)));
	s.resize(n*4); lz.resize(n*4);
	seg(1, 1, t); q[0]=n;
	scanf("%d", &m);
	while(m--){
		scanf("%d %d", &a, &b);
		if(a==1) upd(1, 1, t, p[b]+1, q[b], 1);
		else if(a==2) upd(1, 1, t, p[b]+1, q[b], 0);
		else printf("%d\n", sum(1, 1, t, p[b]+1, q[b]));
	}
}
