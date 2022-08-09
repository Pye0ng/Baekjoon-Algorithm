#include<iostream>
#include<vector>
using namespace std;

void upd(int c, int a, int b, int i, int t, vector<int> &s){
    if(i<a||i>b) return;
    s[c]+=t;
    if(a!=b){
        int m=a+b>>1;
        upd(c<<1, a, m, i, t, s);
        upd(c<<1|1, m+1, b, i, t, s);
    }
}

int sum(int c, int a, int b, int l, int r, vector<int> &s){
    if(a>r||b<l) return 0;
    if(l<=a&&b<=r) return s[c];
    int m=a+b>>1;
    return sum(c<<1, a, m, l, r, s)+sum(c<<1|1, m+1, b, l, r, s);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t, n, p, q, a, b, i; char c;
    cin>>t;
    while(t--){
        cin>>n>>p>>q;
        vector<int> s(n*4, 0);
        for(i=0; i<p+q; i++){
            cin>>c>>a>>b;
            if(c=='P') upd(1, 1, n, a, b, s);
            else cout<<sum(1, 1, n, a, b, s)<<"\n";
        }
    }
}