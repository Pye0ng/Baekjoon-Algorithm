#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
vector<int> g[100100], su, sd;
int k, d, p[100100], q[100100], v[100100];

void dfs(int t){
	v[t]=1; p[t]=++k;
	for(int i=0; i<g[t].size(); i++)
		if(!v[g[t][i]]) dfs(g[t][i]);
	q[t]=k;
}

void updu(int c, int a, int b, int i, int t){
	if(i<a||i>b) return;
	su[c]+=t; int m=(a+b)>>1;
	if(a==b) return;
	updu(c<<1, a, m, i, t);
	updu(c<<1|1, m+1, b, i, t);
}

void updd(int c, int a, int b, int i, int t){
	if(i<a||i>b) return;
	sd[c]+=t; int m=(a+b)>>1;
	if(a==b) return;
	updd(c<<1, a, m, i, t);
	updd(c<<1|1, m+1, b, i, t);
}

int sumu(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return su[c];
	int m=(a+b)>>1;
	return sumu(c<<1, a, m, l, r)+sumu(c<<1|1, m+1, b, l, r);
}

int sumd(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return sd[c];
	int m=(a+b)>>1;
	return sumd(c<<1, a, m, l, r)+sumd(c<<1|1, m+1, b, l, r);
}

int main(){
	int n, m, a, b, c, t, i, j;
	scanf("%d %d %d", &n, &m, &c);
	for(i=2; i<=n; i++){
		scanf("%d", &c);
		g[c].push_back(i);
	}
	dfs(1); t=1<<int(ceil(log2(n)));
	su.resize(n*4); sd.resize(n*4);
	while(m--){
		scanf("%d", &a);
		if(a==1){
			scanf("%d %d", &b, &c);
			if(d) updu(1, 1, t, p[b], c);
			else{
				updd(1, 1, t, p[b], c);
				updd(1, 1, t, q[b]+1, -c);
			}
		}
		else if(a==2){
			scanf("%d", &b);
			printf("%d\n", sumu(1, 1, t, p[b], q[b])+sumd(1, 1, t, 1, p[b]));
		}
		else d^=1;
	}
}
