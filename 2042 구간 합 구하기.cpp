#include<stdio.h>
#include<math.h>
#include<vector>
typedef long long int ll;
using namespace std;
vector<ll> s;
ll n, m, k, d[4000100];

ll sgmnt(int nw, int a, int b){
	if(a==b) return s[nw]=d[a];
	int m=(a+b)/2;
	s[nw]=sgmnt(nw*2, a, m)+sgmnt(nw*2+1, m+1, b);
	return s[nw];
}

ll sgsm(int nw, int a, int b, int p, int q){
	if(p>b||q<a) return 0;
	if(p<=a&&b<=q) return s[nw];
	int m=(a+b)/2;
	return sgsm(nw*2, a, m, p, q)+sgsm(nw*2+1, m+1, b, p, q);
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
	ll hg, sz, c;
	int a, b, i;
	scanf("%d %d %d", &n, &m, &k);
	hg=ceil(log2(n));
	sz=2<<hg;
	s.resize(sz);
	for(i=0; i<n; i++) scanf("%d", &d[i]);
	sgmnt(1, 0, n-1);
	for(i=1; i<=m+k; i++){
		scanf("%d %d %lld", &a, &b, &c);
		if(a==1){
			ll df=c-d[b-1];
			d[b-1]=c;
			udt(1, 0, n-1, b-1, df); 
		}
		else printf("%lld\n", sgsm(1, 1, n, b, c));
	}
}
