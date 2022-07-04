#include<stdio.h>
#include<vector>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
int p[200100], g[200100];
vector<pii> v;
vector<int> ans;

int find(int t){ return p[t]<0?t:p[t]=find(p[t]); }

void unite(int x, int y){
	x=find(x); y=find(y);
	if(x!=y){
		if(p[x]>p[y]) swap(x, y);
		p[x]+=p[y]; p[y]=x;
	}
}

int main(){
	int n, m, i;
	scanf("%d %d", &n, &m);
	for(i=2; i<=n; i++) scanf("%d", &g[i]);
	for(i=1; i<=n; i++) p[i]=-1;
	for(i=1; i<n+m; i++){
		int t, a, b;
		scanf("%d %d", &t, &a);
		if(t){
			scanf("%d", &b);
			v.push_back(pii(a, b));
		}
		else v.push_back(pii(-1, a));
	}
	for(i=v.size()-1; i>=0; i--){
		if(v[i].x==-1) unite(v[i].y, g[v[i].y]);
		else ans.push_back(find(v[i].x)==find(v[i].y));
	}
	for(i=m-1; i>=0; i--) printf("%s\n", ans[i]?"YES":"NO");
}
