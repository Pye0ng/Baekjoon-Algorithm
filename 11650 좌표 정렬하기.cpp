#include<stdio.h>
#include<algorithm>
using namespace std;
struct point{ int x, y; };
bool ch(point a, point b){
	if(a.x<b.x) return 1;
	if(a.x==b.x&&a.y<b.y) return 1;
	return 0;
}

int main(){
	int n, i;
	scanf("%d", &n);
	point arr[n+1];
	for(i=0; i<n; i++) scanf("%d %d", &arr[i].x, &arr[i].y);
	sort(arr, arr+n, ch);
	for(i=0; i<n; i++) printf("%d %d\n", arr[i].x, arr[i].y);
}
