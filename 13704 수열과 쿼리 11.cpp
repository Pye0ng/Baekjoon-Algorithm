#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
struct query{ int idx, s, e; };
typedef long long ll;
ll now, cnt[1200000], ans[100100];
int k, s, a, b, d[100100], p[100100];
vector<query> q;

bool cmp(query x, query y){
	if(x.s/s==y.s/s) return x.e<y.e;
	return x.s/s<y.s/s;
}

void lminus(int t){
	now-=cnt[k^p[t-1]];
	cnt[p[t]]--;
}

void lplus(int t){
	cnt[p[t]]++;
	now+=cnt[k^p[t-1]];
}

void rminus(int t){
	now-=cnt[k^p[t]];
	now-=p[a-1]==(k^p[t]);
	cnt[p[t]]--;
}

void rplus(int t){
	now+=cnt[k^p[t]];
	now+=p[a-1]==(k^p[t]);
	cnt[p[t]]++;
}

int main(){
	int n, m, i; query t;
	scanf("%d %lld", &n, &k); s=sqrt(n);
	for(i=1; i<=n; i++){
		scanf("%d", &d[i]);
		p[i]=d[i]^p[i-1];
	}
	scanf("%d", &m);
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		t.idx=i; t.s=a; t.e=b;
		q.push_back(t);
	}
	sort(q.begin(), q.end(), cmp);
	a=b=q[0].s; cnt[p[a]]=1;
	if(d[a]==k) now++;
	while(b<q[0].e) rplus(++b);
	ans[q[0].idx]=now;
	for(i=1; i<m; i++){
		t=q[i];
		while(a<t.s) lminus(a++);
		while(a>t.s) lplus(--a);
		while(b>t.e) rminus(b--);
		while(b<t.e) rplus(++b);
		ans[t.idx]=now;
	}
	for(i=0; i<m; i++) printf("%lld\n", ans[i]);
}
