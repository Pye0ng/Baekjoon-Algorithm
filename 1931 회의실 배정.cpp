#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int, int> > v;
int cnt, s;

bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.second==b.second) return a.first<b.first;
	else return a.second<b.second;
}

int main(){
	int n, a, b, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d %d", &a, &b);
		v.push_back({a, b});
	}
	sort(v.begin(), v.end(), cmp);
	for(i=0; i<n; i++){
		if(s<=v[i].first){
			s=v[i].second;
			cnt++;
		}
	}
	printf("%d", cnt);
}
