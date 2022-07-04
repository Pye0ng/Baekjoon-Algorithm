#include<stdio.h>
#include<vector>
#include<algorithm>
#define x first
#define y second
#define pb push_back
using namespace std;
typedef pair<int, int> pii;
vector<pii> p;
vector<int> s;
pii d[80000];
int v[80000];

bool cmp(pii a, pii b){
	if(a.x==b.x) return a.y>b.y;
	return a.x<b.x;
}

int sum(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return sum(c<<1, a, m, l, r)+sum(c<<1|1, m+1, b, l, r);
}

void upd(int c, int a, int b, int i){
	if(i<a||i>b) return;
	s[c]++;
	if(a!=b){
		int m=(a+b)>>1;
		upd(c<<1, a, m, i);
		upd(c<<1|1, m+1, b, i);
	}
}

int main(){
	int t, n, a, b, i;
	long long int ans;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n); ans=0;
		s.resize(n*4, 0);
		for(i=1; i<=n; i++){
			scanf("%d %d", &a, &b);
			v[i]=a; p.pb(pii(b, i));
		}
		sort(p.begin(), p.end()); a=1;
		for(i=0; i<n; i++){
			d[p[i].y].x=v[p[i].y];
			if(i>0&&p[i].x==p[i-1].x) d[p[i].y].y=d[p[i-1].y].y;
			else d[p[i].y].y=a++;
		}
		sort(d+1, d+n+1, cmp);
		for(i=1; i<=n; i++){
			ans+=sum(1, 1, n, d[i].y, n);
			upd(1, 1, n, d[i].y);
		}
		printf("%lld\n", ans);
		for(i=1; i<=n; i++) d[i]=pii(0, 0);
		s.clear(); p.clear();
	}
}
