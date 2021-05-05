#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string s[10010];

string add(string a, string b){
	int k=0; string c;
	while(!a.empty()||!b.empty()||k){
		if(!a.empty()){
			k+=a.back()-'0';
			a.pop_back();
		}
		if(!b.empty()){
			k+=b.back()-'0';
			b.pop_back();
		}
		c.push_back((k%10)+'0');
		k/=10;
	}
	reverse(c.begin(), c.end());
	return c;
}


int main(){
	int n, i;
	s[0]="0"; s[1]="1";
	cin>>n;
	for(i=2; i<=n; i++) s[i]=add(s[i-1],s[i-2]);
	cout<<s[n];
}
