#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> g[10100];
int ans, cnt, d[10100], c[10100];

int dfs(int n, int Root){
	d[n]=++cnt;
	int ch=0, r=d[n], t, p, i;
	for(i=0; i<g[n].size(); i++){
		t=g[n][i];
		if(d[t]){
			r=min(r, d[t]);
			continue;
		}
		ch++; p=dfs(t, 0);
		if(!Root&&p>=d[n]) c[n]=1;
		r=min(r, p);
	}
	if(Root) c[n]=ch>1;
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
	for(i=1; i<=n; i++) if(!d[i]) dfs(i, 1);
	for(i=1; i<=n; i++) ans+=c[i];
	printf("%d\n", ans);
	for(i=1; i<=n; i++) if(c[i]) printf("%d ", i);
}
