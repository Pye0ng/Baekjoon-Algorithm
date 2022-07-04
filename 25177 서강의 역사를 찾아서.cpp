#include<stdio.h>
#include<algorithm>
using namespace std;
int mx, a[1010], b[1010];

int main(){
    int n, m, i;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    for(i=0; i<m; i++) scanf("%d", &b[i]);
    for(i=0; i<max(n, m); i++) mx=max(mx, b[i]-a[i]);
    printf("%d", mx);
}