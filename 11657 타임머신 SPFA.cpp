#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
typedef long long int ll;
vector<pair<int, ll> > g[520];
queue<int> q;
int in[520], ch[520];
ll c, d[520], INF=1e17;

int main(){
	int n, m, a, b, i, j;
	scanf("%d %d", &n, &m);
	for(i=0; i<m; i++){
		scanf("%d %d %lld", &a, &b, &c);
		g[a].push_back({b, c});
	}
	for(i=1; i<=n; i++) d[i]=INF;
	d[1]=0; q.push(1); in[1]=1; ch[1]++;
	while(!q.empty()){
		a=q.front(); q.pop(); in[a]=0;
		for(i=0; i<g[a].size(); i++){
			b=g[a][i].first; c=g[a][i].second;
			if(d[b]>d[a]+c){
				d[b]=d[a]+c;
				if(!in[b]){
					ch[b]++;
					if(ch[b]>=n){
						printf("-1");
						return 0;
					}
					q.push(b);
					in[b]=1;
				}
			}
		}
	}
	for(i=2; i<=n; i++) printf("%d\n", d[i]==INF?-1:d[i]);
}
