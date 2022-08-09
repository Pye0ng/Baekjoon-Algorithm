#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct medal{ int g, s, b, num; };
struct need{ 
    int x, y, num;
    need(int a, int b, int c){ x=a; y=b; num=c; }
};
bool cmp1(medal p, medal q){ return p.g!=q.g?p.g>q.g:p.s!=q.s?p.s>q.s:p.b!=q.b?p.b>q.b:p.num<q.num; }
bool cmp2(need p, need q){ return p.x!=q.x?p.x<q.x:p.y!=q.y?p.y<q.y:p.num<q.num; }

vector<medal> v;
vector<need> g;
int d[55];

int main(){
    int n, l, r, e, s, i;
    scanf("%d %d", &n, &l);
    e=r=l;
    for(i=1; i<=n; i++){
        medal t; t.num=i;
        scanf("%d %d %d", &t.g, &t.s, &t.b);
        if(i==1) t.g+=l;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmp1);
    for(i=0; i<n; i++)
        if(v[i].num==1){ s=i; break; }
    if(l==0){ printf("%d", s+1); return 0; }
    for(i=s+1; i<n&&v[s].g==v[i].g; i++){
        g.push_back(need(v[s].s-v[i].s, max(0, v[s].b-v[i].b+1), i));
        g.push_back(need(v[s].s-v[i].s+1, 0, i));
    }
    sort(g.begin(), g.end(), cmp2);
    for(i=0; i<g.size(); i++)
        if(l>=g[i].x&&r>=g[i].y&&g[i].x+g[i].y<=e&&!d[g[i].num]){
            l-=g[i].x; r-=g[i].y;
            d[g[i].num]=1; s++;
        }
    printf("%d", s+1);
}