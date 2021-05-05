#include<stdio.h>
int s[1001];

int main(){
	int n, max=0, i;
	double sc=0;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &s[i]);
		sc+=s[i];
		if(s[i]>max) max=s[i];
	}
	sc=sc/max*100/n;
	printf("%lf", sc);
} 
