#include<stdio.h>
int p[100100];

int find(int t){
	if(p[t]<0) return t;
	return p[t]=find(p[t]);
}

void unite(int x, int y){
	x=find(x); y=find(y);
	if(x==y) return;
	if(p[x]<p[y]){ p[x]+=p[y]; p[y]=x; }
	else{ p[y]+=p[x]; p[x]=y; }
}

int main(){
	int n, m, a, b, i;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){ scanf("%d", &p[i]); p[i]*=-1; }
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		unite(a, b);
		printf("%d\n", -p[find(a)]);
	}
}
