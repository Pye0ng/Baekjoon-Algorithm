#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
vector<int> v[101];
vector<pair<int, int> > ans;
int n, m, cnt, mn=100000000, f[101];
bool visited[101];

void bfs(int s, int k){
	queue<int> q;
	q.push(s);
	visited[s]=1;
	while(!q.empty()){
		int size=q.size();
		for(int i=1; i<=size; i++){
			int p=q.front();
			if(p==k) return;
			q.pop();
			for(int j=0; j<v[p].size(); j++){
				int c=v[p][j];
				if(!visited[c]){
					q.push(c);
					visited[c]=1;
				}
			}
		}
		cnt++;
	}
}

int main(){
	int i, j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(i=1; i<=n; i++) sort(v[i].begin(), v[i].end());
	for(i=1; i<=n; i++){
		cnt=0;
		for(j=1; j<=n; j++){
			if(i==j) continue;
			bfs(i, j);
			memset(visited, 0, sizeof(visited));
		}
		ans.push_back({cnt, i});
	}
	sort(ans.begin(), ans.end());
	printf("%d", ans[0].second);
}
