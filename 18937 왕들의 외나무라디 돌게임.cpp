#include<iostream>
#include<string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, t, ans=0, i; string s;
	cin>>n;
	for(i=1; i<=n; i++){
		cin>>t;
		ans^=(t-2);
	}
	cin>>s;
	if(!ans) s=(s=="Whiteking"?"Blackking":"Whiteking");
	cout<<s;
}
