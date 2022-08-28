#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    int n, t, p, cnt, i, j;
    scanf("%d", &t);
    while(t--){
        int a[110]={};
        char c[12];
        scanf("%d", &n);
        for(i=1; i<=n; i++) scanf("%d", &a[i]);
        for(i=1; i<=n; i++){
            scanf("%d %s", &p, c);
            cnt=0;
            for(j=0; j<p; j++) cnt+=c[j]=='U'?-1:1;
            a[i]=(a[i]+10+cnt)%10;
        }
        for(i=1; i<=n; i++) printf("%d ", a[i]);
        printf("\n");
    }
}