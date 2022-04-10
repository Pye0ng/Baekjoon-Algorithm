#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> g[100100];
int d[100100], v[100100], s[20][100100];

void dfs(int n, int h){
	v[n]=1; d[n]=h;
	for(int i=0; i<g[n].size(); i++)
		if(!v[g[n][i]]){
			s[0][g[n][i]]=n;
			dfs(g[n][i], h+1);
		}
}

int lca(int a, int b){
	if(d[a]>d[b]) swap(a, b);
	for(int i=17; i>=0; i--)
		if(d[b]-d[a]>=(1<<i)) b=s[i][b];
	if(a==b) return a;
	for(int i=17; i>=0; i--){
		if(s[i][a]!=s[i][b]){
			a=s[i][a];
			b=s[i][b];
		}
	}
	return s[0][a];
}

int main(){
	int n, m, a, b, i, j;
	scanf("%d", &n);
	for(i=1; i<n; i++){
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 0);
	for(i=1; i<18; i++)
		for(j=1; j<=n; j++)
			s[i][j]=s[i-1][s[i-1][j]];
	scanf("%d", &m);
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}
}
