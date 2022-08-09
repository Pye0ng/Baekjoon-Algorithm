#include<stdio.h>
int min(int a, int b){ return a<b?a:b; }
int d[1010], c[1010], dp[1010][1010];

int main(){
    int n, m, t, i, j;
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++) scanf("%d", &d[i]);
    for(i=1; i<=m; i++) scanf("%d", &c[i]);
    for(i=1; i<=n; i++){
        t=1e9+1;
        for(j=i; j<=m-n+i; j++){
            t=min(t, dp[i-1][j-1]+d[i]*c[j]);
            dp[i][j]=t;
        }
    }
    printf("%d", t);
}