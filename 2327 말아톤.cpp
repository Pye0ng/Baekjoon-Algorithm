#include<stdio.h>
#include<vector>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
vector<pii> v;
int INF=1e9, dp[100100];

int main(){
    int n, h, a, b, i, j;
    scanf("%d %d", &h, &n);
    for(i=0; i<=h; i++) dp[i]=INF;
    for(i=0; i<n; i++){
        scanf("%d %d", &a, &b);
        v.push_back(pii(a, b));
    }
    sort(v.begin(), v.end());
    for(i=0; i<n; i++)
        for(j=h-v[i].x; j>=0; j--){
            if(dp[j]==INF&&j>0) continue;
            dp[j+v[i].x]=dp[j+v[i].x]==INF?min(dp[j], v[i].y):max(dp[j+v[i].x], min(dp[j], v[i].y));
        }
    printf("%d", dp[h]);
}