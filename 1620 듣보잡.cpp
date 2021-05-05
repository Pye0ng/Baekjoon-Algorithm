#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cctype>
using namespace std;
vector<pair<string, int> > v1;
vector<pair<int, string> > v2;
string s;
int n, m;

int find(){
	int m, st=0, ed=n-1;
	while(st<=ed){
		m=(st+ed)/2;
		if(v1[m].first==s) return m;
		else if(v1[m].first>s) ed=m-1;
		else st=m+1;
	}
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int i;
	cin>>n>>m;
	for(i=1; i<=n; i++){
		cin>>s;
		v1.push_back({s, i});
		v2.push_back({i, s});
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for(i=1; i<=m; i++){
		cin>>s;
		if(isdigit(s[0])) cout<<v2[stoi(s)-1].second<<"\n";
		else cout<<v1[find()].second<<"\n";
	}
}
