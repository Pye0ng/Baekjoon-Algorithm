#include<stdio.h>
#include<vector>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
vector<pii> s[300];
int d[300][300];

pii unite(pii a, pii b){ return pii(max(a.x, b.x), min(a.y, b.y)); }

pii init(int c, int a, int b, int i){
    if(a==b) return s[i][c]=pii(d[i][a], d[i][a]);
    int m=a+b>>1;
    return s[i][c]=unite(init(c<<1, a, m, i), init(c<<1|1, m+1, b, i));
}

pii query(int c, int a, int b, int l, int r, int i){
    if(a>r||b<l) return pii(-1, 251);
    if(l<=a&&b<=r) return s[i][c];
    int m=a+b>>1;
    return unite(query(c<<1, a, m, l, r, i), query(c<<1|1, m+1, b, l, r, i));
}

int main(){
    int n, m, b, k, i, j;
    scanf("%d %d %d", &n, &b, &k);
    for(i=1; i<=n; i++) s[i].resize(n*4);
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++) scanf("%d", &d[i][j]);
    for(i=1; i<=n; i++) init(1, 1, n, i);
    while(k--){
        int p, q;
        scanf("%d %d", &p, &q);
        pii ans=pii(-1, 251);
        for(i=p; i<p+b; i++) ans=unite(ans, query(1, 1, n, q, q+b-1, i));
        printf("%d\n", ans.x-ans.y);
    }
}