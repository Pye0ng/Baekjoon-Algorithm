#include<stdio.h>

int main(){
	int w, h, x, y, min;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	min=y>h-y?h-y:y;
	if(w-x<min) min=w-x;
	if(x<min) min=x;
	printf("%d", min);
}
