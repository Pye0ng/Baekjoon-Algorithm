#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ans;
int d[12][27]={
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

void find(int cnt[], vector<int> v){
    if(ans.size()>0) return;
    int ch=1, i, j;
    for(i=0; i<26; i++)
        if(cnt[i]!=0) ch=0;
    if(ch){ ans=v; return; }
    for(i=0; i<=9; i++){
        ch=0; int ccnt[30];
        for(j=0; j<26; j++) ch|=cnt[j]<d[i][j];
        if(ch) continue;
        for(j=0; j<26; j++) ccnt[j]=cnt[j]-d[i][j];
        vector<int> vv=v;
        vv.push_back(i);
        find(ccnt, vv);
    }
}

int main(){
    int t, i, j;
    scanf("%d", &t);
    for(i=1; i<=t; i++){
        char c[2020]; int cnt[30]={};
        vector<int> v; ans=v;
        scanf("%s", c);
        for(j=0; c[j]!='\0'; j++) cnt[c[j]-'A']++;
        find(cnt, v);
        sort(ans.begin(), ans.end());
        printf("Case #%d: ", i);
        for(auto p:ans) printf("%d", p);
        printf("\n");
    }
}