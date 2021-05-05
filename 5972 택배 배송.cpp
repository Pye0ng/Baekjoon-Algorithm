#include<stdio.h>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;
priority_queue<pair<int, int> > q;
vector<pair<int, int> > v[50010];
int co, nw, cost, d[50010];

int main(){
	int n, m, i;
	scanf("%d %d", &n, &m);
	for(i=0; i<m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}
	for(i=1; i<=n; i++) d[i]=INF;
	q.push({0, 1}); d[1]=0;
	while(!q.empty()){
		co=-q.top().first;
		nw=q.top().second;
		q.pop();
		for(i=0; i<v[nw].size(); i++){
			cost=co+v[nw][i].second;
			if(cost<d[v[nw][i].first]){
				d[v[nw][i].first]=cost;
				q.push({-cost, v[nw][i].first});
			}
		}
	}
	printf("%d", d[n]);
}
 
