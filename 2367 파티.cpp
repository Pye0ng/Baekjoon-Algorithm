#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int> g[310];
queue<int> q;
int fl, mn, c[310][310], f[310][310], p[310];

int main(){
	int n, k, m, s, a, b, i, j;
	scanf("%d %d %d", &n, &k, &m);
	s=n+m+1;
	for(i=1; i<=m; i++){
		scanf("%d", &a);
		g[n+i].push_back(s);
		g[s].push_back(n+i);
		c[n+i][s]=a;
	}
	for(i=1; i<=n; i++){
		scanf("%d", &a);
		c[0][i]=k;
		g[0].push_back(i);
		g[i].push_back(0);
		for(j=0; j<a; j++){
			scanf("%d", &b);
			g[i].push_back(n+b);
			g[n+b].push_back(i);
			c[i][n+b]=1;
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
					p[b]=a; q.push(b);
					if(b==s) break;
				}
			}
		}
		if(p[s]==-1) break;
		mn=1e9;
		for(i=s; i!=0; i=p[i]) mn=min(mn, c[p[i]][i]-f[p[i]][i]);
		for(i=s; i!=0; i=p[i]){
			f[p[i]][i]+=mn;
			f[i][p[i]]-=mn;
		}
		fl+=mn;
	}
	printf("%d", fl);
}
