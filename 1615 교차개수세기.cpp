#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int> > v;
vector<int> s;
long long int ans;

long long int sum(int c, int a, int b, int l, int r){
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
	int n, m, a, b, i;
	scanf("%d %d", &n, &m); s.resize(n*4); 
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		v.push_back({a, b});
	}
	v.push_back({0, 0});
	sort(v.begin(), v.end()); 
	for(i=1; i<=m; i++){
		ans+=sum(1, 1, n, v[i].second+1, n);
		upd(1, 1, n, v[i].second);
	}
	printf("%lld", ans);
}
