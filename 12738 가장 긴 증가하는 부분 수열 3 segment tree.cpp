#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int> > v;
vector<int> s;

bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.first<b.first) return 1;
	else if(a.first==b.first) return a.second>b.second;
	else return 0;
}

int find(int c, int a, int b, int l, int r){
	if(a>r||b<l) return -1e9-1;
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)>>1;
	return max(find(c<<1, a, m, l, r), find(c<<1|1, m+1, b, l, r));
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
	int n, p, t, i;
	scanf("%d", &n); s.resize(n*4);
	for(i=1; i<=n; i++){
		scanf("%d", &t);
		v.push_back({t, i});
	}
	t=1<<int(ceil(log2(n)));
	sort(v.begin(), v.end(), cmp);
	for(i=0; i<n; i++){
		p=v[i].second>1?find(1, 1, t, 1, v[i].second-1):0;
		upd(1, 1, t, v[i].second, p+1);
	}
	printf("%d", s[1]);
}
