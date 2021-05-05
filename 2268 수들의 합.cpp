#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
typedef long long int ll;
vector<ll> s;
ll n, m, k, d[1000010];
bool ch;

ll sgmnt(int nw, int a, int b){
	if(a==b) return s[nw]=d[a];
	int m=(a+b)/2;
	s[nw]=sgmnt(nw*2, a, m)+sgmnt(nw*2+1, m+1, b);
	return s[nw];
}

ll sum(int nw, int a, int b, int p, int q){
	if(p>b||q<a) return 0;
	if(p<=a&&b<=q) return s[nw];
	int m=(a+b)/2;
	return sum(nw*2, a, m, p, q)+sum(nw*2+1, m+1, b, p, q);
}

void udt(int nw, int a, int b, int index, ll df){
	if(index<a||index>b) return;
	s[nw]+=df;
	if(a!=b){
		int m=(a+b)/2;
		udt(nw*2, a, m, index, df);
		udt(nw*2+1, m+1, b, index, df);
	}
}

int main(){
	ll x, y;
	scanf("%lld %lld", &n, &m);
	s.resize(4000100);
	sgmnt(1, 1, n);
	while(m--){
		scanf("%d %lld %lld", &ch, &x, &y);
		if(ch){
			ll df=y-d[x];
			d[x]=y;
			udt(1, 1, n, x, df);
		}
		else if(x<y) printf("%lld\n", sum(1, 1, n, x, y));
		else printf("%lld\n", sum(1, 1, n, y, x));
	}
}
