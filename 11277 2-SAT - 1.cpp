#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v[44], r[44], k;
int vis[44], c[44];

int rnot(int t){ return t^1; }
int rtrue(int t){ return t<<1; }
int rfalse(int t){ return t<<1|1; }

void dfs(int t){
	vis[t]=1;
	for(int i=0; i<v[t].size(); i++)
		if(!vis[v[t][i]]) dfs(v[t][i]);
	k.push_back(t);
}

void scc(int t, int p){
	vis[t]=1; c[t]=p;
	for(int i=0; i<r[t].size(); i++)
		if(!vis[r[t][i]]) scc(r[t][i], p);
}

int main(){
	int n, m, a, b, i;
	scanf("%d %d", &n, &m);
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		a=a>0?rtrue(a):rfalse(-a);
		b=b>0?rtrue(b):rfalse(-b);
		v[rnot(a)].push_back(b);
		v[rnot(b)].push_back(a);
		r[b].push_back(rnot(a));
		r[a].push_back(rnot(b));
	}
	for(i=2; i<=n*2+1; i++)
		if(!vis[i]) dfs(i);
	a=0;
	for(i=2; i<=n*2+1; i++) vis[i]=0;
	reverse(k.begin(), k.end());
	for(i=0; i<k.size(); i++)
		if(!vis[k[i]]) scc(k[i], ++a);
	for(i=1; i<=n; i++)
		if(c[rtrue(i)]==c[rfalse(i)]){
			printf("0");
			return 0;
		}
	printf("1");
}
