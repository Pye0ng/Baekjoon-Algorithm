#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int e[1010], c[1010], d[1010], p[1010];
vector<int> v[1010];
queue<int> q;

int main(){
	int t, n, m, a, b, i;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		for(i=1; i<=n; i++)	scanf("%d", &c[i]);
		for(i=0; i<m; i++){
			scanf("%d %d", &a, &b);
			v[a].push_back(b); e[b]++;
		}
		scanf("%d", &m);
		for(i=1; i<=n; i++)
			if(e[i]==0){ q.push(i); d[i]=c[i]; }
		while(!q.empty()){
			a=q.front(); q.pop();
			for(i=0; i<v[a].size(); i++){
				b=v[a][i];
				if(e[b]){
					d[b]=max(d[b], d[a]+c[b]);
					if(--e[b]==0) q.push(b);
				}
			}
		}
		printf("%d\n", d[m]);
		for(i=1; i<=n; i++){
			e[i]=c[i]=d[i]=0;
			v[i].clear();
		}
	}
}
