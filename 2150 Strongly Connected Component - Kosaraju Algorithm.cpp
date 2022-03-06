#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
vector<int> v[10100], r[10100], c[10100];
stack<int> s;
int vis[10100];

void dfs(int t){
	vis[t]=1;
	for(int i=0; i<v[t].size(); i++)
		if(!vis[v[t][i]]) dfs(v[t][i]);
	s.push(t);
}

void scc(int t, int p){
	vis[t]=1; c[p].push_back(t);
	for(int i=0; i<r[t].size(); i++)
		if(!vis[r[t][i]]) scc(r[t][i], p);
}

bool cmp(vector<int> a, vector<int> b){ return a[0]<b[0]; }

int main(){
	int n, m, a, b, i, j;
	scanf("%d %d", &n, &m);
	while(m--){
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		r[b].push_back(a);
	}
	for(i=1; i<=n; i++)
		if(!vis[i]) dfs(i);
	for(i=1; i<=n; i++) vis[i]=0;
	a=0;
	while(!s.empty()){
		m=s.top(); s.pop();
		if(!vis[m]) scc(m, a++);
	}
	for(i=0; i<a; i++) sort(c[i].begin(), c[i].end());
	sort(c, c+a, cmp);
	printf("%d\n", a);
	for(i=0; i<a; i++){
		for(j=0; j<c[i].size(); j++) printf("%d ", c[i][j]);
		printf("-1\n");
	}
}
