#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
vector<ll> v;

int main(){
	int n, i; ll t, s=0;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%lld", &t);
		v.push_back(t); s+=t;
	}
	sort(v.begin(), v.end()); t=0;
	for(i=0; i<n; i++){
		s-=v[i];
		t+=s*v[i];
	}
	printf("%lld", t);
}
