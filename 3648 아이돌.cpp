#include<stdio.h>
#include<vector>
using namespace std;
vector<int> d[2020], r[2020], k;
int v[2020], c[2020];

int rtrue(int t){ return t<<1 ; }
int rfalse(int t){ return t<<1|1; }

void dfs(int t){
	v[t]=1;
	for(int i=0; i<d[t].size(); i++)
		if(!v[d[t][i]]) dfs(d[t][i]);
	k.push_back(t);
}

void rdfs(int t, int a){
	v[t]=1; c[t]=a;
	for(int i=0; i<r[t].size(); i++)
		if(!v[r[t][i]]) rdfs(r[t][i], a);
}

int main(){
	int n, m, a, b, i;
	while(scanf("%d %d", &n, &m)!=EOF){
		for(i=0; i<=m; i++){
			if(i==0) a=b=1;
			else scanf("%d %d", &a, &b);
			a=a>0?rtrue(a):rfalse(-a);
			b=b>0?rtrue(b):rfalse(-b);
			d[a^1].push_back(b);
			d[b^1].push_back(a);
			r[a].push_back(b^1);
			r[b].push_back(a^1);
		}
		for(i=2; i<=n*2+1; i++)	
			if(!v[i]) dfs(i);
		for(i=2; i<=n*2+1; i++) v[i]=0;
		a=1; b=0;
		for(i=k.size()-1; i>=0; i--)
			if(!v[k[i]]) rdfs(k[i], a++);
		for(i=1; i<=n; i++)
			if(c[rtrue(i)]==c[rfalse(i)])  b=1;
		printf("%s\n", b?"no":"yes");
		for(i=2; i<=n*2+1; i++){
			d[i].clear();
			r[i].clear();
			v[i]=0; c[i]=0;
		}
		k.clear();
	}
}
