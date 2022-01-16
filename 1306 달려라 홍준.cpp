#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> s;
int d[1000100];

int seg(int c, int a, int b){
	if(a==b) return s[c]=d[a];
	int m=(a+b)/2;
	return s[c]=max(seg(c*2, a, m), seg(c*2+1, m+1, b));
}

int lux(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)/2;
	return max(lux(c*2, a, m, l, r), lux(c*2+1, m+1, b, l, r));
}

int main(){
	int n, m, i;
	scanf("%d %d", &n, &m); s.resize(n*4);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	seg(1, 1, n); 
	for(i=m; i<=n-m+1; i++) printf("%d ", lux(1, 1, n, max(1, i-m+1), min(n, i+m-1)));
}
