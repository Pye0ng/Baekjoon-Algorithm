#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
vector<string> v;
vector<int> q;
int n, k, ans, p[200];


void kmp(string s){
    int sum=0, i, j;
    for(i=1, j=0; i<n; i++){
        while(j>0&&s[i]!=s[j]) j=p[j-1];
        if(s[i]==s[j]) p[i]=++j;
    }
    string a=s+s;
    for(i=0, j=0; i<2*n-1; i++){
        while(j>0&&a[i]!=s[j]) j=p[j-1];
        if(a[i]==s[j]){
            if(j==n-1){ sum++; j=p[j]; }
            else j++;
        }
    }
    //cout<<s<<" "<<sum<<endl;
    ans+=sum==k;
}

int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s; int t, i;
    cin>>t;
    for(i=0; i<t; i++){
        cin>>s;
        n+=s.length();
        v.push_back(s);
        q.push_back(i);
    }
    cin>>k;
    do{
        s="";
        for(i=0; i<t; i++) s+=v[q[i]];
        kmp(s);
    }while(next_permutation(q.begin(), q.end()));
    cout<<ans;
}