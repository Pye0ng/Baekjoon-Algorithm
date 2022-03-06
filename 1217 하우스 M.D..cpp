#include<stdio.h>
#include<vector>
using namespace std;
vector<int> p[40100], r[40100], k;
int v[40100], c[40100];

int rtrue(int t){ return t<<1; }
int rfalse(int t){ return t<<1|1; }

void dfs(int t){
	v[t]=1;
	for(int i=0; i<p[t].size(); i++)
		if(!v[p[t][i]]) dfs(p[t][i]);
	k.push_back(t);
}

void rdfs(int t, int a){
	v[t]=1; c[t]=a;
	for(int i=0; i<r[t].size(); i++)
		if(!v[r[t][i]]) rdfs(r[t][i], a);
}

int main(){
	int m, n, a, b, t, cnt, i, j;
	scanf("%d %d", &m, &n);
	while(m){
		t=1; cnt=1;
		for(i=0; i<m; i++){
			scanf("%d %d", &a, &b);
			a=a>0?rtrue(a):rfalse(-a);
			b=b>0?rtrue(b):rfalse(-b);
			p[a^1].push_back(b);
			p[b^1].push_back(a);
			r[a].push_back(b^1);
			r[b].push_back(a^1);
		}
		for(i=2; i<=n*2+1; i++)
			if(!v[i]) dfs(i);
		for(i=2; i<=n*2+1; i++) v[i]=0;
		for(i=k.size()-1; i>=0; i--)
			if(!v[k[i]]) rdfs(k[i], cnt++);
		for(i=1; i<=n; i++)
			if(c[rtrue(i)]==c[rfalse(i)]) t=0;
		printf("%d\n", t);
		scanf("%d %d", &m, &n);
		for(i=2; i<=n*2+1; i++){
			p[i].clear();
			r[i].clear();
			k.clear();
			v[i]=0; c[i]=0;
		}
	}
}
