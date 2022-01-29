#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int> > v;
vector<int> s;
int n, k, m, t, i, j, d[300100];

int main(){
	scanf("%d %d", &n, &k);
	for(i=1; i<=k; i++){
		scanf("%d", &t);
		v.push_back({t, i});
		if(t>m) m=t;
	} t=0;
	if(m>(n+1)/2){ printf("-1"); return 0; }
	sort(v.begin(), v.end());
	for(i=v.size()-1; i>=0; i--)
		for(j=0; j<v[i].first; j++) s.push_back(v[i].second);
	for(i=0; i<(n+1)/2; i++) d[i*2+1]=s[t++];
	for(i=1; i<=n/2; i++) d[i*2]=s[t++];
	for(i=1; i<=n; i++) printf("%d ", d[i]);
}
