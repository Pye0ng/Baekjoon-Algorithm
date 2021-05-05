#include<stdio.h>

int s(int n){ return 3*n*n+3*n+1; }

int main(){
	int n;
	scanf("%d", &n);
	if(n==1){ printf("1"); return 0; }
	for(int i=0; i<n; i++){
		if(s(i)<n&&n<=s(i+1)){
			printf("%d", i+2);
			return 0;
		}
	} 
}
