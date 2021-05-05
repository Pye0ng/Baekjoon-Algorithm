#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ans;
int n, m, t, cnt, d[41][41];

int mid(int x, int y){
    vector<int> v;
    for(int i=x; i<=x+2; i++)
        for(int j=y; j<=y+2; j++) v.push_back(d[i][j]);
    sort(v.begin(), v.end());
    return v[4];
}

int main(){
    int i, j;
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++) scanf("%d", &d[i][j]);
    scanf("%d", &t);
    for(i=1; i<=n-2; i++)
        for(j=1; j<=m-2; j++) ans.push_back(mid(i, j));
    for(i=0; i<ans.size(); i++)
        if(ans[i]>=t) cnt++;
    printf("%d", cnt);
}
