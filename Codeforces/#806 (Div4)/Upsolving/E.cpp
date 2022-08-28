#include<stdio.h>
int min(int a, int b){ return a<b?a:b; }

int main(){
    int t, n, p, ans, i, j;
    scanf("%d", &t);
    while(t--){
        char c[110][110];
        p=ans=0;
        scanf("%d", &n);
        for(i=0; i<n; i++) scanf("%s", c[i]);
        for(i=0; i<n; i++)
            for(j=0; j<n; j++){
                p=(c[i][j]-'0')+(c[j][n-1-i]-'0')+(c[n-1-i][n-1-j]-'0')+(c[n-1-j][i]-'0');
                ans+=min(p, 4-p);
            }
        printf("%d\n", ans/4);
    }
}