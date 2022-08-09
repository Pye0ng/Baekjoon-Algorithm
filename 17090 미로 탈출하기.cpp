#include<stdio.h>
#include<algorithm>
using namespace std;
char s[550], c[550][550];
int ans, n, m, v[550][550], d[550][550];
int dx[]={-1, 0, 1, 0}, dy[]={0, 1, 0, -1};

int T(char t){ return t=='U'?0:t=='R'?1:t=='D'?2:3; }

int dfs(int x, int y){
    if(v[x][y]) return d[x][y];
    if(x<1||x>n||y<1||y>m) return 1;
    v[x][y]=1;
    return d[x][y]=dfs(x+dx[T(c[x][y])], y+dy[T(c[x][y])]);
}

int main(){
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++){
        scanf("%s", s);
        for(j=1; j<=m; j++) c[i][j]=s[j-1];
    }
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(!v[i][j]) dfs(i, j);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++) ans+=d[i][j];
    printf("%d", ans);
}