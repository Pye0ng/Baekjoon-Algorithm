#include<stdio.h>
typedef long long ll;
ll min(ll a, ll b){ return a<b?a:b; }

char s[1000100];
int p[1000100];
ll ans, INF=1e17, dp[1000100];

ll cycle(int t){
    if(dp[t]!=-1) return dp[t];
    if(!p[t]) return dp[t]=INF;
    return dp[t]=min(ll(p[t]), cycle(p[t]-1));
}

int main(){
    int n, i, j;
    scanf("%d", &n);
    scanf("%s", s);
    dp[0]=-1;
    for(i=1, j=0; i<n; i++){
        dp[i]=-1;
        while(j>0&&s[i]!=s[j]) j=p[j-1];
        if(s[i]==s[j]) p[i]=++j;
    }
    for(i=0; i<n; i++){
        ll t=cycle(i);
        if(t!=INF) ans+=i-t+1;
    }
    printf("%lld", ans);
}