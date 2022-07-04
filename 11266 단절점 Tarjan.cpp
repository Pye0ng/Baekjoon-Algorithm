#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> g[10100], ans;
int ord[10100], pa[10100], low[10100], v[10100], cnt;

void dfs(int t){
	ord[t]=++cnt;
	low[t]=cnt;
	int ch=0;
	for(auto i:g[t]){
		if(i==pa[t]) continue;
		if(!ord[i]){
			pa[i]=t; ch++;
			dfs(i);
			if(!pa[t]&&ch>1&&!v[t]){ ans.push_back(t); v[t]=1; }
			else if(pa[t]&&low[i]>=ord[t]&&!v[t]){ ans.push_back(t); v[t]=1; } // 자식이 재귀에서 아래의 else를 만족했다면 단절점이 아니 
			low[t]=min(low[t], low[i]);
		}
		else low[t]=min(low[t], ord[i]); //자식이 방문 순서가다 빠른 정점으로 이동할 수 있다면 여기서 ord[i]로 바뀐다 
	}
}

int main(){
	int n, m, i;	
	scanf("%d %d", &n, &m);
	while(m--){
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(i=1; i<=n; i++) if(!ord[i]) dfs(i);
	sort(ans.begin(), ans.end()); 
	printf("%d\n", ans.size());
	for(auto i:ans) printf("%d ", i);
}
