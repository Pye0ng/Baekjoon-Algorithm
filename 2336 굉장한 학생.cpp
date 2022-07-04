#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct st{ int a, b, c; };
st gr[500100];
vector<st> g;
vector<int> s;

bool cmp(st x, st y){ return x.a<y.a; }

int find(int c, int a, int b, int l, int r){
	if(l>r) return 1e9;
	if(a>r||b<l) return 1e9;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return min(find(c<<1, a, m, l, r), find(c<<1|1, m+1, b, l, r));
}

void upd(int c, int a, int b, int i, int t){
	if(a>i||b<i) return;
	s[c]=min(s[c], t);
	if(a!=b){
		int m=(a+b)>>1;
		upd(c<<1, a, m, i, t);
		upd(c<<1|1, m+1, b, i, t);
	}
}

int main(){
	int n, t, ans=0, i;
	scanf("%d", &n);
	s.resize(n*4, 1e9);
	for(i=1; i<=n; i++){ 
		scanf("%d", &t); 
		gr[t].a=i; 
	}
	for(i=1; i<=n; i++){ 
		scanf("%d", &t); 
		gr[t].b=i; 
	}
	for(i=1; i<=n; i++){ 
		scanf("%d", &t); 
		gr[t].c=i; 
	}
	for(i=1; i<=n; i++) g.push_back(gr[i]);
	sort(g.begin(), g.end(), cmp);
	for(i=0; i<n; i++){
		ans+=find(1, 1, n, 1, g[i].b-1)>g[i].c;
		upd(1, 1, n, g[i].b, g[i].c);
	}
	printf("%d", ans);
}
