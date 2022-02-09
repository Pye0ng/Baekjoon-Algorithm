#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long int ll;
ll k, mx, mn, d[20100], dp[20100];

int main(){
	int n, m, i, j;
	scanf("%d %d %lld", &n, &m, &k);
	for(i=1; i<=n; i++){
		scanf("%lld", &d[i]);
		dp[i]=1e18;
	}
	for(i=1; i<=n; i++){
		mx=mn=d[i];
		for(j=1; j<=m&&j<=i; j++){
			if(d[i-j+1]>mx) mx=d[i-j+1];
			if(d[i-j+1]<mn) mn=d[i-j+1];
			dp[i]=min(dp[i], dp[i-j]+k+j*(mx-mn));
		}
	}
	printf("%lld ", dp[n]);
}
