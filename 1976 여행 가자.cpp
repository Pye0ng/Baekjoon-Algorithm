#include<stdio.h>
int parent[210], route[1010], con[210][210];

int find(int t){
	if(parent[t]==t) return t;
	else return parent[t]=find(parent[t]);
}

void connect(int x, int y){
	x=find(x); y=find(y);
	if(x<y) parent[y]=x;
	else parent[x]=y;
}

int main(){
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		parent[i]=i;
		for(j=1; j<=n; j++) scanf("%d", &con[i][j]);
	}
	for(i=1; i<=m; i++) scanf("%d", &route[i]);
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			if(con[i][j]) connect(i, j);
	for(i=1; i<=m; i++)
		if(parent[route[1]]!=parent[route[i]]){ printf("NO"); return 0; }
	printf("YES");
} 
