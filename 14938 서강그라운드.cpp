#include<stdio.h>
#include<queue>
#include<vector>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > q;
vector<pii> v[110];
int ans, INF=1e9, a[110], d[110];

int main(){
    int n, k, m, c, i, j;
    scanf("%d %d %d", &n, &k, &m);
    for(i=1; i<=n; i++) scanf("%d", &a[i]);
    while(m--){
        int x, y;
        scanf("%d %d %d", &x, &y, &c);
        v[x].push_back(pii(y, c));
        v[y].push_back(pii(x, c));
    }
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++) d[j]=i==j?0:INF;
        m=0; q.push(pii(0, i));
        while(!q.empty()){
            pii p=q.top(); q.pop();
            if(p.x>d[p.y]) continue;
            for(auto j:v[p.y]){
                c=p.x+j.y;
                if(c<d[j.x]){
                    d[j.x]=c;
                    q.push(pii(c, j.x));
                }
            }
        }
        for(j=1; j<=n; j++)
            if(d[j]<=k) m+=a[j];
        ans=max(ans, m);
    }
    printf("%d", ans);
}