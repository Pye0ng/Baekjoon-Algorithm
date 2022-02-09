#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> s;

bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.first==b.first) return a.second>b.second;
	else return a.first<b.first;
}

int mx(int c, int a, int b, int l, int r){
	if(a>r||b<l) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return max(mx(c<<1, a, m, l, r), mx(c<<1|1, m+1, b, l, r));
}

void upd(int c, int a, int b, int i, int t){
	if(i<a||i>b) return;
	s[c]=max(s[c], t);
	if(a==b) return;
	int m=(a+b)>>1;
	upd(c<<1, a, m, i, t);
	upd(c<<1|1, m+1, b, i, t);
}

int main(){
	int t, n, k, p, q, i, j;
	scanf("%d", &t); 
	for(i=1; i<=t; i++){
		vector<pair<int, int> > v;
		scanf("%d %d", &n, &k); s.resize(n*4);
		q=1<<int(ceil(log2(n)));
		for(j=1; j<=n; j++){
			scanf("%d", &p);
			v.push_back({p, j});
		}
		sort(v.begin(), v.end(), cmp);
		for(j=0; j<n; j++){
			p=v[j].second>1?mx(1, 1, q, 1, v[j].second-1):0;
			upd(1, 1, q, v[j].second, p+1);
		}
		printf("Case #%d\n%d\n", i, s[1]>=k); s.clear();
	}
}
