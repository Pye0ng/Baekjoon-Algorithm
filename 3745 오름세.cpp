#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, i;
	while(cin>>n){
		int d[100010];
		vector<int> v;
		v.push_back(0);
		for(i=1; i<=n; i++) cin>>d[i];
		for(i=1; i<=n; i++){
			if(d[i]>v.back()) v.push_back(d[i]);
			else{
				auto it=lower_bound(v.begin(), v.end(), d[i]);
				*it=d[i];
			}
		}
		cout<<v.size()-1<<"\n";
	}
}
