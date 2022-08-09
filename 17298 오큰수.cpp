#include<stdio.h>
#include<stack>
#define x first
#define y second
using namespace std;
int d[1000100], ans[1000100];
stack<int> s;

int main(){
    int n, i;
    scanf("%d", &n);
    for(i=1; i<=n; i++) scanf("%d", &d[i]);
    for(i=n; i; i--){
        while(!s.empty()&&s.top()<=d[i]) s.pop();
        ans[i]=s.empty()?-1:s.top();
        s.push(d[i]);
    }
    for(i=1; i<=n; i++) printf("%d ", ans[i]);
}