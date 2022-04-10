#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
queue<int> q;
vector<int> v[10100];
int d[10100], p[10100], dp[10100], a=0;

int main(){
	int n, m, t, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d %d", &p[i], &m);
		while(m--){
			scanf("%d", &t);
			v[t].push_back(i);
			d[i]++;
		}
	}
	for(i=1; i<=n; i++)
		if(d[i]==0){
			q.push(i);
			dp[i]=p[i];
		}
	while(!q.empty()){
		t=q.front(); q.pop(); 
		for(i=0; i<v[t].size(); i++){
			m=v[t][i];
			if(--d[m]==0) q.push(v[t][i]);
			dp[m]=max(dp[m], dp[t]+p[m]);
		}
	}
	for(i=1; i<=n; i++)
		a=max(a, dp[i]);
	printf("%d", a);
}
