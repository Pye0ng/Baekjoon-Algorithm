#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int> g[310];
queue<int> q;
int mf, c[310][310], f[310][310], p[310], mn, mx=2147483646;

int main(){
	int n, m, a, b, t, i;
	scanf("%d %d", &n, &m);
	for(i=0; i<m; i++){
		scanf("%d %d %d", &a, &b, &t);
		g[a].push_back(b);
		g[b].push_back(a);
		c[a][b]+=t;
		c[b][a]+=t;
	}
	while(1){
		q.push(1);
		for(i=1; i<=n; i++) p[i]=-1;
		while(!q.empty()){
			a=q.front(); q.pop();
			for(i=0; i<g[a].size(); i++){
				b=g[a][i];
				if(c[a][b]>f[a][b]&&p[b]==-1){ 
					q.push(b); p[b]=a; 
					if(b==n) break;
				}
			}
		}
		if(p[n]==-1) break;
		mn=mx;
		for(i=n; i!=1; i=p[i]) mn=min(mn, c[p[i]][i]-f[p[i]][i]);
		for(i=n; i!=1; i=p[i]){
			f[p[i]][i]+=mn;
			f[i][p[i]]-=mn;
		}
		mf+=mn;
	}
	printf("%d", mf);
}
