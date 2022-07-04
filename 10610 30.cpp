#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
vector<int> v;

int main(){
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n=0, ch=-1, i;
	string t, s="";
	cin>>t;
	for(i=0; i<t.length(); i++){
		if(t[i]=='0') ch=1;
		v.push_back(t[i]-'0');
		n+=t[i]-'0';
	}
	if(ch==-1||n%3){
		cout<<-1;
		return 0;
	}	
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for(i=0; i<v.size(); i++) cout<<v[i];
}
