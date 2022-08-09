#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int init(int c, int a, int b, vector<int> &s){
    if(a==b) return s[c]=1;
    int m=a+b>>1;
    return s[c]=init(c<<1, a, m, s)+init(c<<1|1, m+1, b, s);
}

int sum(int c, int a, int b, int l, int r, vector<int> &s){
    if(a>r||b<l) return 0;
    if(l<=a&&b<=r) return s[c];
    int m=a+b>>1;
    return sum(c<<1, a, m, l, r, s)+sum(c<<1|1, m+1, b, l, r, s);
}

void upd(int c, int a, int b, int i, vector<int> &s){
    if(i<a||i>b) return;
    s[c]--;
    if(a!=b){
        int m=a+b>>1;
        upd(c<<1, a, m, i, s);
        upd(c<<1|1, m+1, b, i, s);
    }
}

int find(int c, int a, int b, int t, vector<int> &s){
    if(a==b) return a;
    int m=a+b>>1;
    if(t<=s[c<<1]) return find(c<<1, a, m, t, s);
    else return find(c<<1|1, m+1, b, t-s[c<<1], s);
}

int main(){
    int n, k, m, t, i;
    scanf("%d %d %d", &n, &k, &m);
    while(n){
        vector<int> s(n*4);
        init(1, 1, n, s);
        upd(1, 1, n, m, s);
        for(i=n-1; i>1; i--){
            t=sum(1, 1, n, m+1, n, s);
            if(k%i>t){
                m=find(1, 1, n, k%i-t, s);
                upd(1, 1, n, m, s);
            }
            else{
                t=sum(1, 1, n, 1, m, s)+k%i;
                m=find(1, 1, n, t?t:i, s);
                upd(1, 1, n, m, s);
            }
        }
        printf("%d\n", find(1, 1, n, 1, s));
        scanf("%d %d %d", &n, &k, &m);
    }
}