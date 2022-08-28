#include<stdio.h>

int main(){
    int t, n, i, j;
    scanf("%d", &t);
    while(t--){
        int p, s, d[110];
        char c[12];
        scanf("%d", &n);
        for(i=1; i<=n; i++) scanf("%d", &d[i]);
        for(i=1; i<=n; i++){
            scanf("%d", &p);
            scanf("%s", c);
            s=0;
            for(j=0; j<p; j++) s+=c[j]=='D'?1:-1;
            printf("%d ", (d[i]+10+s)%10);
        }
        printf("\n");
    }
}