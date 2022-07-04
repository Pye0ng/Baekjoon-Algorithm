#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
vector<pii> v;
int sum, d[500100];

bool cmp(pii a, pii b){
	if(a.x==b.x) return a.y<b.y;
	return a.x>b.x;
}

int main(){
	int n, i;
	scanf("%d", &n);
	v.resize(8001, {0, 0});
	for(i=0; i<n; i++){
		scanf("%d", &d[i]);
		sum+=d[i]; v[d[i]+4000].x++;
	}
	for(i=0; i<=8000; i++) v[i].y=i;
	sort(v.begin(), v.end(), cmp);
	sort(d, d+n);
	if(n>1) printf("%.lf\n%d\n%d\n%d", (double)sum/n<0.5&&-0.5<=(double)sum/n?0:(double)sum/n, d[n/2], v[0].x==v[1].x?v[1].y-4000:v[0].y-4000, d[n-1]-d[0]);
	else printf("%d\n%d\n%d\n0", d[0], d[0], d[0]);
}
