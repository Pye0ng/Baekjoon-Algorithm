#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> p[42], r[42], k;
vector<pair<int, int> > q;
int v[42], c[42], d[22];

int rtrue(int t){ return t<<1; }
int rfalse(int t){ return t<<1|1; }

void dfs(int t){
	v[t]=1;
	for(int i=0; i<p[t].size(); i++)
		if(!v[p[t][i]]) dfs(p[t][i]);
	k.push_back(t);
}

void rdfs(int t, int a){
	v[t]=1; c[t]=a;
	for(int i=0; i<r[t].size(); i++)
		if(!v[r[t][i]]) rdfs(r[t][i], a);
}

int main(){
	int n, m, a, b, t=1, i;
	scanf("%d %d", &n, &m);
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		a=a>0?rtrue(a):rfalse(-a);
		b=b>0?rtrue(b):rfalse(-b);
		p[a^1].push_back(b);
		p[b^1].push_back(a);
		r[a].push_back(b^1);
		r[b].push_back(a^1);
	}
	for(i=2; i<=n*2+1; i++)
		if(!v[i]) dfs(i);
	for(i=2; i<=n*2+1; i++) v[i]=0;
	for(i=k.size()-1; i>=0; i--)
		if(!v[k[i]]) rdfs(k[i], t++);
	for(i=1; i<=n; i++){
		if(c[rtrue(i)]==c[rfalse(i)]){
			printf("0");
			return 0;
		}
		d[i]=-1;
	}
	printf("1\n");
	for(i=2; i<=n*2+1; i++) q.push_back({c[i], i});
	sort(q.begin(), q.end());
	for(i=0; i<q.size(); i++){
		t=q[i].second;
		if(d[t/2]==-1) d[t/2]=t%2;
	}
	for(i=1; i<=n; i++) printf("%d ", d[i]);
}
