#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
#define pb push_back
using namespace std;
typedef pair<int, int> pr;
vector<int> g[6030], r[6030], k, ans;
vector<pr> p, q;
int n, v[6030];

int con(int t){ return t>=3*n?t-3*n:t+3*n; }

void edge(int a, int b){
	g[a].push_back(b);
	g[con(b)].push_back(con(a));
	r[b].push_back(a);
	r[con(a)].push_back(con(b));
}

int ccw(pr a, pr b, pr c){
	int t=a.x*b.y+b.x*c.y+c.x*a.y-a.y*b.x-b.y*c.x-c.y*a.x;
	if(t>0) return 1;
	else if(t<0) return -1;
	else return 0;
}

int crs(pr a, pr b, pr c, pr d){
	int ab=ccw(a, b, c)*ccw(a, b, d), cd=ccw(c, d, a)*ccw(c, d, b);
	if(ab==0&&cd==0){
		if(a>b) swap(a, b);
		if(c>d) swap(c, d);
		return c<=b&&a<=d;
	}
	return ab<=0&&cd<=0;
}

void dfs(int t){
	v[t]=1;
	for(int i=0; i<g[t].size(); i++)
		if(!v[g[t][i]]) dfs(g[t][i]);
	k.pb(t);
}

void rdfs(int t, int c){
	v[t]=c;
	for(int i=0; i<r[t].size(); i++)
		if(!v[r[t][i]]) rdfs(r[t][i], c);
}

int main(){
	int i, j; pr a, b;
	scanf("%d", &n);
	for(i=0; i<3*n; i++){
		scanf("%d %d %d %d", &a.x, &a.y, &b.x, &b.y);
		p.pb(a); q.pb(b);
	}
	for(i=0; i<n; i++){
		edge(3*i, con(3*i+1));
		edge(3*i, con(3*i+2));
		edge(3*i+1, con(3*i));
		edge(3*i+1, con(3*i+2));
		edge(3*i+2, con(3*i));
		edge(3*i+2, con(3*i+1));
	}
	for(i=0; i<3*n; i++)
		for(j=i+1; j<3*n; j++)
			if(crs(p[i], q[i], p[j], q[j])) edge(con(i), j);
	for(i=0; i<6*n; i++)
		if(!v[i]) dfs(i);
	for(i=0; i<6*n; i++) v[i]=0;
	j=1;
	for(i=k.size()-1; i>=0; i--)
		if(!v[k[i]]) rdfs(k[i], j++);
	for(i=0; i<3*n; i++){
		if(v[i]==v[con(i)]){
			printf("-1");
			return 0;
		}
		if(v[i]>v[con(i)]) ans.pb(i+1);
	}
	printf("%d\n", ans.size());
	for(i=0; i<ans.size(); i++) printf("%d ", ans[i]);
}
