#include<stdio.h>
#include<vector>
#include<queue>
#define x first
#define y second
using namespace std;
typedef long long int ll;
typedef pair<ll, int> p;
priority_queue<p> q;
vector<p> v[1010];
ll c, co, t, d[1010];

int main(){
	int n, m, s, e, i;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++) d[i]=1e13;
	for(i=0; i<m; i++){
		scanf("%d %d %lld", &s, &e, &t);
		v[s].push_back({t, e});
	}
	scanf("%d %d", &s, &e);
	q.push({0, s}); d[s]=0;
	while(!q.empty()){
		t=-q.top().x; c=q.top().y;
		q.pop(); if(d[c]<t) continue;
		for(i=0; i<v[c].size(); i++){
			co=t+v[c][i].x;
			if(co<d[v[c][i].y]){
				d[v[c][i].y]=co;
				q.push({-co, v[c][i].y});
			}
		}
	}
	printf("%lld ", d[e]);
}
