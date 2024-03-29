#include<stdio.h>
int p[1000100];

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
	int n, m, t, a, b, i;
	scanf("%d %d", &n, &m);
	for(i=0; i<=n; i++) p[i]=-1;
	while(m--){
		scanf("%d %d %d", &t, &a, &b);
		if(t) printf("%s\n", find(a)==find(b)?"YES":"NO");
		else unite(a, b);
	}
}
