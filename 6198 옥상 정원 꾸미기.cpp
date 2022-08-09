#include<stdio.h>
#include<stack>
using namespace std; 
long long int ans;
stack<int> s;

int main(){
	int n, t, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &t);
		while(!s.empty()&&s.top()<=t) s.pop();
		ans+=s.size(); s.push(t);
	}
	printf("%lld", ans);
}
