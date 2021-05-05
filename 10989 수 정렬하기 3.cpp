#include<stdio.h>
int arr[10001];

int main(){
	int n, k, i;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &k);
		arr[k]++;	
	} 
	for(i=1; i<=10000; i++){
		for(k=1; k<=arr[i]; k++) printf("%d\n", i);
	}
}
