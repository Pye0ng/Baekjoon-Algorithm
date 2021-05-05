#include<stdio.h>
int parent[1000010];

int find(int t){
	if(parent[t]<0) return t;
	else return parent[t]=find(parent[t]);
}

void uni_on(int x, int y){
	x=find(x); y=find(y);
	if(x==y) return;
	if(parent[x]<parent[y]){
		parent[x]+=parent[y];
		parent[y]=x;
	}
	else{
		parent[y]+=parent[x];
		parent[x]=y;
	}
}

int main(){
	int n, m, i;
	scanf("%d %d", &n, &m);
	for(i=0; i<=n; i++) parent[i]=-1;
	for(i=0; i<m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a==0) uni_on(b, c);
		else printf("%s\n", find(b)==find(c)?"YES":"NO");
	}
}
