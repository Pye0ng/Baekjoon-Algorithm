#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
vector<int> s, p;
vector<pii> v;
int ans;

int init(int c, int a, int b){
    if(a==b) return s[c]=v[a].y;
    int m=a+b>>1;
    return s[c]=max(init(c<<1, a, m), init(c<<1|1, m+1, b));
}

int query(int c, int a, int b, int l, int r){
    if(a>r||b<l) return 0;
    if(l<=a&&b<=r) return s[c];
    int m=a+b>>1;
    return max(query(c<<1, a, m, l, r), query(c<<1|1, m+1, b, l, r));
}

int main(){
    int n, d, a, b, i;
    scanf("%d %d", &n, &d);
    s.resize(n*4);
    v.push_back(pii(0, 0));
    for(i=0; i<n; i++){
        scanf("%d %d", &a, &b);
        v.push_back(pii(a, b));
        p.push_back(a);
    }
    sort(v.begin(), v.end());
    sort(p.begin(), p.end());
    init(1, 1, n);
    for(i=1; i<=n; i++){
        a=upper_bound(p.begin(), p.end(), v[i].x-d)-p.begin()+1;
        b=lower_bound(p.begin(), p.end(), v[i].x+d)-p.begin()+1;
        ans+=query(1, 1, n, a, i-1)>=2*v[i].y&&query(1, 1, n, i+1, min(b, n))>=2*v[i].y; 
    }
    printf("%d", ans);
}