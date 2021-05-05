#include<iostream>
#include<string>
using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m, cnt=0, i;
	cin>>n;
	m=n;
	while(n--){
		string s;
		int d[27]={};
		cin>>s;
		d[s[0]-97]++;
		for(i=1; i<s.length(); i++)
			if(s[i]!=s[i-1]) d[s[i]-97]++;
		for(i=0; i<27; i++) 
			if(d[i]>1){ cnt++; break; }
	}
	printf("%d", m-cnt);
}
