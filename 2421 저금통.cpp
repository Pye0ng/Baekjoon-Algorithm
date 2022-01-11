#include<iostream>
#include<string>
using namespace std;
int t, a[1000100], d[100000], dp[1010][1010];

int prime(int s){
	int p=0, q=78498, m;
	while(p<=q){
		m=(p+q)/2;
		if(d[m]==s) return 1;
		else if(d[m]>s) q=m-1;
		else p=m+1;
	}
	return 0;
}

int mx(int p, int q){ return p>q?p:q; }

int main(){
	int n, i, j;
	for(i=2; i<1000000; i++) a[i]=i;
	for(i=2; i<1000000; i++){
		if(a[i]==0) continue;
		for(j=i<<1; j<1000000; j+=i) a[j]=0;
	}
	for(i=2; i<1000000; i++)
		if(a[i]!=0) d[++t]=i;
	cin>>n;
	dp[1][1]=0;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			if(i+j==2) continue;
			string s=to_string(i)+to_string(j);
			dp[i][j]=mx(dp[i-1][j], dp[i][j-1])+prime(stoi(s));
		}
	}
	cout<<dp[n][n];
}
