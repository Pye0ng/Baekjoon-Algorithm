#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
struct query{ int idx, s, e; };
typedef pair<int, int> pii;
typedef long long ll;
int k, ord, d[100100]; 
vector<query> q;
vector<pii> v;
vector<ll> s;
ll cnt, ans[100100];

bool cmp(query a, query b){
	if(a.s/k==b.s/k) return a.e<b.e;
	return a.s/k<b.s/k;
}

ll sum(int i){
	ll ret=0;
	while(i>0){
		ret+=s[i];
		i-=(i&-i);
	}
	return ret;
}

void upd(int i, ll t){
	while(i<s.size()){
		s[i]+=t;
		i+=(i&-i);
	}
}

int main(){
	int n, m, a, b, i; query t;
	scanf("%d %d", &n, &m); k=sqrt(n);
	for(i=1; i<=n; i++){
		scanf("%d", &d[i]);
		v.push_back(pii(d[i], i));
	}
	sort(v.begin(), v.end());
	d[v[0].second]=++ord;
	for(i=1; i<n; i++){
		if(v[i].first!=v[i-1].first) ord++;
		d[v[i].second]=ord;
	}
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		t.idx=i; t.s=a; t.e=b;
		q.push_back(t);
	}
	sort(q.begin(), q.end(), cmp);
	a=q[0].s; b=q[0].e;
	s.resize(ord+1, 0);
	for(i=a; i<=b; i++){
		cnt+=sum(ord)-sum(d[i]);
		upd(d[i], 1);
	}
	ans[q[0].idx]=cnt;
	for(i=1; i<m; i++){
		t=q[i];
		while(a<t.s){
			cnt-=sum(d[a]-1);
			upd(d[a], (ll)-1); a++;
		}
		while(a>t.s){
			a--; cnt+=sum(d[a]-1);
			upd(d[a], (ll)1);
		}
		while(b>t.e){
			cnt-=sum(ord)-sum(d[b]);
			upd(d[b], (ll)-1); b--;
		}
		while(b<t.e){
			b++; cnt+=sum(ord)-sum(d[b]);
			upd(d[b], (ll)1);
		}
		ans[t.idx]=cnt;
	}
	for(i=0; i<m; i++) printf("%lld\n", ans[i]);
}
