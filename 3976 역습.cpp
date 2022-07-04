#include<stdio.h>
#include<algorithm>
using namespace std;
int dp1[100100], dp2[100100], d1[100100], d2[100100], p1[100100], p2[100100];

int main(){
    int t, n, s1, s2, i;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d %d", &n, &dp1[1], &dp2[1], &s1, &s2);
        for(i=2; i<=n; i++) scanf("%d", &p1[i]);
        for(i=2; i<=n; i++) scanf("%d", &d1[i]);
        for(i=2; i<=n; i++) scanf("%d", &p2[i]);
        for(i=2; i<=n; i++) scanf("%d", &d2[i]);
        for(i=2; i<=n; i++){
            dp1[i]=min(dp1[i-1]+d1[i], dp2[i-1]+p2[i]);
            dp2[i]=min(dp2[i-1]+d2[i], dp1[i-1]+p1[i]);
        }
        printf("%d\n", min(dp1[n]+s1, dp2[n]+s2));
    }
}