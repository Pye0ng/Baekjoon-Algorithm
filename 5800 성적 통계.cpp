#include<stdio.h>
#include<algorithm>

int abs(int a, int b){ return a>=b?a-b:b-a; }

int main(){
	int n, k, i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		int g=0;
		int arr[51];
		scanf("%d", &k);
		for(j=0; j<k; j++) scanf("%d", &arr[j]);
		std::sort(arr, arr+k);
		for(j=0; j<k-1; j++)
			if(abs(arr[j], arr[j+1])>g) g=abs(arr[j], arr[j+1]);
		printf("Class %d\nMax %d, Min %d, Largest gap %d\n", i, arr[k-1], arr[0], g);
	}
}
