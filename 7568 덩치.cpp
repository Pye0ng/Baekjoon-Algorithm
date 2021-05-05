#include<stdio.h>
int h[51], w[51], c[51];

int main(){
	int n, i, j;
	scanf("%d", &n); 
	for(i=0; i<n; i++){
		scanf("%d %d", &w[i], &h[i]);	
		c[i]=1;
	}
	for(i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			if(w[i]>w[j]&&h[i]>h[j]) c[j]++;
			else if(w[i]<w[j]&&h[i]<h[j]) c[i]++;
		}
	}
	for(i=0; i<n; i++) printf("%d ", c[i]);
}
