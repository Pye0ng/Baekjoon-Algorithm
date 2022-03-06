#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
vector<int> g[100100], s;
int k, p[100100], q[100100], v[100100];

void dfs(int t){
	v[t]=1; p[t]=++k;
	for(int i=0; i<g[t].size(); i++)
		if(!v[g[t][i]]) dfs(g[t][i]);
	q[t]=k;
}

void upd(int c, int a, int b, int i, int t){
	if(i<a||i>b) return;
	s[c]+=t; int m=(a+b)>>1;
	if(a==b) return;
	upd(c<<1, a, m, i, t);
	upd(c<<1|1, m+1, b, i, t);
}

int sum(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return sum(c<<1, a, m, l, r)+sum(c<<1|1, m+1, b, l, r);
}

int main(){
	int n, m, a, b, c, t, i;
	scanf("%d %d %d", &n, &m, &c);
	for(i=2; i<=n; i++){
		scanf("%d", &c);
		g[c].push_back(i);
	}
	dfs(1); s.resize(n*4);
	t=1<<int(ceil(log2(n)));
	while(m--){
		scanf("%d %d", &a, &b);
		if(a&1){
			scanf("%d", &c);
			upd(1, 1, t, p[b], c);
		}
		else printf("%d\n", sum(1, 1, t, p[b], q[b]));
	}
}
