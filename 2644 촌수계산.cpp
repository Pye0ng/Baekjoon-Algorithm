#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[110];
int n, m, x, y;
bool visited[110];

int bfs(int s){
	int cnt=0;
	queue<int> q;
	visited[s]=1;
	q.push(s);
	while(!q.empty()){
		int sz=q.size();
		for(int i=0; i<sz; i++){
			int p=q.front();
			if(p==y) return cnt;
			q.pop();
			for(int j=0; j<v[p].size(); j++){
				int k=v[p][j];
				if(!visited[k]){
					visited[k]=1;
					q.push(k);
				}
			}
		}
		cnt++;
	}
	return -1;
}

int main(){
	scanf("%d %d %d %d", &n, &x, &y, &m);
	for(int i=1; i<=m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	printf("%d", bfs(x));
}
