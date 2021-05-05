#include<stdio.h>
int main(){int n,k;scanf("%d",&n);if(n==1||n==3)printf("-1");else{k=n/5;if((n-5*k)%2)printf("%d", k-1+(n-5*(k-1))/2);else printf("%d", k+(n-5*k)/2);}}
