#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
struct query{ int idx, s, e; };
typedef pair<int, int> pii;
int k, ord, num, d[1000100], cnt[1000100], ans[1000100];
vector<query> q;
vector<pii> v;

bool cmp(query a, query b){
	if(a.s/k==b.s/k) return a.e<b.e;
	return a.s/k<b.s/k;
}

int main(){
	int n, m, a, b, i; query t;
	scanf("%d", &n); k=sqrt(n);
	for(i=1; i<=n; i++){
		scanf("%d", &d[i]);
		v.push_back(pii(d[i], i));
	}
	sort(v.begin(), v.end());
	d[v[0].second]=++ord;
	for(i=1; i<n; i++){
		if(v[i-1].first!=v[i].first) ord++;
		d[v[i].second]=ord;
	}
	scanf("%d", &m);
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		t.idx=i; t.s=a; t.e=b;
		q.push_back(t);
	}
	sort(q.begin(), q.end(), cmp);
	a=b=0;
	for(i=0; i<m; i++){
		t=q[i];
		while(a<t.s) if(--cnt[d[a++]]==0) num--; 
		while(a>t.s) if(++cnt[d[--a]]==1) num++;
		while(b>t.e) if(--cnt[d[b--]]==0) num--;
		while(b<t.e) if(++cnt[d[++b]]==1) num++;
		ans[t.idx]=num;
	}
	for(i=0; i<m; i++) printf("%d\n", ans[i]);
}
