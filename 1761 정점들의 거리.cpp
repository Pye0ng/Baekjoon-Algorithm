#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;
vector<pair<int, int> > g[40400];
int d[40400], v[40400], s[18][70000], p[18][70000];

void dfs(int n, int h){
	v[n]=1; d[n]=h;
	for(int i=0; i<g[n].size(); i++)
		if(!v[g[n][i].x]){
			s[0][g[n][i].x]=n;
			p[0][g[n][i].x]=g[n][i].y;
			dfs(g[n][i].x, h+1);
		}
}

int lca(int a, int b){
	int t=0;
	if(d[a]>d[b]) swap(a, b);
	for(int i=16; i>=0; i--)
		if(d[b]-d[a]>=(1<<i)){
			t+=p[i][b];
			b=s[i][b];
		}
	if(a==b) return t;
	for(int i=16; i>=0; i--)
		if(s[i][a]!=s[i][b]){
			t+=p[i][a]+p[i][b];
			a=s[i][a]; b=s[i][b];
		}
	return t+p[0][a]+p[0][b];
}

int main(){
	int n, m, a, b, c, i, j;
	scanf("%d", &n);
	for(i=1; i<n; i++){
		scanf("%d %d %d", &a, &b, &c);
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	dfs(1, 0);
	for(i=1; i<17; i++)
		for(j=1; j<=n; j++){
			s[i][j]=s[i-1][s[i-1][j]];
			p[i][j]=p[i-1][j]+p[i-1][s[i-1][j]];
		}
	scanf("%d", &m);
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}
}
