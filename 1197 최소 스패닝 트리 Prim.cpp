#include<stdio.h>
#include<vector>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
vector<pii> g[10100];
int s, d[10100], v[10100], INF=1e7; 

int main(){
	int n, m, t, mn, i, j;
	scanf("%d %d", &n, &m);
	while(m--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		g[a].push_back(pii(b, c));
		g[b].push_back(pii(a, c));
	}
	for(i=2; i<=n; i++) d[i]=INF;
	for(i=1; i<=n; i++){
		mn=INF;
		for(j=1; j<=n; j++)
			if(!v[j]&&mn>d[j]){
				mn=d[j];
				t=j;
			}
		s+=mn; v[t]=1;
		for(j=0; j<g[t].size(); j++)
			d[g[t][j].x]=min(d[g[t][j].x], g[t][j].y);
	}
	printf("%d", s);
}
