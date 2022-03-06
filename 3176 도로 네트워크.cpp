#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pa;
vector<pa> v[100100];
int p[100100], c[100100], vis[100100], d[20][100100];
pa s[20][100100];

pa unite(pa a, pa b){ return {min(a.x, b.x), max(a.y, b.y)}; }

void dfs(int n, int h){
	vis[n]=1; c[n]=h;
	for(int i=0; i<v[n].size(); i++)
		if(!vis[v[n][i].x]){
			d[0][v[n][i].x]=n;
			s[0][v[n][i].x]={v[n][i].y, v[n][i].y};
			dfs(v[n][i].x, h+1);
		}
}

pa lca(int a, int b){
	pa ans=make_pair(1e7, 0);
	if(c[a]>c[b]) swap(a, b);
	for(int i=16; i>=0; i--)
		if(c[b]-c[a]>=(1<<i)){
			ans=unite(ans, s[i][b]);
			b=d[i][b];
		}
	if(a==b) return ans;
	for(int i=16; i>=0; i--)
		if(d[i][a]!=d[i][b]){
			ans=unite(ans, unite(s[i][a], s[i][b]));
			a=d[i][a]; b=d[i][b];
		}
	return unite(ans, unite(s[0][a], s[0][b]));
}

int main(){
	int n, m, a, b, i, j;
	scanf("%d", &n);
	for(i=1; i<n; i++){
		scanf("%d %d %d", &a, &b, &m);
		v[a].push_back({b, m});
		v[b].push_back({a, m});
		p[a]++; p[b]++;
	}
	m=0;
	for(i=1; i<=n; i++)
		if(p[i]>p[m]) m=i;
	dfs(m, 0);
	for(i=1; i<17; i++)
		for(j=1; j<=n; j++){
			m=d[i-1][j];
			d[i][j]=d[i-1][m];
			s[i][j]=unite(s[i-1][j], s[i-1][m]);
		}
	scanf("%d", &m);
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		pa ans=lca(a, b);
		printf("%d %d\n", ans.x, ans.y);
	}
}
