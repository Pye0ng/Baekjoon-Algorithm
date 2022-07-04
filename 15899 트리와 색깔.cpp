#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> g[200200], mst[800800];
int k, cnt, p[200200], q[200200], in[200200], d[200200];

void dfs(int t){
	p[t]=++cnt;
	for(auto i:g[t]) if(!p[i]) dfs(i);
	q[t]=cnt;
}

void set(int c, int a, int b){
	vector<int> &v=mst[c];
	if(a==b){
		v.push_back(d[a]);
		return;
	}
	int m=a+b>>1;
	set(c<<1, a, m);
	set(c<<1|1, m+1, b);
	vector<int> &l=mst[c<<1], &r=mst[c<<1|1];
	v.resize(l.size()+r.size());
	merge(l.begin(), l.end(), r.begin(), r.end(), v.begin());
}

int query(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return upper_bound(mst[c].begin(), mst[c].end(), k)-mst[c].begin();
	int m=a+b>>1;
	return query(c<<1, a, m, l, r)+query(c<<1|1, m+1, b, l, r);
}

int main(){
	int n, m, t, s, i;
	scanf("%d %d %d", &n, &m, &k);
	for(i=1; i<=n; i++) scanf("%d", &in[i]);
	for(i=1; i<n; i++){
		scanf("%d %d", &t, &s);
		g[s].push_back(t);
		g[t].push_back(s);
	}
	dfs(1); cnt=0;
	for(i=1; i<=n; i++) d[p[i]]=in[i];
	set(1, 1, n);
	while(m--){
		scanf("%d %d", &t, &k);
		cnt=(cnt+query(1, 1, n, p[t], q[t]))%1000000007;
	}
	printf("%d", cnt);
}
