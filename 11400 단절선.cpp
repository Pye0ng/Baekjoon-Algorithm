#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
vector<int> g[100100];
vector<pii> v;
int cnt, d[100100];

int dfs(int n, int pa){
	d[n]=++cnt;
	int r=d[n], t, p, i;
	for(i=0; i<g[n].size(); i++){
		t=g[n][i];
		if(t==pa) continue;
		if(d[t]){ r=min(r, d[t]); continue; }
		p=dfs(t, n);
		if(p>d[n]) v.push_back(pii(min(n, t), max(n, t)));
		r=min(r, p);
	}
	return r;
}

int main(){
	int n, m, i;
	scanf("%d %d", &n, &m);
	while(m--){
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(i=1; i<=n; i++)
		if(!d[i]) dfs(i, 0);
	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for(i=0; i<v.size(); i++) printf("%d %d\n", v[i].first, v[i].second);
}
