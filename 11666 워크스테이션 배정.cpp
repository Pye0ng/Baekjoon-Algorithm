#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
priority_queue<int, vector<int>, greater<int>> q;
queue<int> track;
vector<pii> v;
int ans;

int main(){
    int n, m, i;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++){
        pii p;
        scanf("%d %d", &p.x, &p.y);
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    for(i=0; i<n; i++){
        while(!q.empty()&&v[i].x-q.top()>m+1) q.pop();
        if(!q.empty()&&v[i].x>q.top()){ q.pop(); ans++; }
        q.push(v[i].x+v[i].y-1);
    }
    printf("%d", ans);
}