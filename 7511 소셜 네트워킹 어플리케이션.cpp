#include<stdio.h>

int find(int parent[], int t){
	if(t==parent[t]) return t;
	else return parent[t]=find(parent, parent[t]);
}

void connect(int parent[], int x, int y){
	x=find(parent, x); y=find(parent, y);
	if(x<y) parent[y]=x;
	else parent[x]=y;
}

int main(){
	int t, n, m, k, i, s=0;
	int a, b;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		int parent[n+5];
		for(i=0; i<n; i++) parent[i]=i;
		for(i=0; i<m; i++){
			scanf("%d %d", &a, &b);
			connect(parent, a, b);
		}
		scanf("%d", &k);
		printf("Scenario %d:\n", ++s);
		for(i=0; i<k; i++){
			scanf("%d %d", &a, &b);
			printf("%d\n", find(parent, a)==find(parent, b));
		}
		printf("\n");
	}
}
