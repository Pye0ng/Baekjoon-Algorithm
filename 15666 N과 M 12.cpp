#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int n, m;

void f(int t, int s, vector<int> p){
    if(t==m){
        for(auto i:p) printf("%d ", i);
        printf("\n");
        return;
    }
    for(int i=s; i<n; i++){
        vector<int> q=p;
        q.push_back(v[i]);
        f(t+1, i, q);
    }
}

int main(){
    int t, i;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++){
        scanf("%d", &t);
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    n=v.size(); vector<int> p;
    f(0, 0, p);
}