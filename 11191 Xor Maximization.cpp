#include<stdio.h>
typedef long long ll;
ll max(ll a, ll b){ return a>b?a:b; }
ll ans, a[100100], d[70];

int main(){
    int n, i, j;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%lld", &a[i]);
    for(i=0; i<n; i++)
        for(j=59; j>=0; j--)
            if((1LL<<j)&a[i]){
                if(!d[j]){ d[j]=a[i]; break; }
                else a[i]^=d[j];
            }
    for(i=59; i>=0; i--) ans=max(ans, ans^d[i]);
    printf("%lld", ans);
}