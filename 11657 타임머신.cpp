#include<stdio.h>
#include<vector>
using namespace std;
typedef long long int ll;
struct nd{ int f, t; ll s; };
vector<nd> v;
ll d[510], INF=1e17;

int main(){
	int n, m, a, b, ch=0, i, j; ll c;
	scanf("%d %d", &n, &m);
	for(i=0; i<m; i++){
		nd p;
		scanf("%d %d %lld", &p.f, &p.t, &p.s);
		v.push_back(p);
	}
	d[1]=0;
	for(i=2; i<=n; i++) d[i]=INF;
	for(i=1; i<n; i++)
		for(j=0; j<m; j++){
			a=v[j].f; b=v[j].t; c=v[j].s;
			if(d[a]!=INF&&d[b]>d[a]+c) d[b]=d[a]+c;
		}
	for(i=0; i<m; i++){
		a=v[i].f; b=v[i].t; c=v[i].s;
		if(d[a]!=INF&&d[b]>d[a]+c){
			printf("-1");
			return 0;
		}
	} 
	for(i=2; i<=n; i++) printf("%lld\n", d[i]==INF?-1:d[i]);
}
