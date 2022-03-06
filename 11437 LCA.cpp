#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v[50100];
int d[50100], vis[50100], s[17][50100];

void dfs(int n, int h){
	vis[n]=1; d[n]=h;
	for(int i=0; i<v[n].size(); i++)
		if(!vis[v[n][i]]){
			s[0][v[n][i]]=n;
			dfs(v[n][i], h+1);
		}
}

int lca(int a, int b){
	if(d[a]>d[b]) swap(a, b);
	for(int i=15; i>=0; i--)
		if(d[b]-d[a]>=(1<<i)) b=s[i][b];
	if(a==b) return a;
	for(int i=15; i>=0; i--)
		if(s[i][a]!=s[i][b]){
			a=s[i][a];
			b=s[i][b];
		}
	return s[0][b];
}

int main(){
	int n, m, a, b, i, j;
	scanf("%d", &n);
	for(i=1; i<n; i++){
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0);
	for(i=1; i<16; i++)
		for(j=1; j<=n; j++)
			s[i][j]=s[i-1][s[i-1][j]];
	scanf("%d", &m);
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}
}
