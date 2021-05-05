#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

bool vis[1001];
vector<int> v[10001];

void dfs(int k){
    if(vis[k]) return;
    printf("%d ", k);
    vis[k]=1;
    for(int i=0; i<v[k].size(); i++){
        int n=v[k][i];
        if(!vis[n]) dfs(n);
    }
}

void bfs(int k){
    queue<int> q;
    q.push(k);
    vis[k]=1;
    while(!q.empty()){
        int n=q.front();
        q.pop();
        printf("%d ", n);
        for(int i=0; i<v[n].size(); i++){
            int m=v[n][i];
            if(!vis[m]){
                q.push(m);
                vis[m]=1;
            }
        }
    }
}

int main(){
    int n, m, s, i;
    scanf("%d %d %d", &n, &m, &s);
    for(i=1; i<=m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i=1; i<=n; i++) sort(v[i].begin(), v[i].end());
    dfs(s);
    for(i=0; i<1001; i++) vis[i]=0;
    printf("\n");
    bfs(s);
}
