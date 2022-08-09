#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> s;

int upd(int c, int a, int b, int i, int t){
    if(i<a||i>b) return s[c];
    if(a==b) return s[c]=t;
    int m=a+b>>1;
    return s[c]=upd(c<<1, a, m, i, t)+upd(c<<1|1, m+1, b, i, t);
}

int find(int c, int a, int b, int t){
    if(a==b) return a;
    int m=a+b>>1;
    if(t<=s[c<<1]) return find(c<<1, a, m, t);
    else return find(c<<1|1, m+1, b, t-s[c<<1]);
}

int main(){
    int n, t, i;
    scanf("%d", &n);
    s.resize(n*4);
    for(i=1; i<=n; i++){
        scanf("%d", &t);
        upd(1, 1, n, i, t);
    }
    for(i=1; i<=n; i++){
        scanf("%d", &t);
        printf("%d ", find(1, 1, n, t));
        upd(1, 1, n, find(1, 1, n, t), 0);
    }
}