#include<stdio.h>

int main(){
	long long int n, i=1;
	scanf("%lld", &n);
	while(1){
		if(i*(i+1)/2<=n&&n<(i+1)*(i+2)/2) break;
		i++;
	}
	printf("%lld", i);
}
