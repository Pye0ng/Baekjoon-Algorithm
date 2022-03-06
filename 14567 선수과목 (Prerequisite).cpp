#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int e[1010], d[1010]; 
vector<int> v[1010];
queue<int> q;

int main(){
	int n, m, a, b, i;
	scanf("%d %d", &n, &m);
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		e[b]++;
	}
	for(i=1; i<=n; i++)
		if(e[i]==0){ d[i]=1; q.push(i); }
	while(!q.empty()){
		a=q.front(); q.pop();
		for(i=0; i<v[a].size(); i++)
			if(v[a][i])
				if(--e[v[a][i]]==0){
					q.push(v[a][i]);
					d[v[a][i]]=d[a]+1;
				}
	}
	for(i=1; i<=n; i++) printf("%d ", d[i]);
}
