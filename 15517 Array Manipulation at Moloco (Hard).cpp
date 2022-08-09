#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> s, v;
long long int ans;
int d[1001000];

void upd(int c, int a, int b, int i){
    if(i<a||i>b) return;
    s[c]++;
    if(a!=b){
        int m=a+b>>1;
        upd(c<<1, a, m, i);
        upd(c<<1|1, m+1, b, i);
    }
}

int sum(int c, int a, int b, int l, int r){
    if(a>r||b<l) return 0;
    if(l<=a&&b<=r) return s[c];
    int m=a+b>>1;
    return sum(c<<1, a, m, l, r)+sum(c<<1|1, m+1, b, l, r);
}

int main(){
    int n, i;
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        scanf("%d", &d[i]);
        v.push_back(d[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    n=v.size(); s.resize(n*4);
    for(i=1; i<=n; i++){
        d[i]=lower_bound(v.begin(), v.end(), d[i])-v.begin()+1;
        printf("%d\n", sum(1, 1, n, 1, d[i]-1));
        upd(1, 1, n, d[i]);
    }
}