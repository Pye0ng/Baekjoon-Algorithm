#include<stdio.h>
#include<algorithm>
#include<stack>
using namespace std;
typedef long long int ll;
struct water{ ll h; int c, p; };
stack<water> s;
ll ans, m, d[100100], g[100100];
int cnt;

water con(ll a, int b, int c){
    water t; t.h=a; t.c=b; t.p=c;
    return t;
}

int main(){
    int n, k, i;
    scanf("%d %d", &n, &k);
    for(i=1; i<=n; i++){
        scanf("%lld", &d[i]);
        m=max(m, d[i]);
    }
    if(k==1){
        printf("0");
        return 0;
    }
    for(i=1; i<=n; i++){
        d[i]=m-d[i];
        while(!s.empty()&&s.top().h<d[i]){
            
        }
    }
}