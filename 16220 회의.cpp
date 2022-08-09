#include<stdio.h>
#include<vector>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
vector<int> s;
vector<pii> p;
int cnt;

int upd(int c, int a, int b, int i, int t){
    if(i<a||i>b) return s[c];
    if(a==b) return s[c]=t;
    int m=a+b>>1;
    return s[c]=min(upd(c<<1, a, m, i, t), upd(c<<1|1, m+1, b, i, t));
}

int query(int c, int a, int b, int t){
    if(a==b) return a;
    int m=a+b>>1;
    if(t>=s[c<<1|1]&&s[c<<1|1]) return query(c<<1|1, m+1, b, t);
    else if(t>=s[c<<1]&&s[c<<1]) return query(c<<1, a, m, t);
    else return 0;
}

int main(){
    int n, t, i;
    scanf("%d", &n);
    p.push_back(pii(0, 0));
    s.resize(n*4, 1e9+1);
    for(i=0; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        p.push_back(pii(a, b));
    }
    sort(p.begin(), p.end());
    for(i=n; i>0; i--){
        t=query(1, 1, n, p[i].y);
        if(t==0) upd(1, 1, n, i, p[i].x);
        else{
            cnt++;
            upd(1, 1, n, t, 1e9+1);
        }
    }
    printf("%d", cnt);
}