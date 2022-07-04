#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int> g[210];
int ans, c[210][210], f[210][210], r[210][210], INF=1e9;

int main(){
	int n, s=0, e=201, now, flow, t, i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		c[s][i]=1;
		g[s].push_back(i);
		g[i].push_back(s);
	}
	for(i=101; i<=n+100; i++){
		c[i][e]=1;
		g[i].push_back(e);
		g[e].push_back(i);
	}
	for(i=1; i<=n; i++)
		for(j=101; j<=n+100; j++){
			scanf("%d", &t);
			c[i][j]=1;
			r[i][j]=t;
			r[j][i]=-t;
			g[i].push_back(j);
			g[j].push_back(i);
		}
	while(1){
		vector<int> p(210, -1), d(210, INF), in(210, 0);
		queue<int> q; q.push(s); in[s]=1; d[s]=0;
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
	}
	printf("%d", ans);
}
