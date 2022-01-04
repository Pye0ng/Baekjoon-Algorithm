#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;
map<string, int> m; 
vector<string> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, p, i;
	string s, t;
	
	cin>>n;
	while(n--){
		t=""; p=0;
		cin>>s;
		for(i=0; i<s.length(); i++){
			if(p) t+=s[i];
			if(s[i]=='.') p=1;
		}
		if(m.count(t)==0){ m.insert({t, 1}); v.push_back(t); }
		else m[t]++;
	}
	sort(v.begin(), v.end());
	for(i=0; i<v.size(); i++)
		cout<<v[i]<<" "<<m[v[i]]<<"\n";
}
