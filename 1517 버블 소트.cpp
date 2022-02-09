#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long int ll;
vector<pair<int, int> > v;
vector<int> s;
ll sum;

ll query(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return query(c*2, a, m, l, r)+query(c*2+1, m+1, b, l, r);
}

void upd(int c, int a, int b, int t){
	if(a==b){ s[c]=1; return; }
	int m=(a+b)>>1;
	if(t<=m) upd(c*2, a, m, t);
	else upd(c*2+1, m+1, b, t);
	s[c]=s[c*2]+s[c*2+1];
}

int main(){
	int n, t, i;
	scanf("%d", &n); s.resize(n*4);
	v.push_back({-1e9-1, 0});
	for(i=1; i<=n; i++){
		scanf("%d", &t);
		v.push_back({t, i});
	}
	sort(v.begin(), v.end());
	for(i=1; i<=n; i++){
		sum+=query(1, 1, n, v[i].second+1, n);
		upd(1, 1, n, v[i].second);
	}
	printf("%lld", sum);
}
