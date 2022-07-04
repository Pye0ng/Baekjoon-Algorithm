#include<stdio.h>
#include<vector>
#include<algorithm> 
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
vector<pii> v;

int main(){
	int n, a, b, ans=0, i;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d %d", &a, &b);
		v.push_back(pii(a, b));
	}
	sort(v.begin(), v.end());
	a=b=-1e9;
	for(i=0; i<n; i++){
		pii p=v[i];
		if(p.x>b){
			ans+=p.y-p.x;
			a=p.x; b=p.y;
		}
		else if(p.y>b){
			ans+=p.y-b;
			b=p.y;
		}
	}
	printf("%d", ans);
}
