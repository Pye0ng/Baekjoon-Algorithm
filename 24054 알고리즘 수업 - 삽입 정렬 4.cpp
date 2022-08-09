#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<int> s, v;
ll k, cnt;
int d[500500], in[500500];

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
    scanf("%d %lld", &n, &k);
    s.resize(n*4);
    for(i=1; i<=n; i++){
        scanf("%d", &d[i]);
        v.push_back(d[i]);
    }
    sort(v.begin(), v.end());
    for(i=1; i<=n; i++){
        t=lower_bound(v.begin(), v.end(), d[i])-v.begin()+1;
        in[i]=sum(1, 1, n, t+1, n);
        cnt+=in[i]+(in[i]>0); upd(1, 1, n, t);
    }
    if(k>cnt){
        printf("-1");
        return 0;
    }
    for(i=2; i<=n&&k>0; i++){
        if(in[i]){
            t=in[i]+1;
            if(t==k) printf("%d", d[i]);
            else if(t>k){
                sort(d+1, d+i);
                printf("%d", d[i-k]);
            }
            k-=t;
        }
    }
}