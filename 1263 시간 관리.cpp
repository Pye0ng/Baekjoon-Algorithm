#include<stdio.h>
#include<algorithm>
int n;

struct point{ int x, y; };
bool cmp(point a, point b){ return a.y<b.y; }

int main(){
	int i;
	point d[1010];
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d %d", &d[i].x, &d[i].y);
	std::sort(d, d+n, cmp);
	for(i=n-1; i>0; i--){
		int s=d[i].y-d[i].x;
		if(s<d[i-1].y) d[i-1].y=s;
		if(s==0){
			printf("-1");
			return 0;
		}
	}
	if(d[0].y<d[0].x) printf("-1");
	else printf("%d", d[0].y-d[0].x);
}
