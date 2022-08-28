#include<stdio.h>
#include<vector>
#include<algorithm>
#define all(x) x.begin(), x.end()
using namespace std;
struct medal{ int g, s, b, num; };
struct need{ 
    int s, b, num; 
    need(int p, int q, int r){ s=p; b=q; num=r; }
};
vector<medal> v;
vector<need> l, r;
int d[52];

bool cmp(medal p, medal q){
    if(p.g==q.g){
        if(p.s==q.s){
            if(p.b==q.b) return p.num<q.num;
            return p.b>q.b;
        }
        return p.s>q.s;
    }
    return p.g>q.g;
}

bool cmpl(need p, need q){
    if(p.s==q.s) return p.b<q.b;
    return p.s<q.s;
}

int main(){
    int n, p, q, x, y, z, i;
    scanf("%d %d", &n, &z);
    for(i=0; i<n; i++){
        medal t; t.num=i;
        scanf("%d %d %d", &t.g, &t.s, &t.b);
        if(i<1) t.g+=z;
        v.push_back(t);
    }
    sort(all(v), cmp);
    x=y=z;
    for(i=0; i<n; i++)
        if(v[i].num==0){ p=q=i; break; }
    if(z==0){ printf("%d", p+1); return 0; }
    for(i=p+1; i<n; i++){
        if(v[p].g!=v[i].g) break;
        l.push_back(need(v[p].s-v[i].s+1, -1, i));
        l.push_back(need(v[p].s-v[i].s, v[p].b>=v[i].b?v[p].b-v[i].b+1:-1, i));
    }
    sort(all(l), cmpl);
    for(i=0; i<l.size(); i++){
        if(x>=l[i].s&&y>=l[i].b&&l[i].s+max(0, l[i].b)<=z&&!d[l[i].num]){
            x-=l[i].s; y-=max(0, l[i].b);
            d[l[i].num]=1; p++;
        }
    }
    printf("%d", p+1);
}