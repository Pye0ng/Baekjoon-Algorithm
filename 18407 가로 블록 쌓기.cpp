#include<stdio.h>
#include<vector>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
vector<int> s, lz, v;
vector<pii> p;

void prop(int c, int a, int b){
    if(lz[c]==0) return;
    s[c]=max(s[c], lz[c]);
    if(a!=b){ 
        lz[c<<1]=max(lz[c], lz[c<<1]);
        lz[c<<1|1]=max(lz[c], lz[c<<1|1]);
    }
    lz[c]=0;
}

void upd(int c, int a, int b, int l, int r, int t){
    prop(c, a, b);
    if(a>r||b<l) return;
    if(l<=a&&b<=r){ lz[c]=max(lz[c], t); prop(c, a, b); return; }
    int m=a+b>>1;
    upd(c<<1, a, m, l, r, t);
    upd(c<<1|1, m+1, b, l, r, t);
    s[c]=max(s[c<<1], s[c<<1|1]);
}

int query(int c, int a, int b, int l, int r){
    prop(c, a, b);
    if(a>r||b<l) return 0;
    if(l<=a&&b<=r) return s[c];
    int m=a+b>>1;
    return max(query(c<<1, a, m, l, r), query(c<<1|1, m+1, b, l, r));
}

int main(){
    int n, t, i;
    scanf("%d", &n);
    s.resize(n*8);
    lz.resize(n*8);
    for(i=0; i<n; i++){
        pii k; scanf("%d %d", &k.x, &k.y);
        p.push_back(pii(k.y, k.x+k.y-1));
        v.push_back(k.y); v.push_back(k.x+k.y-1);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(i=0; i<n; i++){
        p[i].x=lower_bound(v.begin(), v.end(), p[i].x)-v.begin()+1;
        p[i].y=lower_bound(v.begin(), v.end(), p[i].y)-v.begin()+1;
    }
    for(i=0; i<n; i++){
        t=query(1, 1, n*2, p[i].x, p[i].y); 
        upd(1, 1, n*2, p[i].x, p[i].y, t+1);
    }
    printf("%d", query(1, 1, n*2, 1, n*2));
}