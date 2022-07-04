#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int> g[220];
int ans, c[220][210], f[220][220], INF=1e9;

int main(){
	int n, m, s=0, e=201, now, flow, i, j;
	scanf("%d %d", &n, &m);
	for(i=101; i<=n+100; i++){
		scanf("%d", &c[i][e]);
		g[i].push_back(e);
		g[e].push_back(i);
	}
	for(i=1; i<=m; i++){
		scanf("%d", &c[s][i]);
		g[s].push_back(i);
		g[i].push_back(s);
	}
	for(i=1; i<=m; i++)
		for(j=101; j<=n+100; j++){
			scanf("%d", &c[i][j]);
			g[i].push_back(j);
			g[j].push_back(i);
		}
	while(1){
		vector<int> p(220, -1); flow=INF;
		queue<int> q; q.push(s);
		while(!q.empty()){
			now=q.front(); q.pop();
			for(auto nxt:g[now])
				if(p[nxt]==-1&&c[now][nxt]>f[now][nxt]){
					p[nxt]=now; q.push(nxt);
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
