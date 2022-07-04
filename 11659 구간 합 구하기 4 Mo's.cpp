#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
struct query{ int idx, s, e; };
vector<query> q;
int k, sum, d[100100], ans[100100];

bool cmp(query a, query b){
	if(a.s/k==b.s/k) return a.e<b.e;
	return a.s/k<b.s/k;
}

int main(){
	int n, m, a, b, i;
	scanf("%d %d", &n, &m);
	k=sqrt(n);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	for(i=0; i<m; i++){
		query t;
		scanf("%d %d", &a, &b);
		t.idx=i; t.s=a; t.e=b;
		q.push_back(t);
	}
	sort(q.begin(), q.end(), cmp);
	a=q[0].s; b=q[0].e;
	for(i=a; i<=b; i++) sum+=d[i];
	ans[q[0].idx]=sum;
	for(i=1; i<m; i++){
		while(a<q[i].s) sum-=d[a++];
		while(a>q[i].s) sum+=d[--a];
		while(b<q[i].e) sum+=d[++b];
		while(b>q[i].e) sum-=d[b--];
		ans[q[i].idx]=sum;
	}
	for(i=0; i<m; i++) printf("%d\n", ans[i]);
}
