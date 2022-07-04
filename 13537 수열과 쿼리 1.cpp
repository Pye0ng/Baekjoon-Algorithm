#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> mst[400200];
int k, d[100100];

void set(int c, int a, int b){
	vector<int> &v=mst[c];
	if(a==b){
		v.push_back(d[a]);
		return;
	}
	int m=a+b>>1;
	set(c<<1, a, m);
	set(c<<1|1, m+1, b);
	vector<int> &l=mst[c<<1], &r=mst[c<<1|1];
	v.resize(l.size()+r.size());
	merge(l.begin(), l.end(), r.begin(), r.end(), v.begin());
}

int query(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return mst[c].size()-(upper_bound(mst[c].begin(), mst[c].end(), k)-mst[c].begin());
	int m=a+b>>1;
	return query(c<<1, a, m, l, r)+query(c<<1|1, m+1, b, l, r);
}

int main(){
	int n, m, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	set(1, 1, n);
	scanf("%d", &m);
	while(m--){
		int s, e;
		scanf("%d %d %d", &s, &e, &k);
		printf("%d\n", query(1, 1, n, s, e));
	}
}
