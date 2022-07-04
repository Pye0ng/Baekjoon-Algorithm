#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
struct query{ int idx, s, e; };
typedef long long ll;
int k, d[100100], cnt[100100];
ll pairs, ans[100100];
vector<query> q;
vector<ll> s;

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
	int n, m, a, b, p, sz=100000, i; query t;
	scanf("%d %d", &n, &p); k=sqrt(n);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	scanf("%d", &m);
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		t.idx=i; t.s=a; t.e=b;
		q.push_back(t);
	}
	sort(q.begin(), q.end(), cmp);
	a=q[0].s; b=q[0].e; s.resize(sz+1, 0);
	for(i=a; i<=b; i++){
		pairs+=sum(min(sz, d[i]+p))-sum(max(0, d[i]-p-1));
		upd(d[i], 1);
	}
	ans[q[0].idx]=pairs;
	for(i=1; i<m; i++){
		t=q[i];
		while(a<t.s){
			pairs-=sum(min(sz, d[a]+p))-sum(max(0, d[a]-p-1))-1;
			upd(d[a], -1); a++;
		}
		while(a>t.s){
			a--; pairs+=sum(min(sz, d[a]+p))-sum(max(0, d[a]-p-1));
			upd(d[a], 1);
		}
		while(b>t.e){
			pairs-=sum(min(sz, d[b]+p))-sum(max(0, d[b]-p-1))-1;
			upd(d[b], -1); b--;
		}
		while(b<t.e){
			b++; pairs+=sum(min(sz, d[b]+p))-sum(max(0, d[b]-p-1));
			upd(d[b], 1);
		}
		ans[t.idx]=pairs;
	}
	for(i=0; i<m; i++) printf("%lld\n", ans[i]);
}
