#include<stdio.h>
#include<vector>
using namespace std;
vector<int> s, lz;
int d[100100];

void prop(int c, int a, int b){
	if(!lz[c]) return;
	s[c]+=(b-a+1)*lz[c];
	if(a!=b){ lz[c<<1]+=lz[c]; lz[c<<1|1]+=lz[c]; }
	lz[c]=0;
}

void upd(int c, int a, int b, int l, int r, int t){
	prop(c, a, b);
	if(a>r||b<l) return;
	if(l<=a&&b<=r){ lz[c]+=t; prop(c, a, b); return; }
	int m=(a+b)>>1;
	upd(c<<1, a, m, l, r, t);
	upd(c<<1|1, m+1, b, l, r, t);
	s[c]=s[c<<1]+s[c<<1|1];
}

int sum(int c, int a, int b, int l, int r){
	prop(c, a, b);
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return sum(c<<1, a, m, l, r)+sum(c<<1|1, m+1, b, l, r);
}

int main(){
	int n, a, b, p, q, m=100000; 
	scanf("%d", &n); s.resize(m*4); lz.resize(m*4);
	while(n--){
		scanf("%d %d", &a, &b);
		p=sum(1, 1, m, a, a); q=sum(1, 1, m, b, b);
		printf("%d\n", p+q);
		upd(1, 1, m, a, a, -p);
		upd(1, 1, m, b, b, -q);
		if(b>a+1) upd(1, 1, m, a+1, b-1, 1);
	}
}
