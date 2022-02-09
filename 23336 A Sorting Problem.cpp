#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
vector<pair<ll, int> > v;
vector<ll> s;
ll ans;

void upd(int c, int a, int b, int t){
	if(t<a||t>b) return;
	s[c]++; if(a==b) return;
	int m=(a+b)>>1;
	upd(c<<1, a, m, t);
	upd(c<<1|1, m+1, b, t);
}

long long int sum(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return sum(c<<1, a, m, l, r)+sum(c<<1|1, m+1, b, l, r);
}

int main(){
	int n, i; ll t;
	scanf("%d", &n); s.resize(n*4);
	for(i=1; i<=n; i++){
		scanf("%lld", &t);
		v.push_back({t, i});
	}
	sort(v.begin(), v.end());
	t=1<<int(ceil(log2(n)));
	for(i=0; i<n; i++){
		ans+=sum(1, 1, t, v[i].second+1, n);
		upd(1, 1, t, v[i].second);
	}
	printf("%lld", ans);
}
