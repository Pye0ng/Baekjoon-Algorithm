#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> g[110];
queue<int> q;
int fl, w[210], c[210][210], f[210][210], p[210], mx=2147483646;

int main(){
	int n, m, a, b, s, mn, i, j;
	scanf("%d %d", &n, &m);
	s=n+m+1;
	for(i=1; i<=n; i++){
		scanf("%d", &w[i]);
		g[i].push_back(s);
		g[s].push_back(i);
		c[i][s]=mx;
	}
	for(i=1; i<=m; i++){
		scanf("%d", &w[n+i]);
		g[0].push_back(n+i);
		g[n+i].push_back(0);
		c[0][n+i]=w[n+i];
	}
	for(i=1; i<=m; i++){
		scanf("%d", &a);
		for(j=0; j<a; j++){
			scanf("%d", &b);
			g[n+i].push_back(b);
			g[b].push_back(n+i);
			c[n+i][b]=w[b];
		}
	}
	while(1){
		q.push(0);
		for(i=0; i<=s; i++) p[i]=-1;
		while(!q.empty()){
			a=q.front(); q.pop();
			for(i=0; i<g[a].size(); i++){
				b=g[a][i];
				if(c[a][b]>f[a][b]&&p[b]==-1){ 
					q.push(b); p[b]=a; 
					if(b==s) break;
				}
			}
		}
		if(p[s]==-1) break;
		mn=mx;
		for(i=s; i!=0; i=p[i]) mn=min(mn, c[p[i]][i]-f[p[i]][i]);
		for(i=s; i!=0; i=p[i]){
			f[p[i]][i]+=mn;
			f[i][p[i]]-=mn;
		}
		fl+=mn;
	}
	printf("%d", fl);
}
