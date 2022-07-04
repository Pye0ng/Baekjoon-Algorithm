#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
struct query{ int idx, s, e; };
typedef pair<int, int> pii;
int k, ord, d[500500], cnt[500500], p[500500], ans[500500];
vector<query> q;
vector<pii> v;

bool cmp(query a, query b){
	if(a.s/k==b.s/k) return a.e<b.e;
	return a.s/k<b.s/k;
}

void Inc(int t){ 
	cnt[t]++;
	if(cnt[t]==2) ord++; 
	if(cnt[t]==3) ord--;
}

void Dec(int t){ 
	cnt[t]--;
	if(cnt[t]==1) ord--; 
	if(cnt[t]==2) ord++;
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
		if(d[v[i].second]!=d[v[i-1].second]) ord++;
		d[v[i].second]=ord;
	}
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		t.idx=i; t.s=a; t.e=b;
		q.push_back(t);
	}
	sort(q.begin(), q.end(), cmp);
	a=q[0].s; b=q[0].e; ord=0;
	for(i=a; i<=b; i++) Inc(d[i]);
	ans[q[0].idx]=ord;
	for(i=1; i<m; i++){
		t=q[i];
		while(a<t.s) Dec(d[a++]);
		while(a>t.s) Inc(d[--a]);
		while(b>t.e) Dec(d[b--]);
		while(b<t.e) Inc(d[++b]);
		ans[t.idx]=ord;
	}
	for(i=0; i<m; i++) printf("%d\n", ans[i]);
}
