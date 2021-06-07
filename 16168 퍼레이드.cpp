#include<stdio.h>
#include<vector>
using namespace std;
vector<int> v[3010];
int cnt, visit[3010], d[3010];

void dfs(int t){
	visit[t]=1;
	for(int i=0; i<v[t].size(); i++)
		if(visit[v[t][i]]==0) dfs(v[t][i]);
}

int main(){
	int n, m, a, b, i;
	scanf("%d %d", &n, &m);
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
		d[a]++; d[b]++;
	}
	dfs(1);
	for(i=1; i<=n; i++){
		if(visit[i]==0){
			printf("NO");
			return 0;
		}
		if(d[i]%2) cnt++;
	}
	if(cnt==2||cnt==0) printf("YES");
	else printf("NO");
}
