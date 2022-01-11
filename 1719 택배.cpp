#include<stdio.h>
#include<vector>
#include<queue>
#define x first
#define y second
using namespace std;
typedef pair<int, int> p;
vector<p> v[210];
priority_queue<p> q;
int d[210][210], dp[210][210];

int main(){
	int n, m, cs, nw, co, i, j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			d[i][j]=1e9;
	while(m--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({c, b});
		v[b].push_back({c, a});
	}
	for(i=1; i<=n; i++){
		q.push({0, i}); d[i][i]=0;
		while(!q.empty()){
			cs=-q.top().x;
			nw=q.top().y;
			q.pop();
			if(d[i][nw]<cs) continue;
			for(j=0; j<v[nw].size(); j++){
				co=cs+v[nw][j].x;
				if(co<d[i][v[nw][j].y]){
					d[i][v[nw][j].y]=co;
					q.push({-co, v[nw][j].y});
					if(nw==i) dp[i][v[nw][j].y]=v[nw][j].y;
					else dp[i][v[nw][j].y]=dp[i][nw];
				}
			}
		}
	}
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			if(i==j) printf("- ");
			else printf("%d ", dp[i][j]);
		}
		printf("\n");	
	}
}
