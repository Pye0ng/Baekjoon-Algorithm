#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v[10100];
int d[10100], p[10100], vis[10100], s[15][10100];

void dfs(int n, int h){
	vis[n]=1; d[n]=h;
	for(int i=0; i<v[n].size(); i++)
		if(!vis[v[n][i]]){
			s[0][v[n][i]]=n;
			dfs(v[n][i], h+1);
		}
}

int lca(int a, int b){
	int i;
	if(d[a]>d[b]) swap(a, b);
	for(i=13; i>=0; i--)
		if(d[b]-d[a]>=(1<<i)) b=s[i][b];
	if(a==b) return a;
	for(i=13; i>=0; i--)
		if(s[i][a]!=s[i][b]){
			a=s[i][a];
			b=s[i][b];
		}
	return s[0][a];
}

int main(){
	int t, n, m, a, b, i, j;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n); m=0;
		for(i=1; i<n; i++){
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
			p[b]=a;
		}
		for(i=1; i<=n; i++)
			if(p[i]==0) m=i;
		dfs(m, 0);
		for(i=1; i<14; i++)
			for(j=1; j<=n; j++)
				s[i][j]=s[i-1][s[i-1][j]];
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
		for(i=1; i<=n; i++){
			for(j=0; j<14; j++) s[j][i]=0;
			d[i]=0; p[i]=0; vis[i]=0;
			v[i].clear();
		}
	}
}
