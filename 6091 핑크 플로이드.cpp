#include<stdio.h>
#include<vector>
#include<algorithm>
#define all(x) x.begin(), x.end()
using namespace std;
struct pink{ 
	int s, e, c; 
	pink(int x, int y, int z){ s=x; e=y; c=z; }
};
vector<pink> g;
vector<int> v[1030];
int p[1030];

bool cmp(pink a, pink b){ return a.c<b.c; }

int find(int t){ return p[t]<0?t:p[t]=find(p[t]); }

void unite(int a, int b){
	a=find(a); b=find(b);
	if(a!=b){
		if(p[a]>p[b]) swap(a, b);
		p[a]+=p[b]; p[b]=a;
	}
}

int main(){
	int n, t, i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++) p[i]=-1;
	for(i=1; i<n; i++)
		for(j=i+1; j<=n; j++){
			scanf("%d", &t);
			g.push_back(pink(i, j, t));
		}
	sort(all(g), cmp);
	for(i=0; i<g.size(); i++){
		if(find(g[i].s)==find(g[i].e)) continue;
		unite(g[i].s, g[i].e);
		v[g[i].s].push_back(g[i].e);
		v[g[i].e].push_back(g[i].s);
	}
	for(i=1; i<=n; i++) sort(all(v[i]));
	for(i=1; i<=n; i++){
		printf("%d ", v[i].size());
		for(auto j:v[i]) printf("%d ", j);
		printf("\n");
	}
}
