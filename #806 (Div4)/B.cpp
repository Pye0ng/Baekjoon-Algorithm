#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    int n, t, i;
    scanf("%d", &t);
    while(t--){
        char c[52];
        int sum=0, d[30]={};
        scanf("%d", &n);
        scanf("%s", c);
        for(i=0; i<n; i++) d[c[i]-'A']++;
        for(i=0; i<26; i++) sum+=d[i]+(d[i]>0);
        printf("%d\n", sum);
    }
}