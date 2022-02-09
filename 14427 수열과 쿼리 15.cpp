#include<stdio.h>
#include<vector>
#define x first
#define y second
using namespace std;
typedef pair<int, int> p;
vector<p> s;
int d[100100];

p unite(p a, p b){
	if(a.x<b.x) return a;
	else if(a.x==b.x) return a.y<b.y?a:b;
	else return b;
}

p seg(int c, int a, int b){
	if(a==b) return s[c]={d[a], a};
	int m=(a+b)>>1;
	return s[c]=unite(seg(c*2, a, m), seg(c*2+1, m+1, b));	
}

p find(int c, int a, int b, int l, int r){
	if(a>r||b<l) return {1e9+1, 0};
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return unite(find(c*2, a, m, l, r), find(c*2+1, m+1, b, l, r));
}

p upd(int c, int a, int b, int idx, int t){
	if(idx<a||idx>b) return s[c];
	if(a==b) return s[c]={t, idx};
	else{
		int m=(a+b)>>1;
		return s[c]=unite(upd(c*2, a, m, idx, t), upd(c*2+1, m+1, b, idx, t));
	}
}

int main(){
	int n, m, a, b, c, i;
	scanf("%d", &n); s.resize(n*4);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	seg(1, 1, n);
	scanf("%d", &m);
	for(i=0; i<m; i++){
		scanf("%d", &a);
		if(a&1){ 
			scanf("%d %d", &b, &c);
			d[b]=c; upd(1, 1, n, b, c); 
		}
		else printf("%d\n", s[1].y);
	}
}
