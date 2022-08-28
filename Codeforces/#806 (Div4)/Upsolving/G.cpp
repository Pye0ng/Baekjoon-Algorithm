#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int t, n, i, j; ll k, p, ans;
    scanf("%d", &t);
    while(t--){
        int d[100100], b[33]={};
        ll a[100100];
        ans=a[0]=0;
        scanf("%d %lld", &n, &k);
        for(i=1; i<=n; i++){
            scanf("%d", &d[i]);
            a[i]=a[i-1]+d[i];
        }
        for(i=n; i>0; i--){
            p=0;
            for(j=1; j<31; j++){
                b[j]+=d[i]&(1<<j)?1:0;
                b[j-1]=b[j];
                p+=b[j-1]*(1<<j-1);
                
            }
            ans=max(ans, max(a[i]-i*k, p+a[i-1]-(i-1)*k));
        }
        printf("%lld\n", ans);
    }
}