#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
struct query{ int idx, s, e; };
int k, mx, d[100100], p[100100], r[100100], ans[100100];
vector<query> q;

bool cmp(query a, query b){
	if(a.s/k==b.s/k) return a.e<b.e;
	return a.s/k<b.s/k;
}

void Inc(int t){
	if(p[t]) r[p[t]]--;
	p[t]++; r[p[t]]++;
	mx=max(mx, p[t]);
}

void Dec(int t){
	r[p[t]]--;
	if(p[t]==mx&&!r[p[t]]) mx--;
	p[t]--; r[p[t]]++;
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
	a=b=0; 
	for(i=0; i<m; i++){
		query t=q[i];
		while(a<t.s) Dec(d[a++]);
		while(a>t.s) Inc(d[--a]);
		while(b>t.e) Dec(d[b--]);
		while(b<t.e) Inc(d[++b]);
		ans[t.idx]=mx;
	}
	for(i=0; i<m; i++) printf("%d\n", ans[i]);
} 
