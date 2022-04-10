#include<stdio.h>
#include<vector>
#include<algorithm>
#define x first
#define y second
using namespace std;
struct str{ int c, s, e; };
typedef pair<int, int> pii;
vector<str> v;
vector<int> g[100100];
int p[100100], l[100100], r[100100];
pii ans[100100];

bool cmp(str a, str b){
	if(a.c<b.c) return 1;
	return a.c==b.c?a.s<b.s:0;
}

int find(int t){ return p[t]<0?t:p[t]=find(p[t]); }

void unite(int a, int b){
	a=find(a); b=find(b);
	if(a!=b){
		if(p[a]>p[b]) swap(a, b);
		p[a]+=p[b]; p[b]=a;
	}
}

int main(){
	int n, m, q, w, i, j;
	scanf("%d %d", &n, &m);
	for(i=0; i<m; i++){
		str t;
		scanf("%d %d %d", &t.s, &t.e, &t.c);
		v.push_back(t);
	}
	sort(v.begin(), v.end(), cmp);
	scanf("%d", &q);
	vector<pii> qr(q);
	for(i=0; i<q; i++){
		scanf("%d %d", &qr[i].x, &qr[i].y);
		l[i]=1; r[i]=m;
	}
	while(1){
		for(i=1; i<=m; i++) g[i].clear();
		for(i=0; i<100010; i++) p[i]=-1;
		bool ch=0;
		for(i=0; i<q; i++)
			if(l[i]<=r[i]){
				ch=1;
				g[(l[i]+r[i])/2].push_back(i);
			}
		if(!ch) break;
		for(i=0; i<m; i++){
			unite(v[i].s, v[i].e);
			for(j=0; j<g[i+1].size(); j++){
				w=g[i+1][j];
				if(find(qr[w].x)==find(qr[w].y)){
					r[w]=i;
					ans[w]=make_pair(v[i].c, -p[find(qr[w].x)]);
				}
				else l[w]=i+2;
			}
		}
	}
	for(i=0; i<q; i++){
		if(l[i]>m) printf("-1\n");
		else printf("%d %d\n", ans[i].x, ans[i].y);
	}
}
