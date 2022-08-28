#include<stdio.h>
#include<vector>
using namespace std;
vector<int> v[100100];
int d[100100], ans[100100];

void dfs(int t, int s){
    s+=d[t];
    ans[t]=s;
    for(auto i:v[t]) dfs(i, s);
}

int main(){
    int n, m, a, b, i;
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++){
        scanf("%d", &a);
        if(a>0) v[a].push_back(i);
    }
    while(m--){
        scanf("%d %d", &a, &b);
        d[a]+=b;
    }
    dfs(1, 0);
    for(i=1; i<=n; i++) printf("%d ", ans[i]);
}