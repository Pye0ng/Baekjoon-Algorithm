#include<iostream>
#include<string>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string s;
	int n, cnt=0, i;
	cin>>s;
	while(s.length()!=1){
		n=0; cnt++;
		for(i=0; i<s.length(); i++) n+=s[i]-'0';
		s=to_string(n);
	}
	n=stoi(s);
	cout<<cnt<<"\n";
	if(n%3) cout<<"NO";
	else cout<<"YES";
}
