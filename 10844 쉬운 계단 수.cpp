#include<stdio.h>
#define M 1000000000
int n, k, i, d[10];

int main(){
	for(i=1; i<=9; i++) d[i]=1;
	scanf("%d", &n);
	while(--n){
		int t[10]={};
		t[1]+=d[0]; t[8]+=d[9];
		for(i=1; i<9; i++){
			t[i-1]=(t[i-1]+d[i])%M;
			t[i+1]=(t[i+1]+d[i])%M;
		}
		for(i=0; i<=9; i++) d[i]=t[i];
	}
	for(i=0; i<=9; i++) k=(k+d[i])%M;
	printf("%d", k); 
}
