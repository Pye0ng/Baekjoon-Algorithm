#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first 
#define y second
using namespace std;
typedef pair<int, int> pii;
int n, a[1020];

void print(int p, int q, int r, int s){ printf("%d\n%d %d\n%d", p, q, r, s); }

int main(){
    int t, i; pii rev; rev.x=rev.y=0;
    scanf("%d", &n);
    for(i=1; i<=n; i++){
        scanf("%d", &a[i]);
        a[n+i]=a[i];
    }
    for(i=1; i<2*n; i++){
        t=a[i+1]-a[i];
        if(t==-1||t==n-1){
            pii p;
            p.x=i;
            while(i<2*n&&(t==-1||t==n-1)){
                i++; 
                t=a[i+1]-a[i];
            }
            p.y=i; 
            if(p.y-p.x>rev.y-rev.x) rev=p;
        }
    }
    if(rev.y==2*n){
        if(a[n-1]==1) print(a[n-3]-1, 1, n, 3);
        else print(a[n-1]-1, 1, n, 1);
    }
    else if(rev.y>n){
        if(a[rev.x]==1||a[rev.y]==1) print(a[rev.x-1]-1, 2, rev.y-rev.x+2, n-rev.x+2);
        else print(a[rev.y]-1, 1, rev.y-rev.x+1, n-rev.x+1);
    }
    else{
        if(a[n]==1) print(a[n-1]-1, rev.x+2, rev.y+2, 2);
        else if(rev.y==n) print(a[n]-1, 1, rev.y-rev.x+1, rev.y-rev.x+1);
        else print(a[n]-1, rev.x+1, rev.y+1, 1);
    }
}