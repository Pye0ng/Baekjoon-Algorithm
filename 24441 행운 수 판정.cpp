#include<stdio.h>
#include<vector>
using namespace std;
vector<int> s(4000400);
int d[1000100];

int seg(int c, int a, int b){
    if(a==b) return s[c]=a%2;
    int m=a+b>>1;
    return s[c]=seg(c<<1, a, m)+seg(c<<1|1, m+1, b);
}

int find(int c, int a, int b, int t){
    if(a==b) return a;
    int m=a+b>>1;
    if(t<=s[c<<1]) return find(c<<1, a, m, t);
    else return find(c<<1|1, m+1, b, t-s[c<<1]);
}

void upd(int c, int a, int b, int i){
    if(i<a||i>b) return;
    s[c]--;
    if(a!=b){
        int m=a+b>>1;
        upd(c<<1, a, m, i);
        upd(c<<1|1, m+1, b, i);
    }
}

int main(){
    int t, n=1000000, k=0, now=2, cnt=n, i;
    seg(1, 1, n);
    while(k<=cnt){
        k=find(1, 1, n, now++);
        vector<int> v;
        for(i=k; i<=cnt; i+=k) v.push_back(find(1, 1, n, i));
        for(auto i:v){
            upd(1, 1, n, i);
            d[i]=1;
        }
        cnt-=v.size();
    }
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%s\n", d[n]||(n%2==0)?"unlucky":"lucky");
    }
}