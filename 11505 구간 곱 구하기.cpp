#include<stdio.h>
#include<vector>
using namespace std;
typedef long long int ll;
vector<ll> s;
ll d[1000100], M=1e9+7;

ll seg(int c, int a, int b){
	if(a==b) return s[c]=d[a];
	int m=(a+b)>>1;
	return s[c]=((seg(c<<1, a, m)%M)*(seg(c<<1|1, m+1, b)%M))%M;
}

ll upd(int c, int a, int b, int i, ll t){
	if(i<a||i>b) return s[c];
	if(a==b) return s[c]=t;
	int m=(a+b)>>1;
	return s[c]=((upd(c<<1, a, m, i, t)%M)*(upd(c<<1|1, m+1, b, i, t)%M))%M;
}

ll mul(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 1;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return ((mul(c<<1, a, m, l, r)%M)*(mul(c<<1|1, m+1, b, l, r)%M))%M;
}

int main(){
	int n, m, k, i;
	scanf("%d %d %d", &n, &m, &k);
	for(i=1; i<=n; i++) scanf("%lld", &d[i]);
	s.resize(n*4); seg(1, 1, n);
	for(i=0; i<m+k; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a&1){
			ll c;
			scanf("%lld", &c);
			upd(1, 1, n, b, c);
		}
		else{
			int c;
			scanf("%d", &c);
			printf("%lld\n", mul(1, 1, n, b, c));
		}
	}
}
