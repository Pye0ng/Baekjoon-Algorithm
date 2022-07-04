#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int> g[820];
int ans, cnt, c[810][810], f[810][810], r[810][810], INF=1e9;

int main(){
	int n, m, s=0, e=801, now, flow, i;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		c[s][i]=1;
		g[s].push_back(i);
		g[i].push_back(s);
	}
	for(i=401; i<=m+400; i++){
		c[i][e]=1;
		g[i].push_back(e);
		g[e].push_back(i);
	}
	for(i=1; i<=n; i++){
		int t, w, p;
		scanf("%d", &t);
		while(t--){
			scanf("%d %d", &w, &p); w+=400;
			g[i].push_back(w);
			g[w].push_back(i);
			p=10000-p;
			r[i][w]=p;
			r[w][i]=-p;
			c[i][w]=1;
		}
	}
	while(1){
		vector<int> p(810, -1), d(810, INF), in(810, 0);
		queue<int> q; d[s]=0; in[s]=1; q.push(s);
		while(!q.empty()){
			now=q.front(); q.pop(); in[now]=0;
			for(auto nxt:g[now])
				if(c[now][nxt]>f[now][nxt]&&d[nxt]>d[now]+r[now][nxt]){
					d[nxt]=d[now]+r[now][nxt]; p[nxt]=now;
					if(!in[nxt]){ q.push(nxt); in[nxt]=1; }
				}
		}
		if(p[e]==-1) break;
		flow=INF;
		for(i=e; i!=s; i=p[i]) flow=min(flow, c[p[i]][i]-f[p[i]][i]);
		for(i=e; i!=s; i=p[i]){
			ans+=flow*r[p[i]][i];
			f[p[i]][i]+=flow;
			f[i][p[i]]-=flow;
		}
		cnt++;
	}
	printf("%d\n%d", cnt, cnt*10000-ans);
}
