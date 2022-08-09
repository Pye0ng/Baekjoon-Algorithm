#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<ll> s;
ll NINF=-1e15-1;

ll upd(int c, int a, int b, int i, ll t){
    if(i<a||i>b) return s[c];
    if(a==b) return s[c]=t;
    int m=a+b>>1;
    return s[c]=max(upd(c<<1, a, m, i, t), upd(c<<1|1, m+1, b, i, t));
}

ll query(int c, int a, int b, int l, int r){
    if(a>r||b<l) return NINF;
    if(l<=a&&b<=r) return s[c];
    int m=a+b>>1;
    return max(query(c<<1, a, m, l, r), query(c<<1|1, m+1, b, l, r));
}

int main(){
    int n, d, i; ll t;
    scanf("%d %d", &n, &d);
    s.resize(n*4, NINF);
    for(i=1; i<=n; i++){
        scanf("%lld", &t);
        upd(1, 1, n, i, t+max((ll)0, query(1, 1, n, max(1, i-d), i-1)));
    }
    printf("%lld", s[1]);
}