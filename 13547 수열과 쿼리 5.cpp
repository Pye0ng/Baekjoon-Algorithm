#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
struct query{ int idx, s, e; };
vector<query> q;
int k, cnt, d[100100], p[1000100], ans[100100];

bool cmp(query a, query b){
	if(a.s/k==b.s/k) return a.e<b.e;
	return a.s/k<b.s/k;
}

int main(){
	int n, m, a, b, i;
	scanf("%d", &n); k=sqrt(n);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	scanf("%d", &m);
	for(i=0; i<m; i++){
		query t;
		scanf("%d %d", &a, &b);
		t.idx=i; t.s=a; t.e=b;
		q.push_back(t);
	}
	sort(q.begin(), q.end(), cmp);
	a=q[0].s; b=q[0].e;
	for(i=a; i<=b; i++){
		if(p[d[i]]==0) cnt++;
		p[d[i]]++;
	}
	ans[q[0].idx]=cnt;
	for(i=1; i<m; i++){
		query t=q[i];
		while(a<t.s) if(--p[d[a++]]==0) cnt--;
		while(a>t.s) if(++p[d[--a]]==1) cnt++;
		while(b<t.e) if(++p[d[++b]]==1) cnt++;
		while(b>t.e) if(--p[d[b--]]==0) cnt--;
		ans[t.idx]=cnt;
	}
	for(i=0; i<m; i++) printf("%d\n", ans[i]);
}
