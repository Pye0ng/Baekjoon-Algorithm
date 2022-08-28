#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#define all(x) x.begin(), x.end()
using namespace std;

bool find(string s, vector<string> &v){ return *lower_bound(all(v), s)==s; }

int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t, n, c, i, j;
    string a, b;
    cin>>t;
    while(t--){
        vector<string> v, p;
        cin>>n;
        for(i=0; i<n; i++){
            cin>>a;
            v.push_back(a);
            p.push_back(a);
        }
        sort(all(v));
        v.erase(unique(all(v)), v.end());
        for(i=0; i<n; i++){
            c=0;
            if(p[i].length()==1){ cout<<c; continue; }
            for(j=1; j<p[i].length(); j++){
                a=p[i].substr(0, j);
                b=p[i].substr(j);
                if(find(a, v)&&find(b, v)){ c=1; break; }
            }
            cout<<c;
        }
        cout<<"\n";
    }
}