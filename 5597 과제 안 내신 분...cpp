#include<stdio.h>
int d[32];

int main(){
	int t, i;
	for(i=0; i<28; i++){
		scanf("%d", &t);
		d[t]=1;
	}
	for(i=1; i<=30; i++)
		if(!d[i]) printf("%d\n", i);
}
