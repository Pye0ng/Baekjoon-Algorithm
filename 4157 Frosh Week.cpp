#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
long long ans;
vector<int> s;
vector<pii> p;

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
    int n, t, i;
    scanf("%d", &n);
    s.resize(n*4);
    for(i=1; i<=n; i++){
        scanf("%d", &t);
        p.push_back(pii(t, i));
    }
    sort(p.begin(), p.end());
    for(i=0; i<n; i++){
        ans+=sum(1, 1, n, p[i].y+1, n);
        upd(1, 1, n, p[i].y);
    }
    printf("%lld", ans);
}