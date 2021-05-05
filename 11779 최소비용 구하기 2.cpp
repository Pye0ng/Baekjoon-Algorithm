#include<stdio.h>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;
vector<pair<int, int> > v[1010];
priority_queue<pair<int, int> > q;
vector<int> ans;
int n, m, d[1010], dp[1010];

int main(){
	int a, b, c, co, nw, i;
	scanf("%d %d", &n, &m);
	for(i=0; i<m; i++){
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({b, c});
	}
	for(i=0; i<=n; i++) d[i]=INF;
	scanf("%d %d", &a, &b);
	q.push({0, a}); d[a]=0;
	while(!q.empty()){
		co=-q.top().first;
		nw=q.top().second;
		q.pop();
		for(i=0; i<v[nw].size(); i++){
			int cost=co+v[nw][i].second;
			if(cost<d[v[nw][i].first]){
				d[v[nw][i].first]=cost;
				q.push({-cost, v[nw][i].first});
				dp[v[nw][i].first]=nw;
			}
		}
	}
	nw=b;
	while(b!=a){
		ans.push_back(b);
		b=dp[b];
	}
	ans.push_back(a);
	printf("%d\n%d\n", d[nw], ans.size());
	for(i=ans.size()-1; i>=0; i--) printf("%d ", ans[i]);
}
