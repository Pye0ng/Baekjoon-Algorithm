#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int c[210][210], f[210][210], p[210];

int main(){
	int t, n, m, a, b, ans, i;
	scanf("%d", &t);
	while(t--){
		vector<int> g[210];
		queue<int> q; ans=0;
		scanf("%d %d", &n, &m);
		for(i=0; i<m; i++){
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
			g[b].push_back(a);
			c[a][b]=a==1||a==n||b==1||b==n?1:2000000;
		}
		while(1){
			for(i=1; i<=n; i++) p[i]=-1;
			q.push(1);
			while(!q.empty()){
				a=q.front(); q.pop();
				for(i=0; i<g[a].size(); i++){
					b=g[a][i];
					if(c[a][b]>f[a][b]&&p[b]==-1){
						p[b]=a; q.push(b);
						if(b==n) break;
					}
				}
			}
			if(p[n]==-1) break;
			for(i=n; i!=1; i=p[i]){
				f[p[i]][i]++;
				f[i][p[i]]--;
			}
			ans++;
		}
		printf("%d\n", ans);
		for(i=1; i<=n; i++)
			for(m=1; m<=n; m++){ c[i][m]=0; f[i][m]=0; }
	}
}
