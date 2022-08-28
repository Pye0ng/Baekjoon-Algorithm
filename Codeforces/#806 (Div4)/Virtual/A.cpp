#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    char c[5];
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s", c);
        if((c[0]=='Y'||c[0]=='y')&&(c[1]=='E'||c[1]=='e')&&(c[2]=='S'||c[2]=='s')) printf("YES\n");
        else printf("NO\n");
    }
}