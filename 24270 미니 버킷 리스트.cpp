#include<stdio.h>
typedef long long ll;
ll m=1e9+7, sum;

int main(){
    int n, k, i, j;
    scanf("%d %d", &n, &k);
    for(i=0; i<n; i++){
        int t; scanf("%d", &t);
        sum+=t;
    }
    k-=sum; sum=1;
    for(i=n+k; i>k; i--) sum=(sum*i)%m;
    printf("%lld", sum);
}