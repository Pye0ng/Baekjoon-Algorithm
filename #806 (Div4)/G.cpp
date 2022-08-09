#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    int t, n, i, j; ll k;
    scanf("%d", &t);
    while(t--){
        ll ans, sum=0;
        scanf("%d %lld", &n, &k);
        ll d[100100], a[100100];
        int b[33]={};
        for(i=1; i<=n; i++){
            scanf("%lld", &a[i]);
            sum+=a[i]; d[i]=d[i-1]+a[i];
        }
        ans=max(ll(0), sum-n*k);
        for(i=n; i; i--){
            sum=0;
            for(j=0; j<31; j++)
                if((1<<j)&a[i]) b[j]++;
            for(j=1; j<31; j++) b[j-1]=b[j];
            for(j=0; j<31; j++) sum+=b[j]*(1<<j);
            ans=max(ans, d[i-1]+sum-(i-1)*k);
        }
        printf("%lld\n", ans);
    }
}