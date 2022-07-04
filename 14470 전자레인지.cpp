#include<stdio.h>

int main(){
	int a, b, c, d, e, s=0;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	if(a<0) s-=a*c;
	if(a<=0) s+=d;
	if(a>0) s+=e*(b-a);
	else s+=e*b;
	printf("%d", s);
}
