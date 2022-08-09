#include<stdio.h>
long long m=987654321, dp[10050];

int main(){
    int n, i, j;
    scanf("%d", &n);
    dp[0]=1; n/=2;
    for(i=1; i<=n; i++)
        for(j=0; j<i; j++) dp[i]=(dp[i]+dp[j]*dp[i-j-1])%m;
    printf("%lld", dp[n]);
}