#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void upd(int c, int a, int b, int i, vector<int> &s){
    if(i<a||i>b) return;
    s[c]++;
    if(a!=b){
        int m=a+b>>1;
        upd(c<<1, a, m, i, s);
        upd(c<<1|1, m+1, b, i, s);
    }
}

int sum(int c, int a, int b, int l, int r, vector<int> &s){
    if(a>r||b<l) return 0;
    if(l<=a&&b<=r) return s[c];
    int m=a+b>>1;
    return sum(c<<1, a, m, l, r, s)+sum(c<<1|1, m+1, b, l, r, s);
}

int main(){
    int t, n, p, i;
    scanf("%d", &t);
    while(t--){
        vector<pii> v;
        vector<int> s;
        ll ans=0;
        scanf("%d", &n);
        s.resize(n*4, 0);
        for(i=1; i<=n; i++){
            scanf("%d", &p);
            if(i>p) v.push_back(pii(p, i));
        }
        sort(all(v));
        for(i=0; i<v.size(); i++){
            ans+=sum(1, 1, n, 1, min(v[i].x-1, n), s);
            upd(1, 1, n, v[i].y, s);
        }
        printf("%lld\n", ans);
    }
}