#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    ll cntA, cntB, maxA, maxB;
    scanf("%lld %lld %lld %lld", &cntA, &cntB, &maxA, &maxB);
    if(maxA==0||cntA==0) printf("%lld", min(cntB, maxB));
    else if(maxB==0||cntB==0) printf("%lld", min(cntA, maxA));
    else{
        if(cntA<cntB){
            swap(cntA, cntB);
            swap(maxA, maxB);
        }
        if(cntA==cntB) printf("%lld", cntA*2);
        else printf("%lld", min(maxA*(cntB+1), cntA)+cntB);
    }
}