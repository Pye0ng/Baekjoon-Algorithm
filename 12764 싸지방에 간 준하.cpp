#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
struct cmp{ bool operator()(pii a, pii b){ return a.x>b.x; } };
priority_queue<pii, vector<pii>, cmp> q;
priority_queue<int, vector<int>, greater<int> > s;
vector<pii> v;
int t, d[100100];

int main(){
    int n, a, b, i;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d %d", &a, &b);
        v.push_back(pii(a, b));
    }
    sort(v.begin(), v.end());
    for(i=0; i<n; i++){
        while(!q.empty()&&v[i].x>q.top().x){
            s.push(q.top().y);
            q.pop();
        }
        if(s.empty()){
            d[++t]=1;
            q.push(pii(v[i].y, t));
        }
        else{
            d[s.top()]++; 
            q.push(pii(v[i].y, s.top()));
            s.pop();
        }
    }
    printf("%d\n", t);
    for(i=1; i<=t; i++) printf("%d ", d[i]);
}