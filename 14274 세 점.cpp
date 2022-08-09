#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
vector<ll> in, s;
vector<int> v;
vector<pii> p;
ll ans;

ll sum_in(int c, int a, int b, int l, int r){
    if(a>r||b<l) return 0;
    if(l<=a&&b<=r) return in[c];
    int m=a+b>>1;
    return sum_in(c<<1, a, m, l, r)+sum_in(c<<1|1, m+1, b, l, r);
}

ll sum_s(int c, int a, int b, int l, int r){
    if(a>r||b<l) return 0;
    if(l<=a&&b<=r) return s[c];
    int m=a+b>>1;
    return sum_s(c<<1, a, m, l, r)+sum_s(c<<1|1, m+1, b, l, r);
}

void upd_in(int c, int a, int b, int i, ll t){
    if(i<a||i>b) return;
    in[c]+=t;
    if(a!=b){
        int m=a+b>>1;
        upd_in(c<<1, a, m, i, t);
        upd_in(c<<1|1, m+1, b, i, t);
    }
}

void upd_s(int c, int a, int b, int i){
    if(i<a||i>b) return;
    s[c]++;
    if(a!=b){
        int m=a+b>>1;
        upd_s(c<<1, a, m, i);
        upd_s(c<<1|1, m+1, b, i);
    }
}

int main(){
    int n, i;
    scanf("%d", &n);
    s.resize(n*4);
    in.resize(n*4);
    for(i=0; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        p.push_back(pii(a, b));
        v.push_back(b);
    }
    sort(v.begin(), v.end());
    sort(p.begin(), p.end());
    for(i=0; i<n; i++){
        p[i].x=i+1;
        p[i].y=lower_bound(v.begin(), v.end(), p[i].y)-v.begin()+1;
        printf("%d %d\n", p[i].x, p[i].y);
    }
    
    printf("%lld", ans);
}