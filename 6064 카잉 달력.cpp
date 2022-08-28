#include<stdio.h>
#include<algorithm>
using namespace std;
long long n, m, x, y;

int main(){
    int t, i;
    scanf("%d", &t);
    while(t--){
        scanf("%lld %lld %lld %lld", &n, &m, &x, &y);
        if(n<m){ swap(n, m); swap(x, y); }
        for(i=0; i<=m; i++)
            if((n*i+x-y)%m==0){
                printf("%lld\n", n*i+x);
                break;
            }
		if(i==m+1) printf("-1\n");
    }
}