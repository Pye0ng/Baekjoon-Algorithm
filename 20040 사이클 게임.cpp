#include<iostream>
#include<algorithm>
using namespace std;
int parent[500010];

int find(int t){
	if(t==parent[t]) return t;
	else return parent[t]=find(parent[t]);
}

void unity(int x, int y){
	x=find(x); y=find(y);
	parent[y]=x;
}

int main(){
	int n, m, ans, i;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;
	for(i=0; i<n; i++) parent[i]=i;
	for(i=1; i<=m; i++){
		int a, b;
		cin>>a>>b;
		if(find(a)==find(b)){ cout<<i; return 0; }
		else unity(a, b);
	}
	cout<<'0';
}
