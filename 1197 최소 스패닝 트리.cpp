#include<stdio.h>
#include<queue>
using namespace std;
struct p{ int v, a, b; };
struct cmp{
	bool operator()(p a, p b){
		return a.v>b.v;
	}
};
priority_queue<p, vector<p>, cmp> q; 
int ans, pa[10100];

int find(int t){
	if(pa[t]<0) return t;
	return pa[t]=find(pa[t]);
}

void unite(int x, int y){
	x=find(x); y=find(y);
	if(x==y) return;
	if(pa[x]<pa[y]){
		pa[x]+=pa[y];
		pa[y]=x;
	}
	else{
		pa[y]+=pa[x];
		pa[x]=y;
	}
}

int main(){
	int n, m, i;
	scanf("%d %d", &n, &m);
	for(i=0; i<=n; i++) pa[i]=-1;
	for(i=0; i<m; i++){
		p t; scanf("%d %d %d", &t.a, &t.b, &t.v);
		q.push(t);
	}
	while(!q.empty()){
		p t=q.top(); q.pop();
		if(find(t.a)==find(t.b)) continue;
		ans+=t.v; unite(t.a, t.b);
	}
	printf("%d", ans);
}
