#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;
struct query{ int s, e, idx, k; };
vector<query> q;
vector<pil> u;
vector<ll> s;
ll d[100100], ans[100100];
int ord;

bool cmp(query a, query b){
	if(a.k==b.k) return a.idx<b.idx;
	return a.k<b.k;
}

ll seg(int c, int a, int b){
	if(a==b) return s[c]=d[a];
	int m=a+b>>1;
	return s[c]=seg(c<<1, a, m)+seg(c<<1|1, m+1, b);
}

ll sum(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=a+b>>1;
	return sum(c<<1, a, m, l, r)+sum(c<<1|1, m+1, b, l, r);
}

void upd(int c, int a, int b, int i, ll t){
	if(i<a||i>b) return;
	s[c]+=t;
	if(a!=b){
		int m=a+b>>1;
		upd(c<<1, a, m, i, t);
		upd(c<<1|1, m+1, b, i, t);
	}
}

int main(){
	int n, m, a, i; 
	query t; pil p;
	u.push_back(pil(0, 0));
	scanf("%d", &n); s.resize(n*4);
	for(i=1; i<=n; i++) scanf("%lld", &d[i]);
	seg(1, 1, n);
	scanf("%d", &m);
	for(i=0; i<m; i++){
		scanf("%d", &a);
		if(a&1){
			scanf("%d %lld", &p.x, &p.y);
			u.push_back(p);
		}
		else{
			scanf("%d %d %d", &t.k, &t.s, &t.e);
			t.idx=ord++; q.push_back(t);
		}
	}
	sort(q.begin(), q.end(), cmp);
	a=0;
	for(auto t:q){
		while(a<t.k){
			p=u[++a]; 
			upd(1, 1, n, p.x, p.y-d[p.x]);
			d[p.x]=p.y;
		}
		ans[t.idx]=sum(1, 1, n, t.s, t.e);
	}
	for(i=0; i<ord; i++) printf("%lld\n", ans[i]);
}
