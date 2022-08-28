#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
vector<pii> v;
int sum, ans=2147483647, p, q;

bool cmp(pii a, pii b){
    if(a.y==b.y) return a.x>b.x;
    return a.y<b.y;
}

int main(){
    int n, m, i;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v.push_back(pii(a, b));n
        sum+=a;
    }
    if(sum<m){
        printf("-1");
        return 0;
    }
    sort(v.begin(), v.end(), cmp);
    sum=0;
    for(i=0; i<n; i++){
        sum+=v[i].x;
        if(p!=v[i].y){
            if(sum>=m){
                ans=min(ans, v[i].y);
                break;
            }
            p=q=v[i].y;
        }
        else{
            q+=p;
            if(sum>=m) ans=min(ans, q);
        }
    }
    printf("%d", ans);
}