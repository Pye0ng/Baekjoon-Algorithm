#include<stdio.h>
#include<vector>
using namespace std;
typedef long long int ll;

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
        ll ans=0;
        scanf("%d", &n);
        vector<int> s(n*4, 0);
        for(i=0; i<n; i++){
            scanf("%d", &p);
            ans+=sum(1, 1, n, p+1, n, s);
            upd(1, 1, n, p, s);
        }
        printf("%lld\n", ans);
    }
}