#include<stdio.h>
int s, c, d[1010][1010];

int main(){
    int n, i, j;
    scanf("%d", &n);
    while(n){
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++) scanf("%d", &d[i][j]);
        s=d[1][1]; c=1;
        for(i=2; i<=n; i++)
            for(j=1; j<i; j++) c&=(d[j][j]+d[i][i]==d[j][i]+d[i][j]);
        printf("%s\n", c?"homogeneous":"not homogeneous");
        scanf("%d", &n);
    }
}