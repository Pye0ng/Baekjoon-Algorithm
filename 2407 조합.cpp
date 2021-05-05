#include<iostream>
#include<algorithm> 
#include<string>
using namespace std;
string dp[101][101];

string add(string a, string b){
	int k=0; string c;
	while(!a.empty()||!b.empty()||k){
		if(!a.empty()){
			k+=a.back()-'0';
			a.pop_back();
		}
		if(!b.empty()){
			k+=b.back()-'0';
			b.pop_back();
		}
		c.push_back((k%10)+'0');
		k/=10;
	}
	reverse(c.begin(), c.end());
	return c;
}

string comb(int n, int m){
	if(n==m||m==0) return "1";
	if(dp[n][m]!="") return dp[n][m];
	return dp[n][m]=add(comb(n-1, m), comb(n-1, m-1));
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin>>n>>m;
	cout<<comb(n, m);
} 
