#include<stdio.h>
#include<algorithm>
#include<deque>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
deque<pii> q;
int ans[5000500];

int main(){
    int n, m, t, i;
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++){
        scanf("%d", &t);
        while(!q.empty()&&q.front().y<=i-m) q.pop_front();
        while(!q.empty()&&q.back().x>=t) q.pop_back();
        q.push_back(pii(t, i));
        ans[i]=q.front().x;
    }
    for(i=1; i<=n; i++) printf("%d ", ans[i]);
}