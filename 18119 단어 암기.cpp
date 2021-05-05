#include<iostream>
#include<string>
using namespace std;
int k, n, m, t, cont, wd[10010];

int main(){
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int i, j;
	char c;
	cin>>n>>m;
	for(i=0; i<26; i++) cont+=1<<i;
	for(i=1; i<=n; i++){
		int d[28]={};
		string s; cin>>s;
		for(j=0; j<s.length(); j++)
			if(d[s[j]-'a']==0){
				wd[i]+=1<<(s[j]-'a');
				d[s[j]-'a']=1;
			}
	}
	for(i=1; i<=m; i++){
		cin>>k>>c; t=0;
		if(k==1) cont-=1<<(c-'a');
		else cont+=1<<(c-'a');
		for(j=1; j<=n; j++)
			if((wd[j]&cont)==wd[j]) t++;
		cout<<t<<'\n';
	}
}
