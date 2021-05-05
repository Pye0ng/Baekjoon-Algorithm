#include<stdio.h>
#include<algorithm>
struct p{ int x, y; };
p c[8];

bool cmp(p a, p b){
	if(a.y>b.y) return 1;
	else return 0;
}

int main(){
	int i, sum=0, p[5];
	for(i=0; i<8; i++){
		c[i].x=i+1;
		scanf("%d", &c[i].y);
	}
	std::sort(c, c+8, cmp);
	for(i=0; i<5; i++){
		sum+=c[i].y;	
		p[i]=c[i].x;
	}
	std::sort(p, p+5);
	printf("%d\n", sum);
	for(i=0; i<5; i++) printf("%d ", p[i]);
}
