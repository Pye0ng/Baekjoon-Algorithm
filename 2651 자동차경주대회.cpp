#include<stdio.h>
#include<vector>
using namespace std;
int m, d[110], s[110], t[110];
vector<int> dp(110), ans[110];

int main(){
    int n, i, j;
    scanf("%d %d", &m, &n);
    for(i=1; i<=n+1; i++){
        scanf("%d", &d[i]);
        s[i]=s[i-1]+d[i];
    }
    for(i=1; i<=n; i++) scanf("%d", &t[i]);
    for(i=1; i<=n+1; i++){
        dp[i]=s[i]<=m?t[i]:2147483647;
        for(j=i-1; j>=0&&s[i]-s[j]<=m; j--)
            if(dp[j]+t[i]<=dp[i]){
                dp[i]=dp[j]+t[i];
                vector<int> v=ans[j];
                if(i<=n) v.push_back(i);
                ans[i]=v;
            }
    }
    if(s[n+1]<=m) printf("0\n0");
    else{
        printf("%d\n%d\n", dp[n+1], ans[n+1].size());
        for(auto i:ans[n+1]) printf("%d ", i);
    }
}