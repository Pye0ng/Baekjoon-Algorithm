#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;
typedef pair<int, int> p;
vector<p> s;
int d[50100];

p seg(int c, int a, int b){
	if(a==b) return s[c]={d[a], d[a]};
	int m=(a+b)/2;
	p l=seg(c*2, a, m), r=seg(c*2+1, m+1, b);
	return s[c]={min(l.x, r.x), max(l.y, r.y)};
}	

p find(int c, int a, int b, int l, int r){
	if(a>r||b<l) return {1e7+1, 0};
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)/2;
	p x=find(c*2, a, m, l, r), y=find(c*2+1, m+1, b, l, r);
	return {min(x.x, y.x), max(x.y, y.y)};
}

int main(){
	int n, m, a, b, i;
	scanf("%d %d", &n, &m); s.resize(n*4);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	seg(1, 1, n);
	while(m--){
		scanf("%d %d", &a, &b);
		p t=find(1, 1, n, a, b);
		printf("%d\n", t.y-t.x);
	}
}
