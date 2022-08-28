#include<stdio.h>
typedef long long ll;
ll max(ll a, ll b){ return a>b?a:b; }
ll ans, d[100100], b[65];

int main(){
    int n, i, j;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%lld", &d[i]);
    for(i=0; i<n; i++)
        for(j=59; j>=0; j--)
            if((1LL<<j)&d[i]){
                if(!b[j]){ b[j]=d[i]; break; }
                else d[i]^=b[j];
            }
    for(i=59; i>=0; i--) ans=max(ans, ans^b[i]);
    printf("%lld", ans);
}