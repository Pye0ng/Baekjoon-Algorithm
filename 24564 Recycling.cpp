#include<stdio.h>
#include<vector>
using namespace std;
typedef long long ll;
vector<int> s;
ll ans, d[100100];
int n, x, y;

void upd(int p, int q, ll t){
    if(t>ans||(t==ans&&p<x)){ x=p; y=q; ans=t; }
}

int init(int c, int a, int b){
    if(a==b) return s[c]=a;
    int m=a+b>>1, l, r;
    l=init(c<<1, a, m);
    r=init(c<<1|1, m+1, b);
    return s[c]=d[l]<d[r]?l:r;
}

int query(int c, int a, int b, int l, int r){
    if(a>r||b<l) return 0;
    if(l<=a&&b<=r) return s[c];
    int m=a+b>>1, p, q;
    p=query(c<<1, a, m, l, r);
    q=query(c<<1|1, m+1, b, l, r);
    return d[p]<d[q]?p:q;
}

void solve(int l, int r){
    int i=query(1, 1, n, l, r);
    upd(l, r, d[i]*(r-l+1));
    if(l==r) return;
    if(i>l) solve(l, i-1);
    if(i<r) solve(i+1, r);
}

int main(){
    scanf("%d", &n); s.resize(n*4); d[0]=1e16;
    for(int i=1; i<=n; i++) scanf("%lld", &d[i]);
    init(1, 1, n); solve(1, n);
    if(ans==0) printf("1 1 0");
    else printf("%d %d %lld", x, y, ans);
}