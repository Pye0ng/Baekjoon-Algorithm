#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
ll sum, ans=1e15, d[210000];
vector<ll> s;

int main(){
    int k, n, p, t, i, j;
    s.push_back(0);
    scanf("%d %d", &k, &n);
    for(i=1; i<=n; i++){
        scanf("%lld", &d[i]);
        s.push_back(s[i-1]+d[i]);
    }
    for(i=1; i<=s[n]/k; i++){
        p=0; sum=0;
        for(j=0; j<k; j++){
            t=lower_bound(s.begin(), s.end(), s[p]+i)-s.begin();
            if(t>n) break;
            sum+=s[t]-s[p]-i; p=t;
        }
        if(j!=k) break;
        ans=min(ans, sum);
    }
    printf("%lld", ans);
}