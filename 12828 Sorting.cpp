#include<stdio.h>
typedef long long ll;
ll cnt=1, m=1e9+7;

int len(ll t){
    int c=0;
    while(t){
        t/=10;
        c++;
    }
    return c;
}

ll pow(int t){
    ll r=1;
    while(--t) r*=10;
    return r;
}

int main(){
    ll a, b, t; int i;
    scanf("%lld %lld", &a, &b);
    while(len(a)<=len(b)){
        if(len(a)<len(b)){
            t=(pow(len(a)+1)-a)%m;
            cnt=(cnt+(t*(t+1)/2)%m)%m;
            a=pow(len(a)+1);
        }
        else{
            t=(b-a+1)%m;
            cnt=(cnt+(t*(t+1)/2)%m)%m;
            break;
        }
    }
    printf("%lld", cnt);
}