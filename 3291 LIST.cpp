#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
string l[110];
int d[110], e[110];

int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, t, p, i; string s;
    cin>>n;
    for(i=1; i<=n; i++){
        cin>>l[i]>>s;
        if(s=="UP") d[i]=1;
        else if(s=="DOWN") d[i]=2;
        else d[i]=3;
    }
    t=1;
    while(t<=n){
        queue<int> v1, v2;
        p=t;
        while(d[t]==1) v1.push(t++);
        while(d[t]!=1&&d[t]){
            if(d[t]==3) e[t]=t;
            else v2.push(t);
            t++;
        }
        for(i=p; i<t; i++){
            if(e[i]) continue;
            if(!v2.empty()){
                e[i]=v2.front();
                v2.pop();
            }
            else{
                e[i]=v1.front();
                v1.pop();
            }
        }
    }
    for(i=1; i<=n; i++) cout<<l[e[i]]<<"\n";
}