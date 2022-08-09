#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<int> s;
ll d[1000100];
int n;

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

ll solve(int l, int r){
    int i=query(1, 1, n, l, r);
    ll ans=d[i]*(r-l+1);
    if(l==r) return ans;
    if(i>l) ans=max(ans, solve(l, i-1));
    if(i<r) ans=max(ans, solve(i+1, r));
    return ans;
}

int main(){
    scanf("%d", &n); s.resize(n*4);
    for(int i=1; i<=n; i++) scanf("%d", &d[i]);
    init(1, 1, n); d[0]=100000;
    printf("%lld", solve(1, n));
}