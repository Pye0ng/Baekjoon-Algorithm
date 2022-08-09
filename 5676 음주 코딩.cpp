#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int upd(int c, int a, int b, int i, int t, vector<int> &s){
    if(i<a||i>b) return s[c];
    if(a==b) return s[c]=t;
    int m=a+b>>1;
    return s[c]=upd(c<<1, a, m, i, t, s)*upd(c<<1|1, m+1, b, i, t, s);
}

int query(int c, int a, int b, int l, int r, vector<int> &s){
    if(a>r||b<l) return 1;
    if(l<=a&&b<=r) return s[c];
    int m=a+b>>1;
    return query(c<<1, a, m, l, r, s)*query(c<<1|1, m+1, b, l, r, s);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k, a, b, i; char c;
    while(cin>>n>>k){
        vector<int> s(n*4, 0);
        for(i=1; i<=n; i++){
            cin>>a;
            upd(1, 1, n, i, a>0?1:a<0?-1:0, s);
        }
        for(i=0; i<k; i++){
            cin>>c>>a>>b;
            if(c=='C') upd(1, 1, n, a, b>0?1:b<0?-1:0, s);
            else{
                a=query(1, 1, n, a, b, s);
                cout<<(a>0?'+':a<0?'-':'0');
            }
        }
        cout<<"\n";
    }
}