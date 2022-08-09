#include<stdio.h>
#include<vector>
using namespace std;
vector<int> g[2020], v, ans;
int c[2020], d[2020];

bool solve(int t){
    for(auto i:g[t])
        if(!c[i]) return 0;
    for(auto i:g[t]) d[i]=1;
    d[t]=1;
    return 1;
}

int main(){
    int n, m, a, b, i;
    scanf("%d %d", &n, &m);
    while(m--){
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    scanf("%d", &m);
    for(i=0; i<m; i++){
        scanf("%d", &a);
        v.push_back(a);
        c[a]=1;
    }
    for(i=0; i<m; i++)
        if(solve(v[i])) ans.push_back(v[i]);
    for(i=1; i<=n; i++)
        if(c[i]!=d[i]){
            printf("-1");
            return 0;
        }
    printf("%d\n", ans.size());
    for(auto i:ans) printf("%d ", i);
}