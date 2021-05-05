#include<stdio.h>
#include<vector>
std::vector<int> v;
int parent[300010];

int find(int t){
	if(parent[t]<0) return t;
	else{
		parent[t]=find(parent[t]);
		return parent[t];
	}
}

void uni(int x, int y){
	x=find(x); y=find(y);
	if(x==y) return;
	if(parent[x]<=parent[y]){ parent[x]+=parent[y]; parent[y]=x; }
	else{ parent[y]+=parent[x]; parent[x]=y; }
}

int main(){
	int n, a, b, i;
	scanf("%d", &n); 
	for(i=1; i<=n; i++) parent[i]=-1;
	for(i=1; i<n-1; i++){
		scanf("%d %d", &a, &b);
		uni(a, b);
	}
	for(i=1; i<=n; i++)
		if(parent[i]<0) v.push_back(i);
	printf("%d %d", v[0], v[1]);
}
