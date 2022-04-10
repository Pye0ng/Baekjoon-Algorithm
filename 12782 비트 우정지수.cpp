#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, A, B, i;
	string a, b;
	cin>>n;
	while(n--){
		A=0; B=0;
		cin>>a>>b;
		for(i=0; i<a.length(); i++){
			if(a[i]=='1'&&b[i]=='0') A++;
			if(a[i]=='0'&&b[i]=='1') B++;
		}
		cout<<max(A, B)<<"\n";
	}
} 
