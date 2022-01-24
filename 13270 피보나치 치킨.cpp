#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[30], mn[20000], mx[20000];

int ub(int t){
	int p=1, q=27, m;
	while(p<q){
		m=(p+q)/2;
		if(dp[m]>t) q=m;
		else p=m+1;
	}
	return q;
}

int main(){
	int n, i, j;
	dp[1]=1; dp[2]=2;
	scanf("%d", &n);
	for(i=3; i<28; i++) dp[i]=dp[i-1]+dp[i-2]; 
	mn[1]=mx[1]=0; mn[2]=mx[2]=1; mn[3]=mx[3]=2;
	for(i=4; i<=n; i++){
		mn[i]=1e5; mx[i]=0;
		for(j=2; j<ub(i); j++){
			if(i-dp[j]<0) continue;
			mn[i]=min(mn[i], mn[i-dp[j]]+dp[j-1]);
			mx[i]=max(mx[i], mx[i-dp[j]]+dp[j-1]);
		}
	}
	printf("%d %d", mn[n], mx[n]);
}

