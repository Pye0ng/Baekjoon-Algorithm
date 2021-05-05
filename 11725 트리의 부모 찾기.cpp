#include<stdio.h>
#include<vector>
std::vector<int> v[100010];
int par[100010], visited[100010];

void tree(int t, int p){
	visited[t]=1; par[t]=p;
	for(int i=0; i<v[t].size(); i++)
		if(!visited[v[t][i]]) tree(v[t][i], t);
}

int main(){
	int n, i;
	scanf("%d", &n);
	for(i=1; i<n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	tree(1, 0);
	for(i=2; i<=n; i++) printf("%d\n", par[i]);
}

