#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    int t, p, n, i, j;
    scanf("%d", &t);
    while(t--){
        int ans=0;
        char c[110][110];
        scanf("%d", &n);
        for(i=0; i<n; i++) scanf("%s", c[i]);
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                if(c[i][j]!=c[j][n-i-1]||c[i][j]!=c[n-i-1][n-j-1]||c[i][j]!=c[n-j-1][i]){
                    p=(c[i][j]-'0')+(c[j][n-i-1]-'0')+(c[n-i-1][n-j-1]-'0')+(c[n-j-1][i]-'0');
                    ans+=min(4-p, p);
                }
        printf("%d\n", ans/4);
    }
}