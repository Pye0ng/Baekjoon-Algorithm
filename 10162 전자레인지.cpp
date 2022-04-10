#include<stdio.h>
int main(){
	int t, a, b, c;
	scanf("%d", &t);
	if(t%10) printf("-1");
	else{
		a=t/300; t-=a*300;
		b=t/60; t-=b*60;
		c=t/10;
		printf("%d %d %d", a, b, c);
	}
}
