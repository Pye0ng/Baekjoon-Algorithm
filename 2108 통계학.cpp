#include<stdio.h>
#include<algorithm>
using namespace std;
int sum;
struct point{ int x, y; }; 
point p[8001];

bool cmp(point a, point b){
	if(a.y>b.y) return 1;
	else if(a.y==b.y&&a.x<b.x) return 1;
	else return 0;
}

int main(){
	int n, i;
	scanf("%d", &n);
	int a[n+1]={};
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
		sum+=a[i];
		p[a[i]+4000].y++;
	}
	for(i=0; i<=8000; i++) p[i].x=i;
	sort(p, p+8001, cmp);
	sort(a, a+n);
	if(p[0].y!=p[1].y) printf("%.lf\n%d\n%d\n%d", (double)sum/n, a[n/2], p[0].x-4000, a[n-1]-a[0]);
	else printf("%.lf\n%d\n%d\n%d", (double)sum/n, a[n/2], p[1].x-4000, a[n-1]-a[0]);
}
