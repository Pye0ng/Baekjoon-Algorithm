#include<stdio.h>
int d[52][52];

int main(){
    int n, m, t, ans=1, i, j;
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++) scanf("%d", &d[i][j]);
    for(i=1; i<=n; i++){
        t=(d[i][1]-1)/m;
        for(j=2; j<=m; j++){
            ans&=(t==(d[i][j]-1)/m);
            t=(d[i][j]-1)/m;
        }
    }
    for(j=1; j<=m; j++){
        t=d[1][j]%m;
        for(i=2; i<=n; i++){
            ans&=(t==d[i][j]%m);
            t=d[i][j]%m;
        }
    }
    printf("%d", ans);
}