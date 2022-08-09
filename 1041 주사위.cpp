#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long int ll;
ll min1, min2, min3, ans;

int main(){
    ll n;
    ll a, b, c, d, e, f;
    ll ab, ac, ad, ae, bc, bd, bf, ce, cf, de, df, ef;
    ll abc, abd, ace, ade, fbc, fbd, fce, fde;
    scanf("%lld %lld %lld %lld %lld %lld %lld", &n, &a, &b, &c, &d, &e, &f);
    if(n==1) printf("%lld", a+b+c+d+e+f-max({a, b, c, d, e, f}));
    else{
        ab=a+b; ac=a+c; ad=a+d; ae=a+e;
        bc=b+c; bd=b+d; bf=b+f;
        ce=c+e; cf=c+f;
        de=d+e; df=d+f;
        ef=e+f;
        abc=a+b+c; abd=a+b+d; ace=a+c+e; ade=a+d+e;
        fbc=f+b+c; fbd=f+b+d; fce=f+c+e; fde=f+d+e;
        min1=min({a, b, c, d, e, f});
        min2=min({ab, ac, ad, ae, bc, bd, bf, ce, cf, de, df, ef});
        min3=min({abc, abd, ace, ade, fbc, fbd, fce, fde});
        printf("%lld", 4*min3+(8*n-12)*min2+(5*n*n-16*n+12)*min1);
    }
}