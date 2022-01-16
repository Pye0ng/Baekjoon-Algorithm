#include<stdio.h>
#include<vector>
using namespace std;
vector<int> s;
int d[100100];

int seg(int c, int a, int b){
	if(a==b) return s[c]=d[a];
	int m=(a+b)/2;
	int l=seg(c*2, a, m), r=seg(c*2+1, m+1, b);
	return s[c]=l<r?l:r;
}

int mn(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 1e9+7;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)/2;
	int p=mn(c*2, a, m, l, r), q=mn(c*2+1, m+1, b, l, r);
	return p<q?p:q;
}

int main(){
	int n, m, a, b, i;
	scanf("%d %d", &n, &m);
	s.resize(n*4);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	seg(1, 1, n);
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		printf("%d\n", mn(1, 1, n, a, b));
	}
}
