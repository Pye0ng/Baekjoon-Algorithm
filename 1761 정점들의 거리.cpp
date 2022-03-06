#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;
vector<pair<int, int> > v[40100];
int in[40100], vis[40100], q[40100], d[20][40100], s[20][40100];

void dfs(int n, int h){
	vis[n]=1; q[n]=h;
	for(int i=0; i<v[n].size(); i++)
		if(!vis[v[n][i].x]){
			s[0][v[n][i].x]=n;
			d[0][v[n][i].x]=v[n][i].y;
			dfs(v[n][i].x, h+1);
		}
}

int lca(int a, int b){
	int sum=0;
	if(q[a]>q[b]) swap(a, b);
	for(int i=15; i>=0; i--)
		if(q[b]-q[a]>=(1<<i)){
			sum+=d[i][b];
			b=s[i][b];
		}
	if(a==b) return sum;
	for(int i=15; i>=0; i--)
		if(s[i][a]!=s[i][b]){
			sum+=(d[i][a]+d[i][b]);
			a=s[i][a]; b=s[i][b];
		}
	return sum+d[0][a]+d[0][b];
}

int main(){
	int n, m, a, b, t, i, j;
	scanf("%d", &n);
	for(i=1; i<n; i++){
		scanf("%d %d %d", &a, &b, &m);
		v[a].push_back({b, m});
		v[b].push_back({a, m});
		in[a]++; in[b]++;
	}
	m=0;
	for(i=1; i<=n; i++)
		if(in[i]>in[m]) m=i;
	dfs(m, 0);
	for(i=1; i<16; i++)
		for(j=1; j<=n; j++){
			t=s[i-1][j];
			s[i][j]=s[i-1][t];
			d[i][j]=d[i-1][j]+d[i-1][t];
		}
	scanf("%d", &m);
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}
}
