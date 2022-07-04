#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#define fi first
#define se second
#define pb push_back
using namespace std;
struct chain{ int x, y, z, in; };
typedef long long int ll;
typedef pair<ll, int> pli;
priority_queue<pli> q;
vector<pli> v[100100], w1, w2, w3;
vector<chain> g;
vector<int> s;

ll d1[100100], d2[100100], d3[100100], INF=1e18;
chain store[100100];
bool ans[100100];

bool cmp(chain A, chain B){ 
	if(A.x<B.x) return 1;
	else if(A.x==B.x){
		if(A.y>B.y) return 1;
		else if(A.y==B.y) return A.z<B.z;
		else return 0;
	}
	else return 0;
}

int find_min(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 1e9;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return min(find_min(c<<1, a, m, l, r), find_min(c<<1|1, m+1, b, l, r));
}

void update(int c, int a, int b, int i, int t){
	if(i<a||i>b) return;
	s[c]=min(s[c], t);
	if(a!=b){
		int m=(a+b)>>1;
		update(c<<1, a, m, i, t);
		update(c<<1|1, m+1, b, i, t);
	}
}

int main(){
	int n, m, a, b, c, i;
	scanf("%d %d %d %d %d", &n, &a, &b, &c, &m);
	s.resize(n*4, 1e9);
	for(i=0; i<m; i++){
		int S, E; ll C;
		scanf("%d %d %lld", &S, &E, &C);
		v[S].pb(pli(C, E));
		v[E].pb(pli(C, S));
	}
	for(i=1; i<=n; i++) d1[i]=d2[i]=d3[i]=INF;
	
	q.push(pli(0, a)); d1[a]=0;
	while(!q.empty()){
		int tax=-q.top().fi, now=q.top().se; q.pop();
		if(d1[now]<tax) continue;
		for(i=0; i<v[now].size(); i++){
			ll cost=tax+v[now][i].fi;
			if(cost<d1[v[now][i].se]){
				d1[v[now][i].se]=cost;
				q.push(pli(-cost, v[now][i].se));
			}
		}
	}
	for(i=1; i<=n; i++) w1.pb(pli(d1[i], i));
	
	q.push(pli(0, b)); d2[b]=0;
	while(!q.empty()){
		int tax=-q.top().fi, now=q.top().se; q.pop();
		if(d2[now]<tax) continue;
		for(i=0; i<v[now].size(); i++){
			ll cost=tax+v[now][i].fi;
			if(cost<d2[v[now][i].se]){
				d2[v[now][i].se]=cost;
				q.push(pli(-cost, v[now][i].se));
			}
		}
	}
	for(i=1; i<=n; i++) w2.pb(pli(d2[i], i));
	
	q.push(pli(0, c)); d3[c]=0;
	while(!q.empty()){
		int tax=-q.top().fi, now=q.top().se; q.pop();
		if(d3[now]<tax) continue;
		for(i=0; i<v[now].size(); i++){
			ll cost=tax+v[now][i].fi;
			if(cost<d3[v[now][i].se]){
				d3[v[now][i].se]=cost;
				q.push(pli(-cost, v[now][i].se));
			}
		}
	}
	for(i=1; i<=n; i++) w3.pb(pli(d3[i], i));
	
	sort(w1.begin(), w1.end());
	sort(w2.begin(), w2.end());
	sort(w3.begin(), w3.end());
	
	a=b=c=1;
	for(i=0; i<n; i++){
		if(i>0&&w1[i].fi==w1[i-1].fi) store[w1[i].se].x=store[w1[i-1].se].x;
		else store[w1[i].se].x=a++;
	}
	for(i=0; i<n; i++){
		if(i>0&&w2[i].fi==w2[i-1].fi) store[w2[i].se].y=store[w2[i-1].se].y;
		else store[w2[i].se].y=b++;
	}
	for(i=0; i<n; i++){
		if(i>0&&w3[i].fi==w3[i-1].fi) store[w3[i].se].z=store[w3[i-1].se].z;
		else store[w3[i].se].z=c++;
	}
	for(i=1; i<=n; i++){
		store[i].in=i;
		g.pb(store[i]);
	}
	sort(g.begin(), g.end(), cmp);	
	for(i=0; i<n; i++){
		ans[g[i].in]=find_min(1, 1, n, 1, g[i].y-1)>=g[i].z;
		update(1, 1, n, g[i].y, min(g[i].z, find_min(1, 1, n, g[i].y, g[i].y)));
	}
	
	scanf("%d", &m);
	while(m--){
		int t;
		scanf("%d", &t);
		printf("%s\n", ans[t]?"YES":"NO");
	}
}
