#include<stdio.h>
#include<vector>
using namespace std;
vector<int> g[100100];
int v[100100], d[100100];

int dfs(int t){
    int sum=1; v[t]=1;
    for(auto i:g[t])
        if(!v[i]) sum+=dfs(i);
    return d[t]=sum==1?1:sum;
}

int main(){
    int n, r, q, i;
    scanf("%d %d %d", &n, &r, &q);
    for(i=1; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(r);
    while(q--){
        scanf("%d", &r);
        printf("%d\n", d[r]);
    }
}