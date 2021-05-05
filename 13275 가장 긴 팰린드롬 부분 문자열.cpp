#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int p[200010], r, c, ans;
string s, t="*";

int main(){
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int i;
	cin>>s;
	r=c=-1;
	for(i=0; i<s.length(); i++){ t.push_back(s[i]); t.push_back('*'); }	
	int sz=t.length();
	for(i=0; i<sz; i++){
		if(i>r) p[i]=0;
		else p[i]=min(p[2*c-i], r-i);
		while(i>p[i]&&i+p[i]+1<sz&&t[i-p[i]-1]==t[i+p[i]+1]) p[i]++;
		if(r<i+p[i]){ r=i+p[i]; c=i; }
	}
	for(i=0; i<sz; i++) ans=max(ans, p[i]);
	cout<<ans;
}
