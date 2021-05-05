#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int ans, cnt, parent[100010];
bool ch;

typedef struct kruskal{ int a, b, val; }ks;
vector<ks> v;

bool cmp(ks x, ks y){ return x.val<y.val; }

int find(int t){
	if(t==parent[t]) return t;
	else return parent[t]=find(parent[t]);
}

void unity(int x, int y){
	ch=false;
	x=find(x); y=find(y);
	if(x==y) return;
	parent[x]=y;
	ch=true;
	cnt++;
}

int main(){
	int n, m, i;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++) parent[i]=i;
	for(i=0; i<m; i++){
		ks t;
		scanf("%d %d %d", &t.a, &t.b, &t.val);
		v.push_back(t);
	}
	sort(v.begin(), v.end(), cmp);
	for(i=0; i<m; i++){
		if(cnt==n-2) break;
		unity(v[i].a, v[i].b);
		if(ch) ans+=v[i].val;
	}
	printf("%d", ans);
}
