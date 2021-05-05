#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[10100];
queue<int> q;
int n, m, ans, d[10010], dp[10100], in[10100];

int main(){
	int t, i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d %d", &d[i], &m);
		for(j=0; j<m; j++){
			scanf("%d", &t);
			v[t].push_back(i);
			in[i]++;
		}
	}
	for(i=1; i<=n; i++)
		if(in[i]==0){
			q.push(i);
			dp[i]=d[i];
		}
	while(!q.empty()){
		t=q.front(); q.pop();
		for(i=0; i<v[t].size(); i++){
			int s=v[t][i];
			if(--in[s]==0) q.push(s);
			dp[s]=max(dp[s], dp[t]+d[s]);
		}
	}
	for(i=1; i<=n; i++)
		ans=max(ans, dp[i]);
	printf("%d", ans);
}
