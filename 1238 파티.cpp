#include<stdio.h>
#include<vector>
#include<queue>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > q;
vector<pii> v[1010];
int INF=1e9, ans, d[1010][1010];

int main(){
    int n, m, x, c, i, j;
    scanf("%d %d %d", &n, &m, &x);
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++) d[i][j]=INF;
    while(m--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(pii(b, c));
    }
    for(i=1; i<=n; i++){
        d[i][i]=0; q.push(pii(0, i));
        while(!q.empty()){
            pii p=q.top(); q.pop();
            if(p.x>d[i][p.y]) continue;
            for(auto j:v[p.y]){
                c=p.x+j.y;
                if(c<d[i][j.x]){
                    d[i][j.x]=c;
                    q.push(pii(c, j.x));
                }
            }
        }
    }
    for(i=1; i<=n; i++) ans=max(ans, d[i][x]+d[x][i]);
    printf("%d", ans);
}