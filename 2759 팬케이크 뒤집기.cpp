#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

bool check1(vector<int> v){
    int ch=1, i;
    for(i=1; i<v.size(); i++) ch&=(v[i]==v[i-1]-1);
    return !ch;
}

bool check2(vector<int> v){
    int ch=1, i;
    for(i=1; i<v.size(); i++) ch&=(v[i]==v[i-1]+1);
    return !ch;
}

vector<int> solve1(int n, vector<int> v){
    int p=1;
    vector<int> ans;
    while(check1(v)){
        auto t=find(v.begin(), v.end(), p);
        if(t==v.begin()){
            reverse(v.begin(), v.end()-p+1);
            ans.push_back(n-p+1); p++;
        }
        else if(t==v.end()-1) p++;
        else{
            ans.push_back(t-v.begin()+1);
            reverse(v.begin(), t+1);
        }
    }
    ans.push_back(n);
    return ans;
}

vector<int> solve2(int n, vector<int> v){
    int p=n;
    vector<int> ans;
    while(check2(v)){
        auto t=find(v.begin(), v.end(), p);
        if(t==v.begin()){
            reverse(v.begin(), v.end()+p-n);
            ans.push_back(p--);
        }
        else if(t==v.end()-1) p--;
        else{
            ans.push_back(t-v.begin()+1);
            reverse(v.begin(), t+1);
        }
    }
    return ans;
}

int main(){
    int t, n, p, ch, i;
    scanf("%d", &t);
    while(t--){
        vector<int> v, ans;
        scanf("%d", &n);
        for(i=0; i<n; i++){
            scanf("%d", &p);
            v.push_back(p);
        }
        p=1; ch=1;
        for(i=1; i<n; i++) ch&=(v[i]==v[i-1]+1);
        if(ch) printf("0");
        else{
            vector<int> ans1=solve1(n, v), ans2=solve2(n, v);
            ans=ans1.size()<ans2.size()?ans1:ans2;
            printf("%d ", ans.size());
            for(auto i:ans) printf("%d ", i);
        }
        printf("\n");
    }
}