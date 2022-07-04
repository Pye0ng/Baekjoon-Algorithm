#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
#define pb push_back
using namespace std;
typedef pair<int, int> pii;
vector<pii> red, blue, ess, ans;
int cnt, ch[20100], p[20100];

int find(int t){ return p[t]<0?t:p[t]=find(p[t]); }

void unite(int a, int b){
	a=find(a); b=find(b);
	if(a!=b){
		if(p[a]>p[b]) swap(a, b);
		p[a]+=p[b]; p[b]=a;
	}
}

bool eq(pii t){ return find(t.x)!=find(t.y); }

int main(){
	int n, m, k, a, b, c, i;
	scanf("%d %d %d", &n, &m, &k);
	for(i=1; i<=n; i++) p[i]=-1;
	for(i=0; i<m; i++){
		scanf("%d %d %d", &a, &b, &c);
		if(c) red.pb({a, b});
		else blue.pb({a, b});
	}
	if(blue.size()<k){ printf("no solution"); return 0; }
	for(i=0; i<red.size(); i++)
		if(eq(red[i])) unite(red[i].x, red[i].y);
	for(i=0; i<blue.size(); i++)
		if(eq(blue[i])){
			unite(blue[i].x, blue[i].y);
			ess.pb(blue[i]); cnt++;
		}
	for(i=1; i<=n; i++){ ch[i]=p[i]<0; p[i]=-1; }
	if(count(ch+1, ch+n+1, 1)>1){ printf("no solution"); return 0; }
	for(i=0; i<ess.size(); i++){
		ans.pb(ess[i]);
		unite(ess[i].x, ess[i].y);
	}
	for(i=0; i<blue.size(); i++){
		if(cnt>=k) break;
		if(eq(blue[i])){
			ans.pb(blue[i]); cnt++;
			unite(blue[i].x, blue[i].y);
		}
	}
	if(cnt!=k){ printf("no solution"); return 0; }
	for(i=0; i<red.size(); i++)
		if(eq(red[i])){
			ans.pb(red[i]);
			unite(red[i].x, red[i].y);
		}
	for(i=0; i<n-1; i++) printf("%d %d %d\n", ans[i].x, ans[i].y, i>=k);
}
