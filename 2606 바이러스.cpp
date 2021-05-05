#include<stdio.h>
int n, m, cnt=-1;
int v[150], g[150][150];

void dfs(int k){
	cnt++;
	v[k]=1;
	for(int i=1; i<=n; i++)
		if(g[k][i]==1&&v[i]==0) dfs(i);
}

int main(){
	int i, j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		g[a][b]=g[b][a]=1;
	}
	dfs(1);
	printf("%d", cnt); 
}
