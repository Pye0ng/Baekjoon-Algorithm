#include<stdio.h>
int p[6], k;

void c(int n){
	k=1;
	while(n>0){
		p[k++]=n%10;
		n/=10;
	}
}

bool pl(int n){
	c(n);
	for(int i=1; i<=k/2; i++) if(p[i]!=p[k-i]) return 1;
	return 0;
}

int main(){
	int n=1;
	while(1){
		scanf("%d", &n);
		if(!n) break;
		if(pl(n)) printf("no\n");
		else printf("yes\n");
	}
}
