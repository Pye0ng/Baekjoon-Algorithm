#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> g[1000100];
int ea[1000100], no[1000100], v[1000100];

void dfs(int t){
	v[t]=1; ea[t]=1;
	for(int i=0; i<g[t].size(); i++){
		if(v[g[t][i]]) continue;
		dfs(g[t][i]);
		ea[t]+=min(ea[g[t][i]], no[g[t][i]]);
		no[t]+=ea[g[t][i]];
	}
}

int main(){
	int n, i;
	scanf("%d", &n);
	for(i=1; i<n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1);
	printf("%d", min(ea[1], no[1]));
}
