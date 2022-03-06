#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
typedef long long int ll;
vector<ll> s, lz;
vector<int> g[500100];
ll cnt, d[600100], w[600100];
int p[500100], q[500100], v[500100];

void dfs(int t){
	v[t]=1; p[t]=++cnt;
	for(int i=0; i<g[t].size(); i++)
		if(!v[g[t][i]]) dfs(g[t][i]);
	q[t]=cnt;
}

ll seg(int c, int a, int b){
	if(a==b) return s[c]=w[a];
	int m=(a+b)>>1;
	return s[c]=seg(c<<1, a, m)+seg(c<<1|1, m+1, b);
}

void prop(int c, int a, int b){
	if(lz[c]==0) return;
	s[c]+=(b-a+1)*lz[c];
	if(a!=b){ lz[c<<1]+=lz[c]; lz[c<<1|1]+=lz[c]; }
	lz[c]=0;
}

void upd(int c, int a, int b, int l, int r, ll t){
	prop(c, a, b);
	if(a>r||b<l) return;
	if(l<=a&&b<=r){
		lz[c]+=t;
		prop(c, a, b);
		return;
	}
	int m=(a+b)>>1;
	upd(c<<1, a, m, l, r, t);
	upd(c<<1|1, m+1, b, l, r, t);
	s[c]=s[c<<1]+s[c<<1|1];
}

ll find(int c, int a, int b, int l, int r){
	prop(c, a, b);
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return find(c<<1, a, m, l, r)+find(c<<1|1, m+1, b, l, r);
}

int main(){
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m, t, i;
	ll a, b; 
	char c;
	cin>>n>>m>>d[1]; w[1]=d[1]; 
	s.resize(n*4); lz.resize(n*4);
	for(i=2; i<=n; i++){
		cin>>a>>t;
		d[i]=a; g[t].push_back(i);
	}
	dfs(1);
	t=1<<int(ceil(log2(n)));
	for(i=2; i<=n; i++) w[p[i]]=d[i];
	seg(1, 1, t);
	while(m--){
		cin>>c>>a;
		if(c=='p'){
			cin>>b;
			if(q[a]>p[a]) upd(1, 1, t, p[a]+1, q[a], b);
		}
		else cout<<find(1, 1, t, p[a], p[a])<<"\n";
	}
}
