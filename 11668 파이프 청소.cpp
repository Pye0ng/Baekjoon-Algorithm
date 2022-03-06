#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> p;
typedef pair<p, p> pp;
vector<int> q[2010], r[2010], k;
int v[2010];
p w[1010];
pp t[1010];

int ccw(p a, p b, p c){
	ll g=a.x*b.y+b.x*c.y+c.x*a.y-a.y*b.x-b.y*c.x-c.y*a.x;
	if(g>0) return 1;
	else if(g<0) return -1;
	else return 0;
}

int crs(pp n, pp m){
	p a=n.x, b=n.y, c=m.x, d=m.y;
	int ab=ccw(a, b, c)*ccw(a, b, d), cd=ccw(c, d, a)*ccw(c, d, b);	
	if(ab==0&&cd==0){
		if(a>b) swap(a, b);
		if(c>d) swap(c, d);
		return c<=b&&a<=d;
	}
	return ab<=0&&cd<=0;
}

void dfs(int n){
	v[n]=1;
	for(int i=0; i<q[n].size(); i++)
		if(!v[q[n][i]]) dfs(q[n][i]);
	k.push_back(n);
}

void rdfs(int n, int c){
	v[n]=c;
	for(int i=0; i<r[n].size(); i++)
		if(!v[r[n][i]]) rdfs(r[n][i], c);
}

int main(){
	int n, m, c=1, i, j; p a;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++) scanf("%lld %lld", &w[i].x, &w[i].y);
	for(i=1; i<=m; i++){
		scanf("%d %lld %lld", &n, &a.x, &a.y);
		t[i]={w[n], a};
		for(j=1; j<i; j++){
			if(!crs(t[i], t[j])||t[i].x==t[j].x) continue;
			q[i<<1|1].push_back(j<<1);
			q[j<<1|1].push_back(i<<1);
			q[i<<1].push_back(j<<1|1);
			q[j<<1].push_back(i<<1|1);
			r[i<<1|1].push_back(j<<1);
			r[j<<1|1].push_back(i<<1);
			r[i<<1].push_back(j<<1|1);
			r[j<<1].push_back(i<<1|1);
		}
	}
	for(i=2; i<=m*2+1; i++)
		if(!v[i]) dfs(i);
	for(i=2; i<=m*2+1; i++) v[i]=0;
	for(i=k.size()-1; i>=0; i--)
		if(!v[k[i]]) rdfs(k[i], c++);
	c=0;
	for(i=1; i<=m; i++)
		c|=(v[i<<1]==v[i<<1|1]&&v[i<<1]!=0);
	printf("%s", c?"impossible":"possible");
}
