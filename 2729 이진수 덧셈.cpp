#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, i, j;
	cin>>n;
	for(i=1; i<=n; i++){
		string a, b, c;
		int t, k=0, d[85]={0,};
		cin>>a>>b;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		t=a.length()>b.length()?a.length():b.length();
		for(j=0; j<a.length(); j++) d[j]=a[j]-'0';
		for(j=0; j<b.length(); j++) d[j]+=b[j]-'0';
		for(j=0; j<t; j++){
			d[j+1]+=d[j]/2;
			d[j]%=2;
		}
		if(d[t]) t++;
		for(j=t-1; j>=0; j--){
			if(d[j]) k=1;
			if(k==1) cout<<d[j];
		}
		if(k==0) cout<<"0";
		cout<<"\n"; 
	}
}
