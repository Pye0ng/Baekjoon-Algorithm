#include<stdio.h>
#include<algorithm>
int n, m, d[100010], dp[1000010];

int main(){
	int i;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &d[i]);
	for(i=0; i<n; i++){
		dp[d[i]]=dp[d[i]-1]+1;
		m=std::max(m, dp[d[i]]);
	}
	printf("%d", m);
} 
