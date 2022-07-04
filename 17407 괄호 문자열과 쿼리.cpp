#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
vector<int> s;
char p[100100];
int sm, ans, d[100100], lz[400100];

int seg(int c, int a, int b){
	if(a==b) return s[c]=d[a];
	int m=(a+b)>>1;
	return s[c]=min(seg(c<<1, a, m), seg(c<<1|1, m+1, b));
}

void prop(int c, int a, int b){
	if(lz[c]==0) return;
	s[c]+=lz[c];
	if(a!=b){ lz[c<<1]+=lz[c]; lz[c<<1|1]+=lz[c]; }
	lz[c]=0;
}

void upd(int c, int a, int b, int l, int r, int t){
	prop(c, a, b);
	if(a>r||b<l) return;
	if(l<=a&&b<=r){
		lz[c]+=t;
		prop(c, a, b);
		return;
	}
	int m=(a+b)>>1;
	upd(c<<1, a, m, l, r, t);
	upd(c<<1|1, m+1, b, l, r, t);
	s[c]=min(s[c<<1], s[c<<1|1]);
}

int main(){
	int n=0, m, t, k, i;
	scanf("%s", p);
	for(i=0; p[i]!='\0'; i++){
		d[i+1]=d[i]+(p[i]=='('?1:-1);
		n++; sm+=d[i+1]-d[i];
	}
	s.resize(n*4);
	seg(1, 1, n);
	scanf("%d", &m);
	while(m--){
		scanf("%d", &t);
		k=p[t-1]=='('?-2:2; sm+=k;
		p[t-1]=p[t-1]=='('?')':'(';
		upd(1, 1, n, t, n, k);
		ans+=(s[1]>=0&&sm==0);
	}
	printf("%d", ans);
}
