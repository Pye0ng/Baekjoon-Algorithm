#include<iostream>
#include<string>
using namespace std;
int t, i, ans, d[30][3];
string s;
 
int main(){
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>s;
	while(i<s.length()){
		string p="";
		if(s[i]=='-'||s[i]=='+'){ if(s[i]=='-') d[t][2]=1; i++; }
		else{
			while(s[i]!='-'&&s[i]!='+'&&i<s.length()) p.push_back(s[i++]);
			d[t++][1]=stoi(p);
		}
	}
	i=1; ans+=d[0][1];
	while(i<t){
		if(d[i][2]){
			int cnt=d[i++][1];
			while(d[i][2]==0) cnt+=d[i++][1];
			ans-=cnt;
		}
		else ans+=d[i++][1];
	}
	cout<<ans;
}
