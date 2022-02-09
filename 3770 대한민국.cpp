#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long int ll;
vector<int> s;


ll sum(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return sum(c*2, a, m, l, r)+sum(c*2+1, m+1, b, l, r);
}

void upd(int c, int a, int b, int t){
	if(a==b){ s[c]+=1; return; }
	int m=(a+b)>>1;
	if(t<=m) upd(c*2, a, m, t);
	else upd(c*2+1, m+1, b, t);
	s[c]=s[c*2]+s[c*2+1];
}

int main(){
	int t, n, m, k, a, b, i, j;
	scanf("%d", &t);
	for(j=1; j<=t; j++){
		ll ans=0;
		vector<pair<int, int> > v; v.push_back({0, 0});
		scanf("%d %d %d", &n, &m, &k); s.resize(m*4);
		for(i=1; i<=k; i++){
			scanf("%d %d", &a, &b);
			v.push_back({a, b});
		}
		sort(v.begin(), v.end());
		for(i=1; i<=k; i++){
			ans+=sum(1, 1, m, v[i].second+1, m);
			upd(1, 1, m, v[i].second);
		}
		printf("Test case %d: %lld\n", j, ans);
		s.clear();
	}
}
