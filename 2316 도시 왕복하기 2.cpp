#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue> 
using namespace std;
vector<int> g[810];
int ans, c[810][810], f[410][810], INF=1e9;

int main(){
	int n, m, s=402, e=2, now, flow, i;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		g[i].push_back(i+401);
		g[i+401].push_back(i);
		c[i][i+401]=1;
	}
	while(m--){
		int a, b;
		scanf("%d %d", &a, &b);
		g[a+401].push_back(b);
		g[b].push_back(a+401);
		c[a+401][b]=1;
		g[b+401].push_back(a);
		g[a].push_back(b+401);
		c[b+401][a]=1;
	}
	while(1){
		vector<int> p(810, -1);
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
		flow=INF;
		for(i=e; i!=s; i=p[i]) flow=min(c[p[i]][i]-f[p[i]][i], flow);
		for(i=e; i!=s; i=p[i]){
			f[p[i]][i]+=flow;
			f[i][p[i]]-=flow;
		}
		ans+=flow;
	}
	printf("%d", ans);
}
