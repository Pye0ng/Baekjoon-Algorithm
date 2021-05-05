#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, cnt;
bool visited[1001];
vector<int> v[1001];

int ch(){
	for(int i=1; i<=n; i++)
		if(!visited[i]) return i;
	return 0;
}

void dfs(int s){
	visited[s]=1;
	for(int i=0; i<v[s].size(); i++){
		int k=v[s][i];
		if(!visited[k]) dfs(k);
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1; i<=n; i++) sort(v[i].begin(), v[i].end());
	while(ch()){
		cnt++;
		dfs(ch());
	}
	printf("%d", cnt);
}
