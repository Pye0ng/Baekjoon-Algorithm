#include<stdio.h>
int n, sum2, sum5;

void find2(int k){
	while(k%2==0){
		k/=2;
		sum2++;
	}
}

void find5(int k){
	while(k%5==0){
		k/=5;
		sum5++;
	}
}

int main(){
	int i;
	scanf("%d", &n);
	for(i=2; i<=n; i++){
		find2(i);
		find5(i);
	}
	printf("%d", (sum2<sum5)?sum2:sum5);
}
