#include<iostream>
#include<vector>
#include<algorithm>
#define x first
#define y second
#define pb push_back
using namespace std;
typedef pair<int, int> pii;
vector<pii> red, blue, ess, ans;
int cnt, ch[1020], p[1020];

int find(int t){ return p[t]<0?t:p[t]=find(p[t]); }

void unite(int a, int b){
	a=find(a); b=find(b);
	if(a!=b){
		if(p[a]>p[b]) swap(a, b);
		p[a]+=p[b]; p[b]=a;
	}
}

int main(){
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m, k, a, b, i; char c;
	cin>>n>>m>>k;
	for(i=1; i<=n; i++) p[i]=-1;
	for(i=0; i<m; i++){
		cin>>c>>a>>b;
		if(c=='R') red.pb({a, b});
		else blue.pb({a, b});
	}
	if(blue.size()<k){ cout<<0; return 0; }
	for(i=0; i<red.size(); i++)
		if(find(red[i].x)!=find(red[i].y)) unite(red[i].x, red[i].y);
	for(i=0; i<blue.size(); i++)
		if(find(blue[i].x)!=find(blue[i].y)){
			unite(blue[i].x, blue[i].y);
			ess.pb(blue[i]); cnt++;
		}
	for(i=1; i<=n; i++){ ch[i]=p[i]<0; p[i]=-1; }
	if(count(ch+1, ch+n+1, 1)>1){ cout<<0; return 0; }
	for(i=0; i<ess.size(); i++){
		ans.pb(ess[i]);
		unite(ess[i].x, ess[i].y);
	}
	for(i=0; i<blue.size(); i++){
		if(cnt>=k) break;
		if(find(blue[i].x)!=find(blue[i].y)){
			ans.pb(blue[i]);
			unite(blue[i].x, blue[i].y);
			cnt++;
		}
	}
	if(cnt!=k){ cout<<0; return 0; }
	for(i=0; i<red.size(); i++)
		if(find(red[i].x)!=find(red[i].y)){
			ans.pb(red[i]);
			unite(red[i].x, red[i].y);
		}
	for(i=0; i<n-1; i++) cout<<ans[i].x<<' '<<ans[i].y<<'\n';
}
