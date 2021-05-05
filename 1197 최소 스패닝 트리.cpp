#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int ans, parent[100010];
bool ch;

typedef struct kruskal{ int a, b, val; }ks;
vector<ks> v;

bool cmp(ks x, ks y){ return x.val<y.val; }

int find(int t){
    if(t==parent[t]) return t;
    else return parent[t]=find(parent[t]);
}

void uni_on(int x, int y){
    ch=false;
    x=find(x); y=find(y);
    if(x==y) return; //cycle occured
    parent[x]=y;
    ch=true;
}

int main(){
    int n, m, i;
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++) parent[i]=i;
    for(i=0; i<m; i++){
        ks t;
        scanf("%d %d %d", &t.a, &t.b, &t.val);
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmp);
    for(i=0; i<m; i++){
        uni_on(v[i].a, v[i].b);
        if(ch) ans+=v[i].val;
    }
    printf("%d", ans);
}
