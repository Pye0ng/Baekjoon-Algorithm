#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string sum(string a, string b){
	string s=""; int t=0;
	while(!a.empty()||!b.empty()||t){
		if(!a.empty()){
			t+=a.back()-'0';
			a.pop_back();
		}
		if(!b.empty()){
			t+=b.back()-'0';
			b.pop_back();
		}
		s.push_back((t%10)+'0');
		t/=10;
	}
	reverse(s.begin(), s.end());
	return s;
}

int main(){
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string a, b, na, nb, xa, xb;
	int i; cin>>a>>b; na=xa=a; nb=xb=b;
	for(i=0; i<a.length(); i++){
		if(a[i]=='5') xa[i]='6';
		if(a[i]=='6') na[i]='5';
	}
	for(i=0; i<b.length(); i++){
		if(b[i]=='5') xb[i]='6';
		if(b[i]=='6') nb[i]='5';
	}
	cout<<sum(na, nb)<<" "<<sum(xa, xb);
}
