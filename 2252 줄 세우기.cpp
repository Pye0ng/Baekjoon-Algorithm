#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int n, m, in[32200];
vector<int> ans, v[32200];
queue<int> q;

int main(){
    int a, b, i, j;
    scanf("%d %d", &n, &m);
    for(i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        in[b]++;
    }
    for(i=1; i<=n; i++)
        if(in[i]==0) q.push(i);
    for(i=1; i<=n; i++){ //정렬이 완전히 되려면 n개 전부 방문
        int t=q.front(); q.pop();
        ans.push_back(t);
        for(j=0; j<v[t].size(); j++)
            if(--in[v[t][j]]==0) q.push(v[t][j]);
    }
    for(i=0; i<n; i++) printf("%d ", ans[i]);
}
