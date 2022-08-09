#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
ll ans, a, b, c, d, p[100100];

int main(){
    int n, i;
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        scanf("%lld", &p[i]);
        if(p[i]>1) a++;
        else if(p[i]==1) b++;
        else if(p[i]==0) c++;
        else d++;
    }
    sort(p+1, p+n+1); ans=b;
    for(i=1; i<=d/2; i++) ans+=p[i*2-1]*p[2*i];
    if(d&1) ans+=c>0?0:p[d];
    for(i=0; i<a/2; i++) ans+=p[n-i*2]*p[n-i*2-1];
    if(a&1) ans+=p[n-a+1];
    printf("%lld", ans);
}