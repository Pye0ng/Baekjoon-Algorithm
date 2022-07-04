#include<stdio.h>
#include<stack>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
stack<pll> s;
ll m, cnt, d[500500];

int main(){
	int n, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%lld", &d[i]);
	for(i=1; i<=n; i++){
		m=1;
		while(!s.empty()&&s.top().x<=d[i]){
			cnt+=s.top().y;
			m=s.top().x==d[i]?s.top().y+1:1;
			s.pop();
		}
		if(!s.empty()) cnt++;
		s.push(pll(d[i], m));
	}
	printf("%lld", cnt);
}
