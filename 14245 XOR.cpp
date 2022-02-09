#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
int p[601000], lz[2000100];
vector<int> s;

int seg(int c, int a, int b){
	if(a==b) return s[c]=p[a];
	int m=(a+b)>>1;
	return s[c]=seg(c*2, a, m)^seg(c*2+1, m+1, b);
}

void prop(int c, int a, int b){
	if((b-a+1)&1) s[c]^=lz[c];
	if(a!=b){ lz[c*2]^=lz[c]; lz[c*2+1]^=lz[c]; }
	lz[c]=0;
}

void upd(int c, int a, int b, int l, int r, int t){
	if(lz[c]!=0) prop(c, a, b);
	if(a>r||b<l) return; 
	if(l<=a&&b<=r){
		lz[c]^=t;
		prop(c, a, b);
		return;
	}
	int m=(a+b)>>1;
	upd(c*2, a, m, l, r, t);
	upd(c*2+1, m+1, b, l, r, t);
	s[c]=s[c*2]^s[c*2+1];
}

int find(int c, int a, int b, int l, int r){
	if(lz[c]!=0) prop(c, a, b);
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return find(c*2, a, m, l, r)^find(c*2+1, m+1, b, l, r);
}

int main(){
	int n, m, a, b, c, d, t, i;
	scanf("%d", &n); s.resize(n*4);
	t=1<<int(ceil(log2(n)));
	for(i=0; i<n; i++) scanf("%d", &p[i]);
	seg(1, 0, t-1); scanf("%d", &m);
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		if(a&1){
			scanf("%d %d", &c, &d);
			upd(1, 0, t-1, b, c, d);
		}
		else printf("%d\n", find(1, 0, t-1, b, b));
	}
}
