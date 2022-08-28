#include<stdio.h>
#include<algorithm>
#include<queue>
#define x first
#define y second
using namespace std;
struct virus{ 
    int x, y, p; 
    virus(int a, int b, int c){ x=a; y=b; p=c; }
};
struct cmp{
    bool operator()(virus a, virus b){ return a.p>b.p; }
};
priority_queue<virus, vector<virus>, cmp> q;

int n, s, t, x, y, d[220][220];
int dx[]={0, -1, 0, 1}, dy[]={-1, 0, 1, 0};

int main(){
    int k, nx, ny, i, j;
    scanf("%d %d", &n, &k);
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++){
            scanf("%d", &d[i][j]);
            q.push(virus(i, j, d[i][j]));
        }
    scanf("%d %d %d", &t, &x, &y);
    while(!q.empty()&&t&&d[x][y]==0){
        queue<virus> tmp;
        while(!q.empty()){
            virus v=q.top(); q.pop();
            for(j=0; j<4; j++){
                nx=v.x+dx[j];
                ny=v.y+dy[j];
                if(d[nx][ny]||nx<1||nx>n||ny<1||ny>n) continue;
                d[nx][ny]=v.p;
                tmp.push(virus(nx, ny, v.p));
            }
        }
        while(!tmp.empty()){
            q.push(tmp.front());
            tmp.pop();
        }
        t--;
    }
    printf("%d", d[x][y]);
}