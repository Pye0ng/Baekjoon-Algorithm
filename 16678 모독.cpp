#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
int t, a[100100], d[100100];
queue<int> q;
ll ans;

int main(){
    int n, i;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
    for(i=1; i<=n; i++){
        while(a[t]<i&&t<n) t++;
        if(t>=n) break;
        ans+=ll(a[t++]-i);
    }
    printf("%lld", ans);
}