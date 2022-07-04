#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef pair<int, int> pii;
vector<pii> v;
vector<int> s;
map<string, int> m;

int sum(int c, int a, int b, int l, int r){
	if(a>r||b<l||l>r) return 0;
	if(l<=a&&b<=r) return s[c];
	int m=a+b>>1;
	return sum(c<<1, a, m, l, r)+sum(c<<1|1, m+1, b, l, r);
}

void upd(int c, int a, int b, int i){
	if(i<a||i>b) return;
	s[c]++;
	if(a!=b){
		int m=a+b>>1;
		upd(c<<1, a, m, i);
		upd(c<<1|1, m+1, b, i);
	}
}

int main(){
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, i;
	long long int ans=0;
	string t;
	cin>>n;
	while(n){
		for(i=1; i<=n; i++){
			cin>>t;
			m[t]=i;
		}
		for(i=1; i<=n; i++){
			cin>>t;
			v.push_back(pii(m[t], i));
		}
		sort(v.begin(), v.end());
		s.resize(n*4, 0);
		for(i=0; i<n; i++){
			ans+=sum(1, 1, n, v[i].second+1, n);
			upd(1, 1, n, v[i].second);
		}
		s.clear(); v.clear(); m.clear();
		cout<<ans<<"\n";
		ans=0;
		cin>>n;
	}
}
