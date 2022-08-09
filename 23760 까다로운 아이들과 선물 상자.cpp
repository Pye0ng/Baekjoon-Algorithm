#include<stdio.h>
#include<vector>
using namespace std;
vector<int> s(400400);
int w[100100], d[100100];

void upd(int c, int a, int b, int i, int t){
    if(i<a||i>b) return;
    s[c]+=t;
    if(a!=b){
        int m=a+b>>1;
        upd(c<<1, a, m, i, t);
        upd(c<<1|1, m+1, b, i, t);
    }
}

int find(int c, int a, int b, int t){
    if(a==b) return a;
    int m=a+b>>1;
    if(t<=s[c<<1]) return find(c<<1, a, m, t);
    else return find(c<<1|1, m+1, b, t-s[c<<1]);
}

int main(){
    int n, m, t, i;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++){
        scanf("%d", &t);
        upd(1, 0, 100000, t, 1);
    }
    for(i=1; i<=m; i++) scanf("%d", &w[i]);
    for(i=1; i<=m; i++) scanf("%d", &d[i]);
    for(i=1; i<=m; i++){
        t=find(1, 0, 100000, n+1-d[i]);
        if(t>=w[i]){
            upd(1, 0, 100000, t, -1);
            upd(1, 0, 100000, t-w[i], 1);
        }
        else{
            printf("0");
            return 0;
        }
    }
    printf("1");
}