#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> s(400400);
int d[100100];

int seg(int c, int a, int b){
    if(a==b) return s[c]=d[a]>=d[a-1];
    int m=a+b>>1;
    return s[c]=seg(c<<1, a, m)+seg(c<<1|1, m+1, b);
}

int sum(int c, int a, int b, int l, int r){
    if(a>r||b<l||l>r) return 0;
    if(l<=a&&b<=r) return s[c];
    int m=a+b>>1;
    return sum(c<<1, a, m, l, r)+sum(c<<1|1, m+1, b, l, r); 
}

int upd(int c, int a, int b, int i){
    if(i<a||i>b) return s[c];
    if(a==b) return s[c]=d[a]>=d[a-1];
    int m=a+b>>1;
    return s[c]=upd(c<<1, a, m, i)+upd(c<<1|1, m+1, b, i);
}

int main(){
    int n, m, i;
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++) scanf("%d", &d[i]);
    seg(1, 1, n);
    while(m--){
        int t, a, b;
        scanf("%d %d %d", &t, &a, &b);
        if(t&1) printf("%s\n", sum(1, 1, n, a+1, b)==b-a?"CS204":"HSS090");
        else{
            swap(d[a], d[b]);
            upd(1, 1, n, a);
            if(a<n) upd(1, 1, n, a+1);
            upd(1, 1, n, b);
            if(b<n) upd(1, 1, n, b+1);
        }
    }
}