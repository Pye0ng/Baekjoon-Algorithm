#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
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

int query(int c, int a, int b, int l, int r, vector<int> &s){
    if(a>r||b<l) return 0;
    if(l<=a&&b<=r) return s[c];
    int m=a+b>>1;
    return query(c<<1, a, m, l, r, s)+query(c<<1|1, m+1, b, l, r, s);
}

int main(){
    int t, n, i;
    scanf("%d", &t);
    while(t--){
        int a[200200];
        ll ans=0;
        vector<pii> v;
        vector<int> s(1000000);
        scanf("%d", &n);
        for(i=1; i<=n; i++){
            scanf("%d", &a[i]);
            if(a[i]<i) v.push_back(pii(a[i], i));
        }
        sort(v.begin(), v.end());
        for(i=0; i<v.size(); i++){
            ans+=query(1, 1, n, 1, min(n, v[i].x-1), s);
            upd(1, 1, n, v[i].y, s);
        }
        printf("%lld\n", ans);
    }
}