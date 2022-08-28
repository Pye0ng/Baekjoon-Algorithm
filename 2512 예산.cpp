#include<stdio.h>
#include<algorithm>
using namespace std;
int t, m, ans, d[10100];

int main(){
    int n, k, p=1, q=100000, i;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &d[i]);
        t+=d[i]; m=max(m, d[i]);
    }
    scanf("%d", &k);
    if(t<=k){ printf("%d", m); return 0; }
    q=m;
    while(p<=q){
        m=p+q>>1; t=0;
        for(i=0; i<n; i++) t+=min(m, d[i]);
        if(t<=k){
            ans=m;
            p=m+1;
        }
        else q=m-1;
    }
    printf("%d", ans);
}