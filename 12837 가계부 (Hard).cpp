#include<stdio.h>
#include<vector>
using namespace std;
typedef long long int ll;
vector<ll> s;
ll d[1000100];

ll sum(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)/2;
	return sum(c*2, a, m, l, r)+sum(c*2+1, m+1, b, l, r);
}

void upd(int c, int a, int b, int t, int df){
	if(t<a||t>b) return;
	s[c]+=df;
	if(a!=b){
		int m=(a+b)/2;
		upd(c*2, a, m, t, df);
		upd(c*2+1, m+1, b, t, df);
	}
}

int main(){
	int n, k, i;
	scanf("%d %d", &n, &k);
	s.resize(n*4);
	for(i=0; i<k; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a%2){ d[b]+=c; upd(1, 1, n, b, c); }
		else printf("%lld\n", sum(1, 1, n, b, c));
	}
}
