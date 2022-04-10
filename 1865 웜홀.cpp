#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long int ll;
struct st{ int f, t; ll d; };
ll c, INF=1e17, d[520], v[520][520];

int main(){
	int t, n, m, w, a, b, ch=0, i, j, k;
	scanf("%d", &t);
	while(t--){
		st p; ch=0;
		vector<st> g;
		scanf("%d %d %d", &n, &m, &w);
		for(i=1; i<=n; i++){
			d[i]=INF;
			p.f=n+1; p.t=i; p.d=0;
			g.push_back(p); 
			for(j=1; j<=n; j++) v[i][j]=INF;
		}
		d[n+1]=0;
		for(i=0; i<m; i++){
			scanf("%d %d %lld", &a, &b, &c);
			v[a][b]=min(v[a][b], c);
			v[b][a]=min(v[b][a], c);
		}
		for(i=0; i<w; i++){
			scanf("%d %d %lld", &a, &b, &c);
			v[a][b]=min(v[a][b], -c);
		}
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				if(v[i][j]!=INF){
					p.f=i; p.t=j; p.d=v[i][j];
					g.push_back(p);
				}
		for(i=1; i<=n; i++)
			for(j=0; j<g.size(); j++){
				a=g[j].f; b=g[j].t; c=g[j].d;
				if(d[a]!=INF&&d[b]>d[a]+c) d[b]=d[a]+c;
			}
		for(i=0; i<g.size(); i++){
			a=g[i].f; b=g[i].t; c=g[i].d;
			if(d[b]>d[a]+c) ch=1;
		}
		printf("%s\n", ch?"YES":"NO");
	}
}
