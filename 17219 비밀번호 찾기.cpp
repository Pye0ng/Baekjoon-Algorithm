#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string, string> m;
int n, k, i;
string a, b, c;

int main(){
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for(i=0; i<n; i++){
		cin>>a>>b;
		m.insert({a, b});
	}
	for(i=0; i<k; i++){
		cin>>c;
		cout<<m[c]<<"\n";
	}
}
