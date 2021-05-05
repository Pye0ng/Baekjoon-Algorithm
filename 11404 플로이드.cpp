#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 1e9
using namespace std;
int n, m, d[110][110], dk[110][110];
vector<pair<int, int> > v[110];

int main(){
	int i, j;
	scanf("%d %d", &n, &m);
	for(i=0; i<105; i++)
		for(j=0; j<105; j++){ d[i][j]=dk[i][j]=INF; }
	for(i=0; i<m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		d[a][b]=min(d[a][b], c);
	}
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			if(d[i][j]!=INF) v[i].push_back({j, d[i][j]});
	for(i=1; i<=n; i++){
		priority_queue<pair<int, int> > q;
		q.push({0, i});
		while(!q.empty()){
			int co=-q.top().first, nw=q.top().second; q.pop(); 
			for(j=0; j<v[nw].size(); j++){
				int cost=co+v[nw][j].second;
				if(cost<dk[i][v[nw][j].first]){
					dk[i][v[nw][j].first]=cost;
					q.push({-cost, v[nw][j].first});
				}
			}
		}
	}
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			if(dk[i][j]==1e9||i==j) printf("0 ");
			else printf("%d ", dk[i][j]);
		}
		printf("\n");
	}
}
