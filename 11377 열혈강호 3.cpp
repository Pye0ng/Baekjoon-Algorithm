#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#define pb push_back
using namespace std;
vector<int> g[2100];
int ans, c[2100][2100], f[2100][2100];

int main(){
	int n, m, s=0, e=2001, k=2002, now, flow, i;
	scanf("%d %d %d", &n, &m, &c[s][k]);
	g[s].pb(k);
	g[k].pb(s);
	for(i=1; i<=n; i++){
		int t, w;
		g[s].pb(i); g[i].pb(s); c[s][i]=1;
		g[k].pb(i); g[i].pb(k); c[k][i]=1;
		scanf("%d", &t);
		while(t--){
			scanf("%d", &w); w+=1000;
			g[i].pb(w); g[w].pb(i); c[i][w]=1;
		}
	}
	for(i=1001; i<=m+1000; i++){
		g[i].pb(e);
		g[e].pb(i);
		c[i][e]=1;
	}
	while(1){
		vector<int> p(2100, -1); flow=1e9;
		queue<int> q; q.push(s);
		while(!q.empty()){
			now=q.front(); q.pop();
			for(auto nxt:g[now])
				if(p[nxt]==-1&&c[now][nxt]>f[now][nxt]){
					q.push(nxt); p[nxt]=now;
					if(nxt==e) break;
				}
		}
		if(p[e]==-1) break;
		for(i=e; i!=s; i=p[i]) flow=min(flow, c[p[i]][i]-f[p[i]][i]);
		for(i=e; i!=s; i=p[i]){
			f[p[i]][i]+=flow;
			f[i][p[i]]-=flow;
		}
		ans+=flow;
	}
	printf("%d", ans);
}
