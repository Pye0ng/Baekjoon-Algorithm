#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
int k=2, e, ans, m[25][25];
int dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};

int main(){
    int n, x, y, d, s, nx, ny, c, i, j;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++){
            scanf("%d", &m[i][j]);
            if(m[i][j]==9){ x=i; y=j; m[i][j]=0; }
        }
    while(1){
        int v[25][25]={};
        queue<pii> q;
        pii t=pii(n+1, n+1);
        d=c=0;
        q.push(pii(x, y));
        while(!q.empty()){
            d++; s=q.size();
            for(i=0; i<s; i++){
                pii p=q.front(); q.pop();
                for(j=0; j<4; j++){
                    nx=p.x+dx[j];
                    ny=p.y+dy[j];
                    if(nx<1||nx>n||ny<1||ny>n||v[nx][ny]||m[nx][ny]>k) continue;
                    if(m[nx][ny]<k&&m[nx][ny]>0){ 
                        if(nx<t.x||(nx==t.x&&ny<t.y)) t=pii(nx, ny);
                        c=1; 
                    }
                    v[nx][ny]=1;
                    q.push(pii(nx, ny));
                }
            }
            if(c) break;
        }
        if(!c) break;
        x=t.x; y=t.y;
        ans+=d; m[x][y]=0;
        if(++e==k){ k++; e=0; }
    }
    printf("%d", ans);
}