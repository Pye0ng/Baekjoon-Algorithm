#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
struct gold{ int x, y; ll w; };
struct con{ ll lmx, mmx, rmx, sum; };
vector<gold> g, v[3030];
vector<int> gx, gy;
vector<con> s;

bool cmp(gold a, gold b){
	if(a.y==b.y) return a.x<b.x;
	return a.y<b.y;
}

con upd(int c, int a, int b, int i, ll t){
	if(i<a||i>b) return s[c];
	if(a==b){
		s[c].lmx=s[c].mmx=s[c].rmx=s[c].sum+=t;
		return s[c];
	}
	int m=a+b>>1;
	con p=upd(c<<1, a, m, i, t), q=upd(c<<1|1, m+1, b, i, t), r;
	r.sum=p.sum+q.sum;
	r.lmx=max(p.lmx, p.sum+q.lmx);
	r.mmx=max(max(p.mmx, q.mmx), max(p.rmx+q.lmx, r.sum));
	r.rmx=max(p.rmx+q.sum, q.rmx);
	return s[c]=r;
}

int main(){
	int n, i, j; ll ans=0;
	scanf("%d", &n); s.resize(n*4);
	for(i=0; i<n; i++){
		gold d;
		scanf("%d %d %lld", &d.x, &d.y, &d.w);
		gx.push_back(d.x);
		gy.push_back(d.y);
		g.push_back(d);
	}
	sort(gx.begin(), gx.end());
	sort(gy.begin(), gy.end());
	gx.erase(unique(gx.begin(), gx.end()), gx.end());
	gy.erase(unique(gy.begin(), gy.end()), gy.end());
	for(i=0; i<n; i++){
		g[i].x=lower_bound(gx.begin(), gx.end(), g[i].x)-gx.begin()+1;
		g[i].y=lower_bound(gy.begin(), gy.end(), g[i].y)-gy.begin()+1;
	}
	sort(g.begin(), g.end(), cmp);
	for(i=0; i<n; i++){
		if(i>0&&g[i].y==g[i-1].y) continue;
		for(j=0; j<s.size(); j++) s[j].lmx=s[j].rmx=s[j].mmx=s[j].sum=0;
		for(j=i; j<n; j++){
			upd(1, 1, gx.size(), g[j].x, g[j].w);
			if(j<n-1&&g[j].y==g[j+1].y) continue;
			ans=max(ans, s[1].mmx);
		}
	}
	printf("%lld", ans);
}
