#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
vector<pii> v;
int ans, c[32][32];

int main(){
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    for(i=0; i<m; i++){
        pii p;
        scanf("%d %d", &p.x, &p.y);
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    c[0][0]=1;
    for(i=1; i<n; i++){
        c[i][0]=c[i-1][0];
        for(j=1; j<=i; j++) c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
    ans=c[v[0].x][v[0].y];
    for(i=1; i<v.size(); i++) ans*=v[i].y>=v[i-1].y?c[v[i].x-v[i-1].x][v[i].y-v[i-1].y]:0;
    ans*=(1<<abs(n-1-v[v.size()-1].x));
    printf("%d", ans);
}