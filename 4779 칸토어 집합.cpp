#include<stdio.h>
#include<math.h>

void c(int n){
	if(n==1){
		printf("- -");
		return;
	}
	c(n-1);
	for(int i=1; i<=pow(3, n-1); i++) printf(" ");
	c(n-1);
}

int main(){
	int n, i;
	while(scanf("%d", &n)!=EOF){
		if(n==0) printf("-\n");
		else if(n==1) printf("- -\n");
		else{
			c(n-1);
			for(i=1; i<=pow(3, n-1); i++) printf(" ");
			c(n-1);
			printf("\n");
		}
	}
}
