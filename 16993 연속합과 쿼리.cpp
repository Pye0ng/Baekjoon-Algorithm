#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
struct con{ ll lmx, rmx, mmx; };
ll d[100100], t[100100];
vector<con> s;

con seg(int c, int a, int b){
	if(a==b){
		con w; w.lmx=w.rmx=w.mmx=t[a];
		return s[c]=w;
	}
	int m=(a+b)>>1;
	con p=seg(c<<1, a, m), q=seg(c<<1|1, m+1, b), w;
	w.lmx=max(p.lmx, d[m]-d[a-1]+q.lmx);
	w.rmx=max(p.rmx+d[b]-d[m], q.rmx);
	w.mmx=max(max(p.mmx, q.mmx), p.rmx+q.lmx);
	return s[c]=w;
}

con query(int c, int a, int b, int l, int r){
	if(a>r||b<l){
		con w; w.lmx=w.rmx=w.mmx=-1e16;
		return w;
	}
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	con p=query(c<<1, a, m, l, r), q=query(c<<1|1, m+1, b, l, r), w;
	w.lmx=max(p.lmx, d[m]-d[a-1]+q.lmx);
	w.rmx=max(p.rmx+d[b]-d[m], q.rmx);
	w.mmx=max(max(p.mmx, q.mmx), p.rmx+q.lmx);
	return w;
}

int main(){
	int n, m, a, b, i;
	scanf("%d", &n);
	s.resize(n*4);
	for(i=1; i<=n; i++){
		scanf("%lld", &t[i]);
		d[i]=d[i-1]+t[i];
	}
	seg(1, 1, n);
	scanf("%d", &m);
	while(m--){
		scanf("%d %d", &a, &b);
		printf("%lld\n", query(1, 1, n, a, b).mmx);
	}
}
