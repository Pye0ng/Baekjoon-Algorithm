#include<stdio.h>

int decomp(int n){
	int sum=0;
	while(n>0){
		sum+=n%10;
		n/=10;
	}
	return sum;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		if(decomp(i)+i==n){
			printf("%d", i);
			return 0;
		}
	}
	printf("0");
}
