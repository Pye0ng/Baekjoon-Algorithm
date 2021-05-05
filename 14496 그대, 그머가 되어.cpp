#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int n, m, x, y, d[1010];
vector<int> v[1010];
queue<int> q;

int main(){
	int i;
	scanf("%d %d %d %d", &x, &y, &n, &m);
	for(i=1; i<=m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	q.push(x);
	while(!q.empty()){
		int s=q.front(); q.pop();
		if(s==y){
			printf("%d", d[y]);
			return 0;
		}
		for(i=0; i<v[s].size(); i++)
			if(d[v[s][i]]==0){
				d[v[s][i]]=d[s]+1;
				q.push(v[s][i]);
			}	
	}
	printf("-1");
}
