#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
vector<int> g[2010];
int ans, c[2010][2010], f[2010][2010], INF=1e9;

int main(){
	int n, m, s=0, e=2001, now, nxt, flow, i, j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		int a, b;
		scanf("%d", &a);
		g[s].push_back(i);
		g[i].push_back(s);
		c[s][i]=1;
		for(j=0; j<a; j++){
			scanf("%d", &b); b+=1000;
			g[i].push_back(b);
			g[b].push_back(i);
			c[i][b]=1;
		}
	}
	for(i=1001; i<=1000+m; i++){
		g[i].push_back(e);
		g[e].push_back(i);
		c[i][e]=1;
	}
	while(1){
		vector<int> p(2010, -1);
		queue<int> q;
		q.push(s);
		while(!q.empty()){
			now=q.front(); q.pop();
			for(auto nxt:g[now])
				if(p[nxt]==-1&&c[now][nxt]>f[now][nxt]){
					q.push(nxt); p[nxt]=now;
					if(nxt==e) break;
				}
		}
		if(p[e]==-1) break;
		flow=INF;
		for(i=e; i!=s; i=p[i]) flow=min(flow, c[p[i]][i]-f[p[i]][i]);
		for(i=e; i!=s; i=p[i]){
			f[p[i]][i]+=flow;
			f[i][p[i]]-=flow;
		}
		ans+=flow;
	}
	printf("%d", ans);
}
