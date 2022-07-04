#include<stdio.h>
#include<vector>
using namespace std;
vector<char> aa, bb;
char a[100100], b[100100];
int ans, ca[30], cb[30];

bool in(char c){ return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'; }

int main(){
    int n, i;
    scanf("%d", &n);
    scanf("%s", a);
    scanf("%s", b);
    for(i=0; i<n; i++){
        ca[a[i]-'a']++;
        cb[b[i]-'a']++;
        if(!in(a[i])) aa.push_back(a[i]);
        if(!in(b[i])) bb.push_back(b[i]);
    }
    ans=(a[0]!=b[0])||(a[n-1]!=b[n-1])||(aa.size()!=bb.size());
    for(i=0; i<26; i++) ans|=(ca[i]!=cb[i]);
    if(aa.size()==bb.size())
        for(i=0; i<aa.size(); i++) ans|=(aa[i]!=bb[i]);
    printf("%s", ans?"NO":"YES");
}