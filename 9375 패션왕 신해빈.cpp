#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int main(){
	int t, n, i;
	cin>>t;
	while(t--){
		int ans=1;
		string a, b;
		vector<string> v;
		map<string, int> m;
		cin>>n;
		for(i=0; i<n; i++){
			cin>>a>>b;
			if(m.count(b)) m[b]++;
			else{ v.push_back(b); m.insert({b, 1}); }
		}
		for(i=0; i<v.size(); i++) ans*=m[v[i]]+1;
		cout<<ans-1<<"\n";
	}
}
