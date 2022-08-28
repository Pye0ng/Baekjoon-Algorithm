#include<stdio.h>
int ans, d[520][520];
void max(int t){ ans=t>ans?t:ans; }

int main(){
    int n, m, x, y;
    scanf("%d %d", &n, &m);
    for(x=1; x<=n; x++)
        for(y=1; y<=m; y++) scanf("%d", &d[x][y]);
    for(x=1; x<=n; x++)
        for(y=1; y<=m; y++){
            if(x<=n-3) max(d[x][y]+d[x+1][y]+d[x+2][y]+d[x+3][y]);
            if(y<=m-3) max(d[x][y]+d[x][y+1]+d[x][y+2]+d[x][y+3]);
            if(x<=n-2&&y<=m-1){
                max(d[x][y]+d[x+1][y]+d[x+2][y]+d[x+2][y+1]);
                max(d[x][y]+d[x][y+1]+d[x+1][y+1]+d[x+2][y+1]);
                max(d[x][y]+d[x][y+1]+d[x+1][y]+d[x+2][y]);
                max(d[x][y]+d[x+1][y]+d[x+1][y+1]+d[x+2][y+1]);
                max(d[x][y]+d[x+1][y]+d[x+2][y]+d[x+1][y+1]);
            }
            if(x<=n-1&&y<=m-2){
                max(d[x][y]+d[x][y+1]+d[x][y+2]+d[x+1][y]);
                max(d[x][y]+d[x+1][y]+d[x+1][y+1]+d[x+1][y+2]);
                max(d[x][y]+d[x][y+1]+d[x][y+2]+d[x+1][y+2]);
                max(d[x][y]+d[x][y+1]+d[x][y+2]+d[x+1][y+1]);
            }
            if(x<=n-2&&y>=2){
                max(d[x][y]+d[x+1][y]+d[x+1][y-1]+d[x+2][y-1]);
                max(d[x][y]+d[x+1][y-1]+d[x+1][y]+d[x+2][y]);
            }
            if(x<=n-1&&y>=2&&y<=m-1){
                max(d[x][y]+d[x][y+1]+d[x+1][y-1]+d[x+1][y]);
                max(d[x][y]+d[x][y-1]+d[x+1][y]+d[x+1][y+1]);
                max(d[x][y]+d[x+1][y-1]+d[x+1][y]+d[x+1][y+1]);
            }
            if(x<=n-1&&y<=m-1){
                if(y>=2) max(d[x][y]+d[x+1][y-1]+d[x+1][y]+d[x+1][y+1]);
                max(d[x][y]+d[x+1][y]+d[x][y+1]+d[x+1][y+1]);
            }
            if(x<=n-1&&y>=3) max(d[x][y]+d[x+1][y]+d[x+1][y-1]+d[x+1][y-2]);
            if(x<=n-2&&y>=2) max(d[x][y]+d[x+1][y]+d[x+2][y]+d[x+2][y-1]);
        }
    printf("%d", ans);
}