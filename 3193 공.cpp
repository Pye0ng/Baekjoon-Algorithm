#include<iostream>
#include<vector>
#include<algorithm>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
vector<int> r[1010], c[1010], rr[1010], cc[1010];
char p, m[1010][1010];
int dir;

int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, k, t, x, y, i, j;
    cin>>n>>k;
    for(i=0; i<n; i++) cin>>m[i];
    for(i=0; i<n; i++){
        r[i].pb(n); rr[i].pb(1);
        c[i].pb(n); cc[i].pb(1);
        for(j=0; j<n; j++){
            if(m[i][j]=='X'){
                r[i].pb(j); rr[i].pb(-j);
                c[j].pb(i); cc[j].pb(-i);
            }
            if(m[i][j]=='L'){ x=i; y=j; m[i][j]='.'; }
        }
    }
    for(i=0; i<n; i++){
        sort(all(r[i]));
        sort(all(rr[i]));
        sort(all(c[i]));
        sort(all(cc[i]));
    }
    for(i=0; i<k; i++){
        cin>>p;
        dir=(dir+(p=='D'?1:-1)+4)%4;
        if(dir==0) x=*upper_bound(all(c[y]), x)-1;
        if(dir==1) y=*upper_bound(all(r[x]), y)-1;
        if(dir==2) x=1-*upper_bound(all(cc[y]), -x);
        if(dir==3) y=1-*upper_bound(all(rr[x]), -y);
    }
    m[x][y]='L';
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            int ox, oy;
            if(dir==0){ ox=i; oy=j; }
            if(dir==1){ ox=n-1-j; oy=i; }
            if(dir==2){ ox=n-1-i; oy=n-1-j; }
            if(dir==3){ ox=j; oy=n-1-i; }
            cout<<m[ox][oy];
        }
        cout<<"\n";
    }
}