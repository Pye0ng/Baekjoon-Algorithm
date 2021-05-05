#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
vector<string> a, v;
string s;
int n, m;

void find(){
	int m, p=0, q=n-1;
	while(p<=q){
		m=(p+q)/2;
		if(s==a[m]){
			v.push_back(s);
			return;
		}
		else if(s>a[m]) p=m+1;
		else q=m-1;	
	}
}

int main(){
	int i;
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(i=0; i<n; i++){
		cin>>s;
		a.push_back(s);
	}
	sort(a.begin(), a.end());
	for(i=0; i<m; i++){
		cin>>s;
		find();
	}
	sort(v.begin(), v.end());
	cout<<v.size()<<"\n";
	for(i=0; i<v.size(); i++) cout<<v[i]<<"\n";
}
