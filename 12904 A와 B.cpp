#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s, t;
bool ch;

int main(){
	int i;
	cin>>s>>t;
	while(true){
		if(s.length()==t.length()){
			if(s==t) ch=1;
			break;
		}
		char e=t[t.length()-1]; 
		t.pop_back();
		if(e=='B') reverse(t.begin(), t.end());
	}
	cout<<ch;
}
