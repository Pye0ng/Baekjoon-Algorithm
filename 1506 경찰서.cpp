#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
vector<int> v[110], r[110], c[100];
stack<int> s;
int sum, a, m, d[110], vis[110];
char p[110];

void dfs(int t){
	vis[t]=1;
	for(int i=0; i<v[t].size(); i++)
		if(!vis[v[t][i]]) dfs(v[t][i]);
	s.push(t);
}

void scc(int t, int q){
	vis[t]=1; c[q].push_back(t);
	for(int i=0; i<r[t].size(); i++)
		if(!vis[r[t][i]]) scc(r[t][i], q);
}

int main(){
	int n, i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	for(i=1; i<=n; i++){
		scanf("%s", p);
		for(j=1; j<=n; j++)
			if(p[j-1]=='1'){
				v[i].push_back(j);
				r[j].push_back(i);
			}
	}
	for(i=1; i<=n; i++)
		if(!vis[i]) dfs(i);
	for(i=1; i<=n; i++) vis[i]=0;
	while(!s.empty()){
		i=s.top(); s.pop();
		if(!vis[i]) scc(i, a++);
	}
	for(i=0; i<a; i++){
		m=1e7;
		for(j=0; j<c[i].size(); j++) m=min(m, d[c[i][j]]);
		sum+=m;
	}
	printf("%d", sum);
}
