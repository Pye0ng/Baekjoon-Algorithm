#include<stdio.h>
#include<vector>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
vector<pii> v;
vector<int> s, p;
int t, a[500100], d[500100];

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
    int n, k, i;
    scanf("%d %d", &n, &k);
    s.resize(n*4);
    for(i=1; i<=n; i++){
        scanf("%d", &a[i]);
        p.push_back(a[i]);
        v.push_back(pii(a[i], i));
    }
    sort(a+1, a+n+1);
    sort(v.begin(), v.end());
    for(i=0; i<n; i++){
        d[i+1]=sum(1, 1, n, v[i].y+1, n);
        t+=d[i+1]; upd(1, 1, n, v[i].y);
    }
    if(t<k) printf("-1");
    else{
        
    }
}