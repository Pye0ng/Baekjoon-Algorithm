#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long int ll;
int in[520], ch[520];
ll c, d[520], v[520][520], M=1e17;

int main(){
	int t, n, m, w, a, b, s=0, i, j;
	scanf("%d", &t);
	while(t--){
		vector<pair<int, ll> > g[520];
		queue<int> q; s=0;
		scanf("%d %d %d", &n, &m, &w);
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++) v[i][j]=M;
		for(i=0; i<m+w; i++){
			scanf("%d %d %lld", &a, &b, &c);
			if(i<m){
				v[a][b]=min(v[a][b], c);
				v[b][a]=min(v[b][a], c);
			}
			else v[a][b]=min(v[a][b], -c);
		}
		for(i=1; i<=n; i++){
			d[i]=M; in[i]=0; ch[i]=0;
			g[n+1].push_back({i, 0});
			for(j=1; j<=n; j++)
				if(v[i][j]!=M) g[i].push_back({j, v[i][j]});
		}
		d[n+1]=0; q.push(n+1); in[n+1]=ch[n+1]=1;
		while(!q.empty()){
			a=q.front(); q.pop(); in[a]=0;
			for(i=0; i<g[a].size(); i++){
				b=g[a][i].first; c=g[a][i].second;
				if(d[b]>d[a]+c){
					d[b]=d[a]+c;
					if(!in[b]){
						if(++ch[b]>=n) s=1;
						q.push(b); in[b]=1;
					}
				}
				if(s) break;
			}
			if(s) break;
		}
		printf("%s\n", s?"YES":"NO");
	}
}
