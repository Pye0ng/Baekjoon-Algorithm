#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
vector<int> v;
int p[100100], ch[100100];
pii q[100100];
ll ans;

int find(int t){ return p[t]<0?t:p[t]=find(p[t]); }

void unite(int a, int b){
	a=find(a); b=find(b);
	if(a!=b){
		if(p[a]>p[b]) swap(a, b);
		p[a]+=p[b]; p[b]=a;
	}
}

int main(){
	int n, m, k, a, b, i;
	scanf("%d %d %d", &n, &m, &k);
	for(i=1; i<=n; i++) p[i]=-1;
	for(i=1; i<=m; i++){
		scanf("%d %d", &a, &b);
		q[i]=pii(a, b);
	}
	for(i=0; i<k; i++){
		scanf("%d", &a);
		ch[a]=1; v.push_back(a);
	}
	for(i=1; i<=m; i++)
		if(!ch[i]) unite(q[i].x, q[i].y);
	for(i=v.size()-1; i>=0; i--){
		a=find(q[v[i]].x); b=find(q[v[i]].y);
		if(a!=b) ans+=(ll)p[a]*p[b];
		unite(q[v[i]].x, q[v[i]].y);
	}
	printf("%lld", ans);
}
