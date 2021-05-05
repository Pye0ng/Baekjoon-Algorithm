#include<stdio.h>
#include<algorithm>
int n, k;

struct point{ int x, y; };

int f(int s){
	int cnt=0;
	while(s>0){
		cnt++;
		s/=10;
	}
	return cnt;
}

bool cmp(point a, point b){
	if(a.y>b.y) return 1;
	else if(a.y==b.y){
		if(a.x>=b.x) return 1;
		else return 0;
	}
	return 0;
}

int main(){
	int i;
	point d[1010];
	scanf("%d %d", &k, &n);
	for(i=0; i<k; i++){
		scanf("%d", &d[i].x);
		d[i].y=f(d[i].x);
	}
	std::sort(d, d+k, cmp);
	for(i=0; i<n-k; i++) printf("%d", d[0].x);
	for(i=0; i<k; i++) printf("%d", d[i].x);
}
