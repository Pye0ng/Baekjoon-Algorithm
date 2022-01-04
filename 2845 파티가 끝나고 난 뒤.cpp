#include<stdio.h>
int d[6];

int main(){
	int l, p, i;
	scanf("%d %d", &l, &p);
	for(i=0; i<5; i++){
		scanf("%d", &d[i]);
		d[i]-=l*p;
	}
	for(i=0; i<5; i++) printf("%d ", d[i]);
}
