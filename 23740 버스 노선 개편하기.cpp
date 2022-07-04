#include<stdio.h>
#include<vector>
#include<algorithm>
#define x first
#define y second
using namespace std;
struct bus{ int a, b, c; };
vector<bus> v, g;

bool cmp(bus x, bus y){ return x.a<y.a; }

int main(){
	int n, s, e, m, i;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d %d %d", &s, &e, &m);
		bus t; t.a=s; t.b=e; t.c=m;
		v.push_back(t);
	}
	sort(v.begin(), v.end(), cmp);
	s=v[0].a; e=v[0].b; m=v[0].c;
	for(i=1; i<n; i++){
		bus t=v[i];
		if(t.a>e){
			bus p; p.a=s; p.b=e; p.c=m;
			g.push_back(p);
			s=t.a; e=t.b; m=t.c;
		}
		else{
			m=min(m, t.c);
			if(t.b>e) e=t.b;
		}
	}
	bus p; p.a=s; p.b=e; p.c=m;
	g.push_back(p);
	printf("%d\n", g.size());
	for(i=0; i<g.size(); i++) printf("%d %d %d\n", g[i].a, g[i].b, g[i].c);
}
