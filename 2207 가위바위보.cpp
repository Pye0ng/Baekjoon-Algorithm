#include<stdio.h>
#include<vector>
using namespace std;
vector<int> v[20200], r[20200], k;
int vis[20200], c[20200];

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
	int n, m, a, b, p=1, i;
	scanf("%d %d", &m, &n);
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		a=a>0?rtrue(a):rfalse(-a);
		b=b>0?rtrue(b):rfalse(-b);
		v[a^1].push_back(b);
		v[b^1].push_back(a);
		r[a].push_back(b^1);
		r[b].push_back(a^1);
	}
	for(i=2; i<=n*2+1; i++)
		if(!vis[i]) dfs(i);
	for(i=2; i<=n*2+1; i++) vis[i]=0;
	for(i=k.size()-1; i>=0; i--)
		if(!vis[k[i]]) scc(k[i], p++);
	for(i=1; i<=n; i++)
		if(c[rtrue(i)]==c[rfalse(i)]&&c[rtrue(i)]!=0){
			printf("OTL"); return 0;
		}
	printf("^_^");
}
