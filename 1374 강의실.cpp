#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
struct cmp{
    bool operator()(pii a, pii b){
        return a.x>b.x;
    }
};
priority_queue<pii, vector<pii>, cmp> q;
vector<pii> v;
int ans;

int main(){
    int n, i;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        pii p; int t;
        scanf("%d %d %d", &t, &p.x, &p.y);
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    for(i=0; i<n; i++){
        while(!q.empty()&&q.top().x<=v[i].x) q.pop();
        q.push(pii(v[i].y, v[i].x));
        ans=max(ans, int(q.size()));
    }
    printf("%d", ans);
}