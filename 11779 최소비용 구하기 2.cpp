#include<stdio.h>
#include<vector>
#include<queue>
#define x first 
#define y second
using namespace std;
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > q;
vector<pii> v[1010];
vector<int> ans;
int INF=1e9, d[1010], dp[1010];

int main(){
	int n, s, e, c, i;
	scanf("%d %d", &n, &e);
	while(e--){
		int a, b;
		scanf("%d %d %d", &a, &b, &s);
		v[a].push_back(pii(b, s));
	}
	scanf("%d %d", &s, &e);
	for(i=1; i<=n; i++) d[i]=s==i?0:INF;
	q.push(pii(0, s));
	while(!q.empty()){
		pii p=q.top(); q.pop();
		if(p.x>d[p.y]) continue;
		for(auto i:v[p.y]){
			c=p.x+i.y;
			if(c<d[i.x]){
				d[i.x]=c; dp[i.x]=p.y;
				q.push(pii(c, i.x));
			}
		}
	}
	for(i=e; i>0; i=dp[i]) ans.push_back(i);
	printf("%d\n%d\n", d[e], ans.size());
	for(i=ans.size()-1; i>=0; i--) printf("%d ", ans[i]);
}
