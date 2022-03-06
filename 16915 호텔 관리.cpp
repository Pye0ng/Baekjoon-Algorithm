#include<stdio.h>
#include<vector>
using namespace std;
vector<int> p[200200], r[200200], h[100100], k;
int s[100100], v[200200];

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

void edge(int a, int b){
	a=a>0?a*2:(-a)*2+1;
	b=b>0?b*2:(-b)*2+1;
	p[a].push_back(b);
	r[b].push_back(a);
}

int main(){
	int n, m, a, b, i, j;
	scanf("%d %d", &m, &n);
	for(i=1; i<=m; i++) scanf("%d", &s[i]);
	for(i=1; i<=n; i++){
		scanf("%d", &a);
		for(j=0; j<a; j++){
			scanf("%d", &b);
			h[b].push_back(i);
		}
	}
	for(i=1; i<=m; i++){
		a=h[i][0]; b=h[i][1];
		if(s[i]){
			edge(a, b); edge(b, a);
			edge(-a, -b); edge(-b, -a);
		}
		else{
			edge(-a, b); edge(-b, a);
			edge(a, -b); edge(b, -a);
		}
	}
	a=1;
	for(i=2; i<=n*2+1; i++)
		if(!v[i]) dfs(i);
	for(i=2; i<=n*2+1; i++) v[i]=0;
	for(i=k.size()-1; i>=0; i--)
		if(v[k[i]]==0) rdfs(k[i], a++);
	a=1;
	for(i=1; i<=n; i++)
		if(v[i<<1]==v[i<<1|1]) a=0;
	printf("%d", a);
}
