#include<stdio.h>
int n, m, s, c;
int main(){
	scanf("%d", &n);
	while(n--){
		scanf("%d", &s);
		if(s==m){ c++; m=(m+1)%3; }
	}
	printf("%d", c);
} 
