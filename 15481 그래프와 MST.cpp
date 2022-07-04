#include<stdio.h>
#include<vector>
#include<algorithm>
#define x first
#define y second
#define pb push_back
using namespace std;
struct tup{ int s, e, c; };
vector<tup> v, mst;
vector<pair<tup, int> > g;
vector<pair<int, int> > l[200200];
long long int w;
int p[200100], vis[200100], d[200100], in[200200], s[20][270000], mx[20][270000];

bool cmp1(pair<tup, int> a, pair<tup, int> b){ return a.x.c<b.x.c; }

bool cmp2(tup a, tup b){
	if(a.s<b.s) return 1;
	else if(a.s==b.s) return a.e<b.e;
	else return 0;
}

int find(int t){ return p[t]<0?t:p[t]=find(p[t]); }

void unite(int x, int y){
	x=find(x); y=find(y);
	if(x!=y){
		if(p[x]>p[y]) swap(x, y);
		p[x]+=p[y]; p[y]=x;
	}
}

void dfs(int n, int h){
	vis[n]=1; d[n]=h;
	for(int i=0; i<l[n].size(); i++)
		if(!vis[l[n][i].x]){
			s[0][l[n][i].x]=n;
			mx[0][l[n][i].x]=l[n][i].y;
			dfs(l[n][i].x, h+1);
		}
}

int lca(int a, int b){
	int m=0, i;
	if(d[a]>d[b]) swap(a, b);
	for(i=18; i>=0; i--)
		if(d[b]-d[a]>=(1<<i)){
			m=max(m, mx[i][b]);
			b=s[i][b];
		}
	if(a==b) return m;
	for(i=18; i>=0; i--)
		if(s[i][a]!=s[i][b]){
			m=max(m, max(mx[i][a], mx[i][b]));
			a=s[i][a]; b=s[i][b];
		}
	return max(m, max(mx[0][a], mx[0][b]));
}

int main(){
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++) p[i]=-1;
	for(i=0; i<m; i++){
		tup t;
		scanf("%d %d %d", &t.s, &t.e ,&t.c);
		if(t.s>t.e) swap(t.s, t.e);
		g.pb({t, i}); v.pb(t);
	}
	sort(g.begin(), g.end(), cmp1);
	for(i=0; i<m; i++)
		if(find(g[i].x.s)!=find(g[i].x.e)){
			unite(g[i].x.s, g[i].x.e);
			w+=g[i].x.c; mst.pb(g[i].x);
			l[g[i].x.s].pb({g[i].x.e, g[i].x.c});
			l[g[i].x.e].pb({g[i].x.s, g[i].x.c});
			in[g[i].y]=1;
		}
	sort(mst.begin(), mst.end(), cmp2);
	dfs(1, 0);
	for(i=1; i<19; i++)
		for(j=1; j<=n; j++){
			s[i][j]=s[i-1][s[i-1][j]];
			mx[i][j]=max(mx[i-1][j], mx[i-1][s[i-1][j]]);
		}
	
	for(i=0; i<m; i++){
		if(in[i]) printf("%lld\n", w);
		else printf("%lld\n", w-lca(v[i].s, v[i].e)+v[i].c);
	}
}
