#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> g[410];
int t, c[410][410], f[410][410], p[410];

int main(){
	int n, m, a, b, i;
	scanf("%d %d", &n, &m);
	while(m--){
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
		c[a][b]=1;
	}
	while(1){
		for(i=1; i<=n; i++) p[i]=-1;
		queue<int> q; q.push(1);
		while(!q.empty()){
			a=q.front(); q.pop();
			for(i=0; i<g[a].size(); i++){
				b=g[a][i];
				if(c[a][b]>f[a][b]&&p[b]==-1){
					q.push(b); p[b]=a;
					if(b==2) break;
				}
			}
		}
		if(p[2]==-1) break;
		for(i=2; i!=1; i=p[i]){
			f[p[i]][i]++;
			f[i][p[i]]--;
		}
		t++;
	}
	printf("%d", t);
}
