#include<stdio.h>
int d, h, t, a;

int main(){
	int n, i;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &d);
		if(d>h){ h=d; t=0; }
		else t++;
		if(t>a) a=t;
	}
	printf("%d", a);
}
