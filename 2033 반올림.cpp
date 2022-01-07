#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s, a;
int t, m, k, i, j;

int main(){
	cin>>s;
	for(i=s.length()-1; i>0; i--){
		k=1;
		if(m) t=1;
		else t=0;
		m=0;
		t+=s[i]-'0';
		if(t>4) m=1; 
		a.push_back(0+'0');
	}
	if(m) t=1;
	else t=0;
	t+=s[0]-'0';
	if(t>9){ a.push_back(0+'0'); a.push_back(1+'0'); }
	else a.push_back(t+'0');
	reverse(a.begin(), a.end());
	cout<<a;
}
