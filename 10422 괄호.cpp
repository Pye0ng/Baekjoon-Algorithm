#include<stdio.h>
long long int m=1e9+7, dp[5050];

int main(){
    int n, t, i, j;
    dp[0]=1;
    for(i=2; i<=5000; i+=2)
        for(j=0; j<i; j+=2) dp[i]=(dp[i]+dp[j]*dp[i-j-2])%m;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }
}