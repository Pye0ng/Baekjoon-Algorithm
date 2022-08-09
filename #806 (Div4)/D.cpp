#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<string, int> pii;

bool cmp(pii a, pii b){
    if(a.x.length()==b.x.length()){
        if(a.x==b.x) return a.y<b.y;
        return a.x<b.x;
    }
    return a.x.length()<b.x.length();
}

int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, t, i, j;
    cin>>t;
    while(t--){
        cin>>n;
        string s, a, b;
        int d[100100]={};
        vector<pii> v;
        vector<string> l;
        for(i=0; i<n; i++){
            cin>>s;
            v.push_back(pii(s, i));
            l.push_back(s);
        }
        sort(l.begin(), l.end());
        l.erase(unique(l.begin(), l.end()), l.end());
        sort(v.begin(), v.end(), cmp);
        for(i=0; i<n; i++){
            if(v[i].x.length()==1) continue;
            for(j=1; j<v[i].x.length(); j++){
                a=v[i].x.substr(0, j);
                b=v[i].x.substr(j, v[i].x.length()-j+1);
                if(*lower_bound(l.begin(), l.end(), a)==a&&*lower_bound(l.begin(), l.end(), b)==b){
                    d[v[i].y]=1;
                    break;
                }
            }
        }
        for(i=0; i<n; i++) cout<<d[i];
        cout<<"\n";
    }
}