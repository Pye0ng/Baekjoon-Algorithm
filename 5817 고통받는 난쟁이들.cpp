#include<stdio.h>
#include<vector>
#include<algorithm>
#define x first
#define y second
using namespace std;
vector<int> mn, mx;
int d[200200], p[200200];

int seg_min(int c, int a, int b){
	if(a==b) return mn[c]=d[a];
	int m=(a+b)>>1;
	return mn[c]=min(seg_min(c<<1, a, m), seg_min(c<<1|1, m+1, b));
}

int seg_max(int c, int a, int b){
	if(a==b) return mx[c]=d[a];
	int m=(a+b)>>1;
	return mx[c]=max(seg_max(c<<1, a, m), seg_max(c<<1|1, m+1, b));
}

int find_min(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 2000000;
	if(l<=a&&b<=r) return mn[c];
	int m=(a+b)>>1;
	return min(find_min(c<<1, a, m, l, r), find_min(c<<1|1, m+1, b, l, r));
}

int find_max(int c, int a, int b, int l, int r){
	if(a>r||b<l) return -1;
	if(l<=a&&b<=r) return mx[c];
	int m=(a+b)>>1;
	return max(find_max(c<<1, a, m, l, r), find_max(c<<1|1, m+1, b, l, r));
}

int upd_min(int c, int a, int b, int i, int t){
	if(i<a||i>b) return mn[c];
	if(a==b) return mn[c]=t;
	int m=(a+b)>>1;
	return mn[c]=min(upd_min(c<<1, a, m, i, t), upd_min(c<<1|1, m+1, b, i, t));
}

int upd_max(int c, int a, int b, int i, int t){
	if(i<a||i>b) return mx[c];
	if(a==b) return mx[c]=t;
	int m=(a+b)>>1;
	return mx[c]=max(upd_max(c<<1, a, m, i, t), upd_max(c<<1|1, m+1, b, i, t));
}

int main(){
	int n, m, a, b, c, t, i;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%d", &c);
		d[c]=i; p[i]=c;
	}
	mn.resize(n*4, 200001); mx.resize(n*4, 0);
	seg_min(1, 1, n); seg_max(1, 1, n);
	while(m--){
		scanf("%d %d %d", &c, &a, &b);
		if(c&1){
			upd_min(1, 1, n, p[a], d[p[b]]);
			upd_min(1, 1, n, p[b], d[p[a]]);
			upd_max(1, 1, n, p[a], d[p[b]]);
			upd_max(1, 1, n, p[b], d[p[a]]);
			swap(d[p[a]], d[p[b]]);
			swap(p[a], p[b]);
		}
		else printf("%s\n", b-a==find_max(1, 1, n, a, b)-find_min(1, 1, n, a, b)?"YES":"NO");
	}
}
