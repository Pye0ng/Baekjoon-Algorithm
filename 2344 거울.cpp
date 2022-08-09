#include<stdio.h>
#include<vector>
#include<algorithm>
#define all(v) v.begin(), v.end()
using namespace std;
vector<int> r[1010], c[1010], rr[1010], cc[1010];
int t, n, m, ans[4040];

void dfs(int x, int y, int d){
    if(d==1){
        auto p=upper_bound(all(r[x]), y);
        if(p==r[x].end()){
            t=2*n+m-x+1;
            return;
        }
        dfs(x, *p, 2);
    }
    else if(d==2){
        auto p=upper_bound(all(cc[y]), n-x+1);
        if(p==cc[y].end()){
            t=2*(n+m)-y+1;
            return;
        }
        dfs(n-*p+1, y, 1);
    }
    else if(d==3){
        auto p=upper_bound(all(rr[x]), m-y+1);
        if(p==rr[x].end()){
            t=x;
            return;
        }
        dfs(x, m-*p+1, 4);
    }
    else{
        auto p=upper_bound(all(c[y]), x);
        if(p==c[y].end()){
            t=n+m-y+1;
            return;
        }
        dfs(*p, y, 3);
    }
}

int main(){
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++){
            scanf("%d", &t);
            if(t){
                r[i].push_back(j);
                c[j].push_back(i);
                rr[i].push_back(m-j+1);
                cc[j].push_back(n-i+1);
            }
        }
    for(i=1; i<=n; i++) sort(all(rr[i]));
    for(i=1; i<=m; i++) sort(all(cc[i]));
    for(i=1; i<=2*(n+m); i++){
        if(ans[i]) continue;
        if(i<=n) dfs(i, 0, 1);
        else if(i<=n+m) dfs(n+1, i-n, 2);
        else if(i<=2*n+m) dfs(2*n+m-i+1, m+1, 3);
        else dfs(0, 2*(n+m)-i+1, 4);
        ans[i]=t; ans[t]=i;
    }
    for(i=1; i<=2*(n+m); i++) printf("%d ", ans[i]);
}