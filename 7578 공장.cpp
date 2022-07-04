#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long int ll;
vector<pair<int, int> > v, g;
vector<ll> s;
int n, d[500100];
ll sum;

int find(int t){
	int p=0, q=n-1, m;
	while(p<=q){
		m=(p+q)>>1;
		if(g[m].first<t) p=m+1;
		else if(g[m].first>t) q=m-1;
		else return m;	
	}
}

ll query(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return query(c<<1, a, m, l, r)+query(c<<1|1, m+1, b, l, r);
}

void upd(int c, int a, int b, int t){
	if(a==b){ s[c]=1; return; }
	int m=(a+b)>>1;
	if(t<=m) upd(c<<1, a, m, t);
	else upd(c<<1|1, m+1, b, t);
	s[c]=s[c<<1]+s[c<<1|1];
}

int main(){
	int t, i;
	scanf("%d", &n); s.resize(n*4);
	v.push_back({-1, -1});
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	for(i=1; i<=n; i++){
		scanf("%d", &t);
		g.push_back({t, i});
	}
	sort(g.begin(), g.end());
	for(i=1; i<=n; i++) v.push_back({i, g[find(d[i])].second});
	sort(v.begin(), v.end());
	for(i=1; i<=n; i++){
		sum+=query(1, 1, n, v[i].second+1, n);
		upd(1, 1, n, v[i].second);
	}
	printf("%lld", sum);
}
