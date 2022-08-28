#include<stdio.h>
int max(int a, int b){ return a>b?a:b; }
int d[4][100100], p[4][100100], q[100100];

int main(){
    int t, n, i;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i=1; i<=n; i++) scanf("%d", &d[0][i]);
        for(i=1; i<=n; i++) scanf("%d", &d[1][i]);
        for(i=0; i<=n; i++) p[0][i]=p[1][i]=q[i]=0;
        for(i=1; i<=n; i++){
            p[0][i]=max(p[1][i-1], q[i-1])+d[0][i];
            p[1][i]=max(p[0][i-1], q[i-1])+d[1][i];
            q[i]=max(p[0][i-1], p[1][i-1]);
        }
        printf("%d\n", max(p[0][n], p[1][n]));
    }
}