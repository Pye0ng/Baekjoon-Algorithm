#include<stdio.h>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> p;

int ccw(p a, p b, p c){
	ll t=a.x*b.y+b.x*c.y+c.x*a.y-a.y*b.x-b.y*c.x-c.y*a.x;
	if(t>0) return 1; //ccw
	else if(t<0) return -1; //cw
	else return 0; //parallel 
}

int dis(p a, p b, p c, p d){
	int m=ccw(c, d, a)*ccw(c, d, b), n=ccw(a, b, c)*ccw(a, b, d);
	if(m==0&&n==0){
		if(a>b) swap(a, b);
		if(c>d) swap(c, d);
		return c<=b&&a<=d;
	}
	return m<=0&&n<=0;
}

int main(){
	p a, b, c, d;
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y);
	printf("%d", dis(a, b, c, d));
} 
