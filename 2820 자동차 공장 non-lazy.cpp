#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
typedef long long int ll;
vector<ll> s;
vector<int> g[500100];
ll cnt, d[500100];
int p[500100], q[500100], v[500100];

void dfs(int t){
	v[t]=1; p[t]=++cnt;
	for(int i=0; i<g[t].size(); i++)
		if(!v[g[t][i]]) dfs(g[t][i]);
	q[t]=cnt;
}

void upd(int c, int a, int b, int i, ll t){
	if(i<a||i>b) return;
	s[c]+=t;
	if(a==b) return;
	int m=(a+b)>>1;
	upd(c<<1, a, m, i, t);
	upd(c<<1|1, m+1, b, i, t);
}

ll sum(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return sum(c<<1, a, m, l, r)+sum(c<<1|1, m+1, b, l, r);
}

int main(){
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m, t, i;
	ll a, b;
	char c;
	cin>>n>>m>>d[1]; 
	s.resize(n*4);
	for(i=2; i<=n; i++){
		cin>>a >>t;
		d[i]=a; g[t].push_back(i);
	}
	dfs(1);
	t=1<<int(ceil(log2(n)));
	while(m--){
		cin>>c>>a;
		if(c=='p'){
			cin>>b;
			upd(1, 1, t, p[a]+1, b);
			upd(1, 1, t, q[a]+1, -b);
		}
		else cout<<sum(1, 1, t, 1, p[a])+d[a]<<"\n";
	}
}
