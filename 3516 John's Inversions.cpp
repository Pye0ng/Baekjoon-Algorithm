#include<stdio.h>
#include<vector>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
vector<int> s, v;
vector<pii> p;
long long ans;

int sum(int c, int a, int b, int l, int r){
    if(a>r||b<l) return 0;
    if(l<=a&&b<=r) return s[c];
    int m=a+b>>1;
    return sum(c<<1, a, m, l, r)+sum(c<<1|1, m+1, b, l, r);
}

void upd(int c, int a, int b, int i){
    if(i<a||i>b) return;
    s[c]++;
    if(a!=b){
        int m=a+b>>1;
        upd(c<<1, a, m, i);
        upd(c<<1|1, m+1, b, i);
    }
}

int main(){
    int n, i;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        p.push_back(pii(a, b));
        v.push_back(b);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    sort(p.begin(), p.end());
    n=v.size(); s.resize(n*4);
    for(i=0; i<p.size(); i++){
        p[i].y=lower_bound(v.begin(), v.end(), p[i].y)-v.begin()+1;
        ans+=sum(1, 1, n, p[i].y+1, n);
        upd(1, 1, n, p[i].y);
    }
    printf("%lld", ans);
}