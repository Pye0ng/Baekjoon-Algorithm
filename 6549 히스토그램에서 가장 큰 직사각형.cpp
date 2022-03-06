#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long int ll;
vector<int> s;
int n, d[100100];

int seg(int c, int a, int b){
	if(a==b) return s[c]=a;
	int m=(a+b)>>1, x, y;
	x=seg(c<<1, a, m); y=seg(c<<1|1, m+1, b);
	return s[c]=d[x]<d[y]?x:y;
}

int find(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1, x, y;
	x=find(c<<1, a, m, l, r); y=find(c<<1|1, m+1, b, l, r);
	return d[x]<d[y]?x:y;
}

ll solve(int a, int b){
	int i=find(1, 1, n, a, b);
	ll t=(ll)(b-a+1)*d[i];
	if(a<=i-1) t=max(t, solve(a, i-1));
	if(b>=i+1) t=max(t, solve(i+1, b));
	return t;
}

int main(){
	int i; scanf("%d", &n); d[0]=1e9+1;
	while(n){
		s.resize(n*4);
		for(i=1; i<=n; i++) scanf("%d", &d[i]);
		seg(1, 1, n); printf("%lld\n", solve(1, n));
		s.clear(); for(i=1; i<=n; i++) d[i]=0;
		scanf("%d", &n);
	}
}
