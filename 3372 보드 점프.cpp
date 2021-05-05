#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string dp[1050][1050];
int n, d[1010][1010];

string add(string a, string b){
	int k=0; string c="";
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

int main(){
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int i, j;
	cin>>n;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++) cin>>d[i][j];
	for(i=1; i<=1020; i++)
		for(j=1; j<=1020; j++) dp[i][j]="0";
	dp[1][1]="1";
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++){
			if(i==n&&j==n) break;
			dp[i+d[i][j]][j]=add(dp[i+d[i][j]][j], dp[i][j]);
			dp[i][j+d[i][j]]=add(dp[i][j+d[i][j]], dp[i][j]);
		}
	cout<<dp[n][n];
}
