#include<stdio.h>
int n, d[150], dp[300010];

int main(){
	int k, t, i, j;
	scanf("%d", &n);
	for(i=2; i<=140; i++) d[i-1]=(i*i*i-i)/6;
	dp[1]=1;
	for(i=2; i<=n; i++){
		k=9999999;
		for(j=1; d[j]<=i; j++){
			t=i-d[j];
			if(dp[t]<k) k=dp[t]; 
		}
		dp[i]=k+1;
	}
	printf("%d", dp[n]);
}
