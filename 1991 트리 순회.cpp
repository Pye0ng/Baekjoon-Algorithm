#include<iostream>
#include<string>
#include<vector>
using namespace std;
int l[30], r[30];
string ans1, ans2, ans3;

void travel1(int t){
    ans1+='A'+t-1;
    if(l[t]) travel1(l[t]);
    if(r[t]) travel1(r[t]);
}

void travel2(int t){
    if(l[t]) travel2(l[t]);
    ans2+='A'+t-1;
    if(r[t]) travel2(r[t]);
}

void travel3(int t){
    if(l[t]) travel3(l[t]);
    if(r[t]) travel3(r[t]);
    ans3+='A'+t-1;
}

int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, i; char a, b, c;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>a>>b>>c;
        if(b!='.') l[a-'A'+1]=b-'A'+1;
        if(c!='.') r[a-'A'+1]=c-'A'+1;
    }
    travel1(1);
    travel2(1);
    travel3(1);
    cout<<ans1<<"\n"<<ans2<<"\n"<<ans3;
}