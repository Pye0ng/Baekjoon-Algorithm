#include<stdio.h>
#include<vector>
#include<queue>
#define INF 1e8
using namespace std;
vector<pair<int, int> > t[20010];
priority_queue<pair<int, int> > q;
int d[20010];

int main(){
	int v, e, s, i;
	for(i=0; i<=20000; i++) d[i]=INF;
	scanf("%d %d %d", &v, &e, &s);
	for(i=0; i<e; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		t[a].push_back({b, c});
	}
	q.push({0, s}); d[s]=0;
	while(!q.empty()){
		int co=-q.top().first;
		int nw=q.top().second;
		q.pop();
		if(d[nw]<co) continue;
		for(i=0; i<t[nw].size(); i++){
			int cost=co+t[nw][i].second;
			if(cost<d[t[nw][i].first]){
				d[t[nw][i].first]=cost;
				q.push({-cost, t[nw][i].first});
			}
		}
	}
	for(i=1; i<=v; i++){
		if(d[i]==INF) printf("INF\n");
		else printf("%d\n", d[i]);
	}
}
