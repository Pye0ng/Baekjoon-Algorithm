#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long int ll;
struct query{ int idx, s, e; };
ll power, d[100100], ans[100100];
int k, cnt[1001000];
vector<query> q;

bool cmp(query a, query b){
	if(a.s/k==b.s/k) return a.e<b.e;
	return a.s/k<b.s/k;
}

void change(int t, int ch){ power+=d[t]*cnt[d[t]]*cnt[d[t]]*ch; }

int main(){
	int n, m, a, b, i; query t;
	scanf("%d %d", &n, &m); k=sqrt(n);
	for(i=1; i<=n; i++) scanf("%lld", &d[i]);
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		t.idx=i; t.s=a; t.e=b;
		q.push_back(t);
	}
	sort(q.begin(), q.end(), cmp);
	a=q[0].s; b=q[0].e;
	for(i=a; i<=b; i++){
		cnt[d[i]]++;
		power+=d[i]*(2*cnt[d[i]]-1);
	}
	ans[q[0].idx]=power;
	for(i=1; i<m; i++){
		t=q[i];
		while(a<t.s){
			change(a, -1); cnt[d[a]]--;
			change(a, 1); a++;
		}
		while(a>t.s){ 
			a--; change(a, -1);
			cnt[d[a]]++; change(a, 1);
		}
		while(b>t.e){
			change(b, -1); cnt[d[b]]--;
			change(b, 1); b--;
		}
		while(b<t.e){
			b++; change(b, -1);
			cnt[d[b]]++; change(b, 1);
		}
		ans[t.idx]=power;
	}
	for(i=0; i<m; i++) printf("%lld\n", ans[i]);
}
