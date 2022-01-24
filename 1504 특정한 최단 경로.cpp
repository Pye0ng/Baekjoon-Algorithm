#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#define x first
#define y second
using namespace std;
typedef long long int ll;
typedef pair<ll, int> p;
priority_queue<p> q;
vector<p> v[820];
ll m, co, cs, nw, d[5][820];

void dijk(int t, int k){
	q.push({0, t}); d[k][t]=0;
	while(!q.empty()){
		co=-q.top().x; nw=q.top().y;
		q.pop(); if(d[k][nw]<co) continue;
		for(int i=0; i<v[nw].size(); i++){
			cs=co+v[nw][i].y;
			if(cs<d[k][v[nw][i].x]){
				d[k][v[nw][i].x]=cs;
				q.push({-cs, v[nw][i].x});
			}
		}
	}
}

int main(){
	int n, v1, v2, i, j;
	scanf("%d %lld", &n, &m);
	for(i=1; i<4; i++)
		for(j=1; j<=n; j++) d[i][j]=1e9;
	for(i=0; i<m; i++){
		scanf("%d %d %d", &v1, &v2, &co);
		v[v1].push_back({v2, co});
		v[v2].push_back({v1, co});
	}
	scanf("%d %d", &v1, &v2);
	dijk(1, 1); dijk(v1, 2); dijk(v2, 3);
	m=min(d[1][v1]+d[2][v2]+d[3][n], d[1][v2]+d[3][v1]+d[2][n]);
	if(m>=1e9) printf("-1"); 
	else printf("%lld", m);
}
