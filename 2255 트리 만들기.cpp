#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#define x first
#define y second
#define pb push_back
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppii;
priority_queue<ppii, vector<ppii>, greater<ppii> > s;
vector<pii> g;
int ans, d[1010], p[1010];

int find(int t){ return p[t]<0?t:p[t]=find(p[t]); }

void unite(int a, int b){
	a=find(a); b=find(b);
	if(a!=b){
		if(p[a]>p[b]) swap(a, b);
		p[a]+=p[b]; p[b]=a;
	}
}

int main(){
	int n, m, r, a, b, c, i, j;
	scanf("%d %d %d", &n, &m, &r);
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		g.pb(pii(a, b));
		d[a]++; d[b]++;
	}
	for(i=0; i<m; i++){
		a=g[i].x; b=g[i].y;
		if(a!=r) s.push(ppii(pii(d[b], d[a]), pii(b, a)));
		if(b!=r) s.push(ppii(pii(d[a], d[b]), pii(a, b)));
	}
	for(i=1; i<=n; i++) p[i]=-1;
	while(!s.empty()){
		a=s.top().y.x; b=s.top().y.y;
		if(find(a)!=find(b)){
			unite(a, b);
			ans+=s.top().x.x;
		}
		s.pop();
	}
	printf("%d", ans);
}
