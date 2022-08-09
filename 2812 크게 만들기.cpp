#include<stdio.h>
#include<queue>
#include<stack>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
stack<pii> s;
queue<int> ans;
char c[500500];
int d[500500];

int main(){
    int n, k, p=0, i;
    scanf("%d %d", &n, &k);
    scanf("%s", c);
    for(i=0; i<n&&p<k; i++){
        while(!s.empty()&&s.top().x<c[i]-'0'){
            d[s.top().y]=1; s.pop();
            if(++p==k) break;
        }
        if(p<k) s.push(pii(c[i]-'0', i));
    }
    for(i=0; i<n; i++)
        if(!d[i]) ans.push(c[i]-'0');
    for(i=0; i<n-k; i++){
        printf("%d", ans.front());
        ans.pop();
    }
}