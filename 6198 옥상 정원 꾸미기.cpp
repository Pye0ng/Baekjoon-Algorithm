#include<stdio.h>
#include<stack>
using namespace std; 
stack<int> s;
int n, d[80010];
long long int ans;

int main(){
	int i;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	for(i=1; i<=n; i++){
		while(!s.empty()&&s.top()<=d[i]) s.pop();
		s.push(d[i]);
		ans+=s.size()-1;
	}
	printf("%lld", ans);
}
