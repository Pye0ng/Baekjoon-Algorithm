#include<stdio.h>
#include<vector>
using namespace std;
typedef long long int ll;
vector<ll> s;
ll d[1000100];
int n;

ll seg(int c, int a, int b){
	if(a==b) return s[c]=d[a];
	int m=(a+b)/2;
	return s[c]=seg(c*2, a, m)+seg(c*2+1, m+1, b);
}

ll sum(int c, int a, int b, int l, int r){
	if(l>b||r<a) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)/2;
	return sum(c*2, a, m, l, r)+sum(c*2+1, m+1, b, l, r);
}

void upd(int c, int a, int b, int t, ll df){
	if(t<a||b<t) return;
	s[c]+=df;
	if(a!=b){
		int m=(a+b)/2;
		upd(c*2, a, m, t, df);
		upd(c*2+1, m+1, b, t, df);
	}
}

int main(){
	int m, k, a, b, i;
	ll c;
	scanf("%d %d %d", &n, &m, &k);
	for(i=1; i<=n; i++) scanf("%lld", &d[i]);
	s.resize(4000400);
	seg(1, 1, n);
	for(i=0; i<m+k; i++){
		scanf("%d %d %lld", &a, &b, &c);
		if(a%2){
			ll df=c-d[b]; d[b]=c;
			upd(1, 1, n, b, df);
		}
		else printf("%lld\n", sum(1, 1, n, b, c));
	}
}
