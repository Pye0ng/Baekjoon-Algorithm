#include<iostream>
#include<string>
#include<vector>
using namespace std;
int d[52][1010];

int main(){
	int n, m, h, k, i, j; string s, t; 
	cin>>n>>m>>h;
	cin.ignore(1);
	for(k=1; k<=n; k++){
		vector<int> v; v.push_back(0);
		getline(cin, s, '\n'); t="";
		for(i=0; i<s.length(); i++){
			if(s[i]!=' ') t+=s[i];
			else{ v.push_back(stoi(t)); t=""; }
		}
		v.push_back(stoi(t));
		for(i=0; i<v.size(); i++){
			d[k][0]=1;
			if(k==1) d[1][v[i]]=1;
			else 
				for(j=h; j>0; j--)
					if(j>=v[i]) d[k][j]=(d[k][j]+d[k-1][j-v[i]])%10007;
		}
	}
	cout<<d[n][h];
}
