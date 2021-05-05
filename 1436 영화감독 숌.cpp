#include<iostream>
#include<string>
using namespace std;

int main(){
	int n, cnt=0, t=665;
	cin>>n;
	while(++t){
		string s=to_string(t);
		if(s.find("666")!=-1) cnt++;
		if(cnt==n){
			cout<<t<<"\n";
			break;
		}
	}
}
