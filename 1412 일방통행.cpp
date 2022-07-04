#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int> g[52];
queue<int> q;
int d[52];
char c[52][52];

int main(){
	int n, t, i, j;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%s", c[i]);
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if(c[i][j]=='Y'&&c[j][i]=='N'){
				g[i+1].push_back(j+1);
				d[j+1]++;
			}
	for(i=1; i<=n; i++)
		if(d[i]==0) q.push(i);
	while(!q.empty()){
		t=q.front(); q.pop();
		for(i=0; i<g[t].size(); i++)
			if(--d[g[t][i]]==0)
				q.push(g[t][i]);
	}
	t=0;
	for(i=1; i<=n; i++)
		if(d[i]) t=1;
	printf("%s", t?"NO":"YES");
}
