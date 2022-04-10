#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#define x first
#define y second
using namespace std;
typedef pair<int, int> p;
vector<p> g[10100], r[10100];
queue<p> qp, qr;
queue<int> Q;
int cnt, v[10100], cp[10100], cr[10100], dp[10100], dr[10100];

int main(){
	int n, m, a, b, c, s, e, i;
	scanf("%d %d", &n, &m);
	while(m--){
		scanf("%d %d %d", &a, &b, &c);
		g[a].push_back({b, c}); dp[b]++;
		r[b].push_back({a, c}); dr[a]++;
	}
	scanf("%d %d", &s, &e);
	for(i=1; i<=n; i++){
		if(!dp[i]) qp.push({i, i==s});
		if(!dr[i]) qr.push({i, i==e});
	}
	while(!qp.empty()){
		p q=qp.front(); qp.pop();
		for(i=0; i<g[q.x].size(); i++){
			m=g[q.x][i].x;
			if(q.y) cp[m]=max(cp[m], cp[q.x]+g[q.x][i].y);
			if(!--dp[m]) qp.push({m, (m==s)||q.y||cp[m]});
		}
	}
	while(!qr.empty()){
		p q=qr.front(); qr.pop();
		for(i=0; i<r[q.x].size(); i++){
			m=r[q.x][i].x;
			if(q.y) cr[m]=max(cr[m], cr[q.x]+r[q.x][i].y);
			if(!--dr[m]) qr.push({m, (m==e)||q.y||cr[m]});
		}
	}
	Q.push(s);
	while(!Q.empty()){
		m=Q.front(); Q.pop();
		for(i=0; i<g[m].size(); i++){
			a=g[m][i].x;
			if(cp[m]+g[m][i].y+cr[a]==cp[e]) cnt++;
			if(!v[a]){ v[a]=1; Q.push(a); }
		}
	}
	printf("%d\n%d", cp[e], cnt);
}
