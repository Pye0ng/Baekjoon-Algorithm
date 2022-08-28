#include<stdio.h>
#include<vector>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
vector<pii> c, h;
int n, m, ans=1e9;

void dil(int t, int l, vector<int> v){
    int s=0, k, i;
    if(l==c.size()-1&&t<m) return;
    if(t==m){
        for(i=0; i<n; i++){
            k=400;
            for(auto j:v) k=min(k, abs(h[i].x-c[j].x)+abs(h[i].y-c[j].y));
            s+=k;
        }
        ans=min(ans, s);
        return;
    }
    for(i=l+1; i<c.size(); i++){
        vector<int> p=v;
        p.push_back(i);
        dil(t+1, i, p);
    }
}

int main(){
    int t, i, j;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++){
            scanf("%d", &t);
            if(t==1) h.push_back(pii(i, j));
            if(t==2) c.push_back(pii(i, j));
        }
    n=h.size();
    vector<int> v;
    for(i=0; i<=c.size()-m; i++) dil(0, i-1, v);
    printf("%d", ans);
}