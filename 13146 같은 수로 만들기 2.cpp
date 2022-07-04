#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
vector<int> s;
ll d[1001000];
int n; 

int seg(int c, int a, int b){
	if(a==b) return s[c]=a;
	int m=a+b>>1, p, q;
	p=seg(c<<1, a, m);
	q=seg(c<<1|1, m+1, b);
	return s[c]=d[p]>d[q]?p:q;
}

int find(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=a+b>>1, p, q;
	p=find(c<<1, a, m, l, r);
	q=find(c<<1|1, m+1, b, l, r);
	return d[p]>d[q]?p:q;
}

ll solve(int a, int b, ll p){
	int i=find(1, 1, n, a, b); ll t=p-d[i];
	if(a<=i-1) t+=solve(a, i-1, d[i]);
	if(b>=i+1) t+=solve(i+1, b, d[i]);
	return t;
}

int main(){
	scanf("%d", &n);
	s.resize(n*4);
	for(int i=1; i<=n; i++) scanf("%lld", &d[i]);
	seg(1, 1, n);
	printf("%lld", solve(1, n, d[find(1, 1, n, 1, n)]));
}
