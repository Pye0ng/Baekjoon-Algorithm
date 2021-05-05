#include<stdio.h>
int n, mx=1, a[1100], dp[1100];

int main(){
	int i;
	dp[0]=1;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &a[i]);
	for(i=1; i<n; i++){
		dp[i]=1;
		for(int j=0; j<i; j++)
			if(a[i]>a[j]&&dp[j]+1>dp[i])
				dp[i]=dp[j]+1;
		if(mx<dp[i])
			mx=dp[i];
	}
	printf("%d", mx);
}
