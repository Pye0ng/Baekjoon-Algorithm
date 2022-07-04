#include<stdio.h>
#include<algorithm>
#include<stack>
using namespace std;
typedef long long int ll;
struct point{ ll x, y, p, q; };
point t[100100];
stack<int> s;

bool cmp(point a, point b){
	if(a.q*b.p!=a.p*b.q) return a.q*b.p<a.p*b.q;
	if(a.y!=b.y) return a.y<b.y;
	return a.x<b.x;
}

ll ccw(point a, point b, point c){ return a.x*b.y+b.x*c.y+c.x*a.y-a.y*b.x-b.y*c.x-c.y*a.x; }

int main(){
	int n, nx=2, i;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		ll a, b;
		scanf("%lld %lld", &a, &b);
		t[i].x=a; t[i].y=b;
	}
	sort(t, t+n, cmp);
	for(i=1; i<n; i++){
		t[i].p=t[i].x-t[0].x;
		t[i].q=t[i].y-t[0].y;
	}
	sort(t+1, t+n, cmp);
	s.push(0); s.push(1);
	while(nx<n){
		while(s.size()>1){
			int a, b;
			b=s.top(); s.pop(); a=s.top();
			if(ccw(t[a], t[b], t[nx])>0){
				s.push(b);
				break;
			}
		}
		s.push(nx++);
	}
	printf("%d", s.size());
}
