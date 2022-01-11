#include<stdio.h>
#include<vector>
#include<queue>
#define x first
#define y second
typedef long long int ll;
using namespace std;
typedef pair<ll, ll> p;
vector<p> v[10100];
priority_queue<p> q;
long long int s, d[15][10010];
int mn=1e9, t[10100], dp[13];

int main(){
	int n, m, st, nw, i, j;
	ll cs, co;
	scanf("%d %d", &n, &m);
	for(i=0; i<m; i++){
		ll a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}
	for(i=1; i<=11; i++){
		scanf("%d", &m);
		dp[i]=m; if(i==11) st=m;
		if(t[m]>0) continue;
		for(j=1; j<=n; j++) d[i][j]=1e15;
		t[m]=i;
		q.push({0, m});
		d[i][0]=m; d[i][m]=0; 
		while(!q.empty()){
			cs=-q.top().x;
			nw=q.top().y;
			q.pop();
			if(d[i][nw]<cs) continue;
			for(j=0; j<v[nw].size(); j++){
				co=cs+v[nw][j].y;
				if(co<d[i][v[nw][j].x]){
					d[i][v[nw][j].x]=co;
					q.push({-co, v[nw][j].x});
				}
			}
		}
	}
	nw=dp[1];
	if(nw==st) mn=nw;
	for(i=2; i<=10; i++){
		if(d[t[nw]][dp[i]]==1e15) continue;
		s+=d[t[nw]][dp[i]]; nw=dp[i];
		if(d[t[st]][dp[i]]<=s&&nw<mn) mn=nw; 
	}
	if(mn==1e9) printf("-1");
	else printf("%d", mn);
}
