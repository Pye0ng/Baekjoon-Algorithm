#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
vector<int> g, s(2002000);
vector<pii> v;

int main(){
    int n, ans=0, i;
    scanf("%d", &n);
    v.push_back(pii(0, 0));
    for(i=0; i<n; i++){
        pii p; scanf("%d %d", &p.x, &p.y);
        g.push_back(p.x);
        g.push_back(p.y);
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    n=g.size();
    for(i=1; i<v.size(); i++){
        v[i].x=lower_bound(g.begin(), g.end(), v[i].x)-g.begin()+1;
        v[i].y=lower_bound(g.begin(), g.end(), v[i].y)-g.begin()+1;
    }
    printf("%d", ans);
}