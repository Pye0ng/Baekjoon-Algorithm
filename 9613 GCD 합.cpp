#include<stdio.h>

int gcd(int a, int b){
	int n;
	if(a>=b){
		while(b!=0){ n=a%b; a=b; b=n; } 
		return a; 
	}
	else{
		while(a!=0){ n=b%a; b=a; a=n; } 
		return b; 
	}
}

int main(){
	int a[101];
	int n, p, i, j, k;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		long long int sum=0;
		scanf("%d", &p);
		for(j=0; j<p; j++) scanf("%d", &a[j]);
		for(j=0; j<p-1; j++)
			for(k=j+1; k<p; k++) sum+=gcd(a[j], a[k]);
		printf("%lld\n", sum);
	}
}
