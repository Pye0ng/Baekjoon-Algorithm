#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct con{ int lmx, mmx, rmx, sum; };
vector<con> s;

con upd(int c, int a, int b, int i, int t){
	if(i<a||i>b) return s[c];
	con p, q;
	if(a==b){
		s[c].lmx=s[c].mmx=s[c].rmx=s[c].sum=t;
		return s[c];
	}
	int m=a+b>>1;
	p=upd(c<<1, a, m, i, t);
	q=upd(c<<1|1, m+1, b, i, t);
	s[c].sum=p.sum+q.sum;
	s[c].lmx=max(p.lmx, p.sum+q.lmx);
	s[c].rmx=max(p.rmx+q.sum, q.rmx);
	s[c].mmx=max(max(p.mmx, q.mmx), p.rmx+q.lmx);
	return s[c];
}

con query(int c, int a, int b, int l, int r){
	if(a>r||b<l){
		con init;
		init.sum=0;
		init.lmx=init.rmx=init.mmx=-1e9;
		return init;
	}
	if(l<=a&&b<=r) return s[c];
	int m=a+b>>1;
	con w, p, q;
	p=query(c<<1, a, m, l, r);
	q=query(c<<1|1, m+1, b, l, r);
	w.sum=p.sum+q.sum;
	w.lmx=max(p.lmx, p.sum+q.lmx);
	w.rmx=max(p.rmx+q.sum, q.rmx);
	w.mmx=max(max(p.mmx, q.mmx), p.rmx+q.lmx);
	return w;
}

int main(){
	int n, q, u, v, c, a, b, i;
	scanf("%d %d %d %d", &n, &q, &u, &v);
	con init;
	init.sum=0;
	init.lmx=init.rmx=init.mmx=-1e9;
	s.resize(n*4, init);
	for(i=1; i<=n; i++){
		scanf("%d", &c);
		upd(1, 1, n, i, u*c+v);
	}
	while(q--){
		scanf("%d %d %d", &c, &a, &b);
		if(c) upd(1, 1, n, a, u*b+v);
		else printf("%d\n", query(1, 1, n, a, b).mmx-v);
	}
}
