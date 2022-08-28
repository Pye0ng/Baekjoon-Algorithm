#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
vector<pii> ans;
int c;

void sum(int n, int t){
    if(c||n==0){ c=1; return; }
    if(n%3==0){
        sum(n/3, t+1);
        return;
    }
    int s=int(floor(log2(n)));
    if((n-(1<<s))%3==0){
        ans.push_back(pii(s, t));
        sum(n-(1<<s), t);
    }
    else{
        ans.push_back(pii(--s, t));
        sum(n-(1<<s), t);
    }
}

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        c=0; sum(n, 0);
        printf("%d\n", ans.size());
        for(auto i:ans) printf("%d %d\n", i.first, i.second);
        ans.clear();
    }
}