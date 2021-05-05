#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, i, j;
	string a, b;
	cin>>n;
	while(n!=0){
		vector<pair<string, string> > v;
		for(i=1; i<=n; i++){
			cin>>a;
			b=a;
			for(j=0; j<a.length(); j++)
				if(a[j]<91) a[j]+=32;
			v.push_back({a, b});
		}
		sort(v.begin(), v.end());
		cout<<v.front().second<<"\n";
		cin>>n;
	}
}
