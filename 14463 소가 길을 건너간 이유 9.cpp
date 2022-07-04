#include<stdio.h>
#include<vector>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
vector<pii> v;
vector<int> s;
int d[50500], ans;

int sum(int c, int a, int b, int l, int r){
	if(a>r||b<l||l>r) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return sum(c<<1, a, m, l, r)+sum(c<<1|1, m+1, b, l, r);
}

void upd(int c, int a, int b, int i){
	if(i<a||i>b) return;
	s[c]++;
	if(a!=b){
		int m=(a+b)>>1;
		upd(c<<1, a, m, i);
		upd(c<<1|1, m+1, b, i);
	}
}

int main(){
	int n, t, i;
	scanf("%d", &n);
	s.resize(n*8, 0);
	for(i=1; i<=2*n; i++){
		scanf("%d", &t);
		if(d[t]) v.push_back(pii(d[t], i));
		else d[t]=i;
	}
	sort(v.begin(), v.end());
	for(i=0; i<n; i++){
		ans+=sum(1, 1, n*2, v[i].x+1, v[i].y-1);
		upd(1, 1, n*2, v[i].y);
	}
	printf("%d", ans); 
}
