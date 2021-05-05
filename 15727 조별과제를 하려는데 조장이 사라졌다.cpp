#include<stdio.h>

int main(){
	int d;
	scanf("%d", &d);
	if(d%5) printf("%d", d/5+1);
	else printf("%d", d/5);	
}
