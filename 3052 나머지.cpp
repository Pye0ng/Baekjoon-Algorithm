#include<stdio.h>
int a[11], b[43];

int main(){
	int n, i, dif=10;
	for(i=0; i<10; i++){
		scanf("%d", &n);
		a[i]=n%42;
		b[a[i]]++;
	}	
	for(i=0; i<42; i++){
		if(b[i]) dif-=b[i]-1;
	}
	printf("%d", dif);
}
