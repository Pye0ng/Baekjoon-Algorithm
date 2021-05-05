#include<stdio.h>
int n, k, d[2001];
 
int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &k);
		d[k+1000]++;
	}
	for(int i=0; i<=2000; i++)
		if(d[i]>0) printf("%d ", i-1000);
}
