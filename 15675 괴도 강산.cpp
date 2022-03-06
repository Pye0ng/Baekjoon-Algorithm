#include<stdio.h>
#include<vector>
using namespace std;
vector<int> p[4040], r[4040], k;
char c[1010][1010];
int n, m, v[4040];

void edge(int a, int b, int t){
	if(t) a+=(a>0?n:-n);
	else b+=(b>0?n:-n);
	a=a>0?a*2:(-a)*2+1;
	b=b>0?b*2:(-b)*2+1;
	p[a].push_back(b);
	r[b].push_back(a);
}

void dfs(int t){
	v[t]=1;
	for(int i=0; i<p[t].size(); i++)
		if(!v[p[t][i]]) dfs(p[t][i]);
	k.push_back(t);
}

void rdfs(int t, int a){
	v[t]=a;
	for(int i=0; i<r[t].size(); i++)
		if(v[r[t][i]]==0) rdfs(r[t][i], a);
}

int main(){
	int t=1, i, j;
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++) scanf("%s", c[i]);
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++){
			if(c[i-1][j-1]=='#'){ edge(i, j, 0); edge(-i, -j, 0); edge(j, i, 1); edge(-j, -i, 1); }
			if(c[i-1][j-1]=='*'){ edge(i, -j, 0); edge(j, -i, 1); edge(-i, j, 0); edge(-j, i, 1); }
		}
	for(i=2; i<=2*(n+m)+1; i++)
		if(!v[i]) dfs(i);
	for(i=2; i<=2*(n+m)+1; i++) v[i]=0;
	for(i=k.size()-1; i>=0; i--)
		if(v[k[i]]==0) rdfs(k[i], t++);
	t=1;
	for(i=1; i<=n+m; i++)
		if(v[i<<1]==v[i<<1|1]) t=0;
	printf("%d", t);
}
